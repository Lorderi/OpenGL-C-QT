#ifndef AFIN_H
#define AFIN_H

#include <math.h>

#include "models.h"
#define PI 3.14159265358979323846264338327950288

void move_coordinate(Data_array *vertexes, const int vertexCount,
                     const double move_value, const char coordinate);
void scale_coordinate(Data_array *vertexes, const int vertexCount,
                      const double scale_value, const char coordinate);
void scale_all_coordinate(Data_array *vertexes, const int vertexCount,
                          const double scale_value);
void rotate_x(Data_array *vertexes, const int vertexCount, const double angle);
void rotate_y(Data_array *vertexes, const int vertexCount, const double angle);
void rotate_z(Data_array *vertexes, const int vertexCount, const double angle);

#endif  // AFIN_H
