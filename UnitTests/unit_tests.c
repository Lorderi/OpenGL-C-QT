#include <check.h>
#include <unistd.h>

#include "afin.h"
#include "parser.h"
#define EPS 1e-06

START_TEST(test_file_data_equivalence_1) {
  File_data file_data1, file_data2;
  file_data1.vertex_count = 8;
  file_data1.facets_count = 6;
  file_data1.vertices_in_face = 4;
  file_data1.indices_cols = 8;
  file_data1.indices_len = 48;
  file_data1.max_coef = 1.5;

  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};

  obj_parser(&file_data2, &data_array, filename);
  ck_assert_int_eq(file_data2.vertex_count, file_data1.vertex_count);
  ck_assert_int_eq(file_data2.facets_count, file_data1.facets_count);
  ck_assert_int_eq(file_data2.vertices_in_face, file_data1.vertices_in_face);
  ck_assert_int_eq(file_data2.indices_cols, file_data1.indices_cols);
  ck_assert_int_eq(file_data2.indices_len, file_data1.indices_len);
  ck_assert_double_eq(file_data2.max_coef, file_data1.max_coef);
  free_memory(&data_array);
}
END_TEST

START_TEST(test_file_data_equivalence_2) {
  File_data file_data1, file_data2;
  file_data1.vertex_count = 64656;
  file_data1.facets_count = 194035;
  file_data1.vertices_in_face = 2;
  file_data1.indices_cols = 4;
  file_data1.indices_len = 776140;
  file_data1.max_coef = 9.961299;

  const char *filename = "obj/dragon.obj";
  Data_array data_array = {0};

  obj_parser(&file_data2, &data_array, filename);
  ck_assert_int_eq(file_data2.vertex_count, file_data1.vertex_count);
  ck_assert_int_eq(file_data2.facets_count, file_data1.facets_count);
  ck_assert_int_eq(file_data2.vertices_in_face, file_data1.vertices_in_face);
  ck_assert_int_eq(file_data2.indices_cols, file_data1.indices_cols);
  ck_assert_int_eq(file_data2.indices_len, file_data1.indices_len);
  ck_assert_double_eq(file_data2.max_coef, file_data1.max_coef);
  free_memory(&data_array);
}
END_TEST

START_TEST(test_failed_path_name) {
  File_data file_data1;
  const char *filename = "dragon1.obj";
  Data_array data_array = {0};

  ck_assert_int_eq(0, obj_parser(&file_data1, &data_array, filename));
  free_memory(&data_array);
}
END_TEST

START_TEST(test_vertices_equivalence) {
  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array1 = {0}, data_array2 = {0};

  obj_parser(&file_data, &data_array2, filename);
  double vertices[] = {1.000000,  1.000000,  -1.000000, 1.000000,  -1.000000,
                       -1.000000, 1.000000,  1.000000,  1.000000,  1.000000,
                       -1.000000, 1.000000,  -1.000000, 1.000000,  -1.000000,
                       -1.000000, -1.000000, -1.000000, -1.000000, 1.000000,
                       1.000000,  -1.000000, -1.000000, 1.000000};
  data_array1.vertices = vertices;
  for (int i = 0; i < 24; i++) {
    ck_assert(data_array1.vertices[i] == data_array2.vertices[i]);
  }
  free_memory(&data_array2);
}
END_TEST

START_TEST(test_indices_equivalence) {
  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array1 = {0}, data_array2 = {0};
  memset(&data_array1, 0, sizeof(Data_array));
  memset(&data_array2, 0, sizeof(Data_array));
  obj_parser(&file_data, &data_array2, filename);
  unsigned int indices[] = {1, 5, 5, 7, 7, 3, 3, 1, 4, 3, 3, 7, 7, 8, 8, 4, 8,
                            7, 7, 5, 5, 6, 6, 8, 6, 2, 2, 4, 4, 8, 8, 6, 2, 1,
                            1, 3, 3, 4, 4, 2, 6, 5, 5, 1, 1, 2, 2, 6, 1, 1};
  data_array1.indices = indices;
  for (int i = 0; i < 24; i++) {
    ck_assert(data_array1.indices[i] - 1 == data_array2.indices[i]);
  }
  free_memory(&data_array2);
}
END_TEST

START_TEST(test_indices_realloc) {
  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};
  obj_parser(&file_data, &data_array, filename);

  const char *filename2 = "obj/dragon.obj";

  obj_parser(&file_data, &data_array, filename2);
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_1) {
  double vertices_result[] = {
      1.005000,  1.000000, -1.000000, 1.005000,  -1.000000, -1.000000,
      1.005000,  1.000000, 1.000000,  1.005000,  -1.000000, 1.000000,
      -0.995000, 1.000000, -1.000000, -0.995000, -1.000000, -1.000000,
      -0.995000, 1.000000, 1.000000,  -0.995000, -1.000000, 1.000000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};

  obj_parser(&file_data, &data_array, filename);

  double value = 0.005;
  move_coordinate(&data_array, file_data.vertex_count, value, 'x');
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_2) {
  double vertices_result[] = {
      1.000000,  1.005000, -1.000000, 1.000000,  -0.995000, -1.000000,
      1.000000,  1.005000, 1.000000,  1.000000,  -0.995000, 1.000000,
      -1.000000, 1.005000, -1.000000, -1.000000, -0.995000, -1.000000,
      -1.000000, 1.005000, 1.000000,  -1.000000, -0.995000, 1.000000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};

  obj_parser(&file_data, &data_array, filename);

  double value = 0.005;
  move_coordinate(&data_array, file_data.vertex_count, value, 'y');
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_3) {
  double vertices_result[] = {
      1.000000,  1.000000, -0.995000, 1.000000,  -1.000000, -0.995000,
      1.000000,  1.000000, 1.005000,  1.000000,  -1.000000, 1.005000,
      -1.000000, 1.000000, -0.995000, -1.000000, -1.000000, -0.995000,
      -1.000000, 1.000000, 1.005000,  -1.000000, -1.000000, 1.005000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};

  obj_parser(&file_data, &data_array, filename);

  double value = 0.005;
  move_coordinate(&data_array, file_data.vertex_count, value, 'z');
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_4) {
  double vertices_result[] = {
      1.000000,  1.000000, -0.500000, 1.000000,  -1.000000, -0.500000,
      1.000000,  1.000000, 0.500000,  1.000000,  -1.000000, 0.500000,
      -1.000000, 1.000000, -0.500000, -1.000000, -1.000000, -0.500000,
      -1.000000, 1.000000, 0.500000,  -1.000000, -1.000000, 0.500000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};

  obj_parser(&file_data, &data_array, filename);

  double value = 0.5;
  scale_coordinate(&data_array, file_data.vertex_count, value, 'z');
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_5) {
  double vertices_result[] = {
      1.000000,  0.500000, -1.000000, 1.000000,  -0.500000, -1.000000,
      1.000000,  0.500000, 1.000000,  1.000000,  -0.500000, 1.000000,
      -1.000000, 0.500000, -1.000000, -1.000000, -0.500000, -1.000000,
      -1.000000, 0.500000, 1.000000,  -1.000000, -0.500000, 1.000000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};

  obj_parser(&file_data, &data_array, filename);

  double value = 0.5;
  scale_coordinate(&data_array, file_data.vertex_count, value, 'y');
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_6) {
  double vertices_result[] = {
      0.500000,  1.000000, -1.000000, 0.500000,  -1.000000, -1.000000,
      0.500000,  1.000000, 1.000000,  0.500000,  -1.000000, 1.000000,
      -0.500000, 1.000000, -1.000000, -0.500000, -1.000000, -1.000000,
      -0.500000, 1.000000, 1.000000,  -0.500000, -1.000000, 1.000000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};
  obj_parser(&file_data, &data_array, filename);

  double value = 0.5;
  scale_coordinate(&data_array, file_data.vertex_count, value, 'x');
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_7) {
  double vertices_result[] = {
      0.500000,  0.500000, -0.500000, 0.500000,  -0.500000, -0.500000,
      0.500000,  0.500000, 0.500000,  0.500000,  -0.500000, 0.500000,
      -0.500000, 0.500000, -0.500000, -0.500000, -0.500000, -0.500000,
      -0.500000, 0.500000, 0.500000,  -0.500000, -0.500000, 0.500000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};
  obj_parser(&file_data, &data_array, filename);

  double value = 0.5;
  scale_all_coordinate(&data_array, file_data.vertex_count, value);
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_8) {
  double vertices_result[] = {
      1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000, 1.000000,
      1.000000,  1.000000,  -1.000000, 1.000000,  1.000000,  1.000000,
      -1.000000, -1.000000, -1.000000, -1.000000, -1.000000, 1.000000,
      -1.000000, 1.000000,  -1.000000, -1.000000, 1.000000,  1.000000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};
  obj_parser(&file_data, &data_array, filename);

  double value = 90;
  rotate_x(&data_array, file_data.vertex_count, value);
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_9) {
  double vertices_result[] = {
      -1.000000, 1.000000, -1.000000, -1.000000, -1.000000, -1.000000,
      1.000000,  1.000000, -1.000000, 1.000000,  -1.000000, -1.000000,
      -1.000000, 1.000000, 1.000000,  -1.000000, -1.000000, 1.000000,
      1.000000,  1.000000, 1.000000,  1.000000,  -1.000000, 1.000000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};
  obj_parser(&file_data, &data_array, filename);

  double value = 90;
  rotate_y(&data_array, file_data.vertex_count, value);
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

START_TEST(test_afins_transformation_10) {
  double vertices_result[] = {
      1.000000, -1.000000, -1.000000, -1.000000, -1.000000, -1.000000,
      1.000000, -1.000000, 1.000000,  -1.000000, -1.000000, 1.000000,
      1.000000, 1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
      1.000000, 1.000000,  1.000000,  -1.000000, 1.000000,  1.000000};

  File_data file_data;
  const char *filename = "obj/cube.obj";
  Data_array data_array = {0};
  obj_parser(&file_data, &data_array, filename);

  double value = 90;
  rotate_z(&data_array, file_data.vertex_count, value);
  unsigned int i = 0;
  while (i < file_data.vertex_count * 3) {
    ck_assert_double_eq_tol(vertices_result[i], data_array.vertices[i], EPS);
    i++;
  }
  free_memory(&data_array);
}
END_TEST

int main(void) {
  Suite *s = suite_create("FileDataSuite");
  TCase *tc = tcase_create("FileDataCase");

  tcase_add_test(tc, test_file_data_equivalence_1);
  tcase_add_test(tc, test_file_data_equivalence_2);
  tcase_add_test(tc, test_failed_path_name);
  tcase_add_test(tc, test_vertices_equivalence);
  tcase_add_test(tc, test_indices_equivalence);
  tcase_add_test(tc, test_indices_realloc);
  tcase_add_test(tc, test_afins_transformation_1);
  tcase_add_test(tc, test_afins_transformation_2);
  tcase_add_test(tc, test_afins_transformation_3);
  tcase_add_test(tc, test_afins_transformation_4);
  tcase_add_test(tc, test_afins_transformation_5);
  tcase_add_test(tc, test_afins_transformation_6);
  tcase_add_test(tc, test_afins_transformation_7);
  tcase_add_test(tc, test_afins_transformation_8);
  tcase_add_test(tc, test_afins_transformation_9);
  tcase_add_test(tc, test_afins_transformation_10);

  suite_add_tcase(s, tc);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);

  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
