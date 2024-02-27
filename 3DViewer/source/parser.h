#ifndef PARSER_H
#define PARSER_H

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "models.h"

#define STR_SIZE 256
#define XYZ_LEN 3
#define INDX_LEN 2

enum xyz_pos { x_pos, y_pos, z_pos };

bool obj_parser(File_data* file_information, Data_array* data_array,
                const char* file_name);
bool get_information_from_file(File_data* file_information,
                               Data_array* data_array, FILE* file);
void set_init_data(File_data* file_information);
type_of_record get_type_of_record(char* buffer, File_data* file_information);
void calc_data_params(File_data* file_information, type_of_record record_type);
bool allocate_memory_for_models(Data_array* data_array,
                                File_data* file_information);
void parse_file(Data_array* data_array, File_data* file_information,
                FILE* file);
unsigned int calc_vertices_in_face();
void parse_face_string(const char* faceStr, unsigned int* indices,
                       File_data* file_information,
                       unsigned int facets_recorded);
void update_max_coordinate(double* max, double new_coordinate);
double* get_double_item(double* item, int row, int col);
unsigned int* get_int_item(unsigned int* item, int range_col, int row, int col);
void init_indice_array(unsigned int* indices, File_data* file_information,
                       unsigned int* indice_array,
                       unsigned int facets_recorded);
void free_memory(Data_array* data_array);

#endif  // PARSER_H
