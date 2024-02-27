#ifndef MODELS_H
#define MODELS_H
// тут объявлены все модели данных, которыми пользуемся для парсера
typedef enum type_of_record {
  null,
  vertex,
  facet,
} type_of_record;

// все калькулированные данные из файла
typedef struct File_data {
  unsigned int vertex_count;
  unsigned int facets_count;
  unsigned int vertices_in_face;
  // количество вершин в грани, чтобы было удобно обходить, потому что может
  // быть и 3 и 4 вершины
  unsigned int indices_cols;
  unsigned int indices_len;
  double max_coef;
} File_data;

typedef struct {
  double* vertices;  // координаты вершин
  unsigned int* indices;
} Data_array;

#endif  // MODELS_H
