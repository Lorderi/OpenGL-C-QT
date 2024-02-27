#include "parser.h"

#include <ctype.h>
#include <float.h>
#include <locale.h>

bool obj_parser(File_data* file_information, Data_array* data_array,
                const char* file_name) {
  setlocale(LC_ALL, "C");
  bool error_flag = false;
  set_init_data(file_information);
  FILE* file = fopen(file_name, "r");
  if (file != NULL) {
    error_flag = get_information_from_file(file_information, data_array, file);
    file_information->max_coef *= 1.5;
    fclose(file);
  } else {
    fprintf(stderr, "Error while opening file: %s\n", file_name);
  }
  return error_flag;
}

// устанавливаем начальные значения
void set_init_data(File_data* file_information) {
  memset(file_information, 0, sizeof(File_data));
}

bool empty_data_array(Data_array* data_array) {
  return (data_array->vertices == NULL || data_array->indices == NULL);
}

bool get_information_from_file(File_data* file_information,
                               Data_array* data_array, FILE* file) {
  bool error_flag = false;
  char buffer[STR_SIZE] = {0};
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    //считаем все, что можно посчитать в файле
    calc_data_params(file_information,
                     get_type_of_record(buffer, file_information));
  }
  //объявил массивы структур
  file_information->indices_len =
      file_information->indices_cols * file_information->facets_count;

  // выделяю память для массивов структур 
  error_flag = allocate_memory_for_models(data_array, file_information);
  if (!error_flag && empty_data_array(data_array))
    error_flag = true;
  else if (!error_flag)
    parse_file(data_array, file_information, file);

  return error_flag;
}

double* get_double_item(double* item, int row, int col) {
  return &item[row * XYZ_LEN + col];
}
unsigned int* get_int_item(unsigned int* item, int range_col, int row,
                           int col) {
  return &item[row * range_col + col];
}

void update_max_coordinate(double* max, double new_coordinate) {
  if (new_coordinate > *max) *max = new_coordinate;
}

void update_max_coef(double* vertices, File_data* file_information,
                     unsigned int vertices_recorded) {
  //  0 - x_pos, 1 - y_pos, 2 - z_pos
  for (size_t i = 0; i < 3; i++) {
    update_max_coordinate(&file_information->max_coef,
                          *get_double_item(vertices, vertices_recorded, i));
  }
}

// парсим файл и записываем все нужные данные в массивы структур
void parse_file(Data_array* data_array, File_data* file_information,
                FILE* file) {
  char buffer[STR_SIZE] = {0};

  fseek(file, 0, SEEK_SET);
  unsigned int vertices_recorded = 0;
  unsigned int facets_recorded = 0;

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    // если вершина
    double x, y, z;
    if (sscanf(buffer, "v %lf %lf %lf", &x, &y, &z) == 3) {
      *get_double_item(data_array->vertices, vertices_recorded, x_pos) = x;
      *get_double_item(data_array->vertices, vertices_recorded, y_pos) = y;
      *get_double_item(data_array->vertices, vertices_recorded, z_pos) = z;
      update_max_coef(data_array->vertices, file_information,
                      vertices_recorded);
      vertices_recorded++;
      // если текстурная координата
    } else if (buffer[0] == 'f') {
      // если грань
      parse_face_string(buffer, data_array->indices, file_information,
                        facets_recorded);
      facets_recorded++;
    }
  }
}

void init_indice_array(unsigned int* indices, File_data* file_information,
                       unsigned int* const indice_array,
                       unsigned int facets_recorded) {
  // удвоение: f 5 1 4 = 5, 1, 1, 4, 4, 5
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int first_element;
  if (indice_array)
    first_element = indice_array[i++];
  else {
    fprintf(stderr, "Error in init_indice_array\n");
    if (indices) free(indices);
    exit(1);
  }
  *get_int_item(indices, file_information->indices_cols, facets_recorded, j++) =
      first_element;
  for (; i < file_information->vertices_in_face; i++) {
    for (int k = 0; k < 2; k++) {
      *get_int_item(indices, file_information->indices_cols, facets_recorded,
                    j++) = indice_array[i];
    }
  }
  *get_int_item(indices, file_information->indices_cols, facets_recorded, j) =
      first_element;
}

// чтобы сохранять в массив грани
void parse_face_string(const char* faceStr, unsigned int* indices,
                       File_data* file_information,
                       unsigned int facets_recorded) {
  bool error_flag = false;
  char* copy = NULL;
  if (faceStr) {
    copy = (char*)malloc(strlen(faceStr) + 1);
    if (copy) {
      strcpy(copy, faceStr);
    } else {
      error_flag = true;
    }
  } else {
    error_flag = true;
  }
  char* token = strtok(copy, " ");

  unsigned int* indice_array = NULL;
  int count = 0;
  while (token != NULL) {
    if (isdigit(token[0])) {
      int number = atoi(token);
      if (indice_array == NULL) {
        indice_array = (unsigned int*)malloc((count + 1) * sizeof(int));
      } else {
        unsigned int* new_array =
            (unsigned int*)realloc(indice_array, (count + 1) * sizeof(int));
        if (new_array) {
          indice_array = new_array;
        } else {
          error_flag = true;
        }
      }
      if (indice_array) {
        indice_array[count] = number - 1;
        count++;
      } else {
        error_flag = true;
      }
      if (error_flag) {
        fprintf(stderr, "Error alloc in parse_face_string\n");
        if (indice_array) free(indice_array);
        if (copy) free(copy);
        exit(1);
      }
    }
    token = strtok(NULL, " ");
  }
  init_indice_array(indices, file_information, indice_array, facets_recorded);
  free(indice_array);
  free(copy);
}

bool allocate_memory_for_models(Data_array* data_array,
                                File_data* file_information) {
  bool error_flag = false;
  if (data_array->vertices)
    data_array->vertices =
        (double*)realloc(data_array->vertices, file_information->vertex_count *
                                                   XYZ_LEN * sizeof(double));
  else
    data_array->vertices = (double*)calloc(
        file_information->vertex_count * XYZ_LEN, sizeof(double));
  if (data_array->indices)
    data_array->indices = (unsigned int*)realloc(
        data_array->indices,
        file_information->indices_len * sizeof(unsigned int));
  else
    data_array->indices = (unsigned int*)calloc(file_information->indices_len,
                                                sizeof(unsigned int));
  if (empty_data_array(data_array)) {
    error_flag = true;
  }
  return error_flag;
}

void free_memory(Data_array* data_array) {
  if (data_array->vertices) {
    free(data_array->vertices);
    data_array->vertices = NULL;
  }
  if (data_array->indices) {
    free(data_array->indices);
    data_array->indices = NULL;
  }
}

unsigned int calc_vertices_in_face() {
  unsigned int count_vertices = 0;
  // чтобы пропустить первый токен, который уже взял в прошлой функции
  char* token = strtok(NULL, " ");
  while (token != NULL) {
    count_vertices++;
    token = strtok(NULL, " ");
  }
  return count_vertices;
}

// получаем тип записи
type_of_record get_type_of_record(char* buffer, File_data* file_information) {
  type_of_record record_type = null;
  const char* delimeter = " ";
  const char* token = strtok(buffer, delimeter);
  if (strcmp(token, "v") == 0) {
    record_type = vertex;
  } else if (strcmp(token, "f") == 0) {
    record_type = facet;
    if (file_information->vertices_in_face == 0) {
      //тут считаем сколько у нас вершин в ребре
      file_information->vertices_in_face = calc_vertices_in_face();
      file_information->indices_cols =
          file_information->vertices_in_face * INDX_LEN;
      // так хранится массив индексов
    }
  }
  return record_type;
}

// считаем сколько у нас соответствующих записей
void calc_data_params(File_data* file_information, type_of_record record_type) {
  if (record_type == vertex)
    file_information->vertex_count++;
  else if (record_type == facet)
    file_information->facets_count++;
}
