#include "afin.h"

/// @brief смещает нужную координату на определенное значение
/// @param vertexes массив с координатами вершин
/// @param vertexCount кол-во вершин
/// @param move_value значение, на которое требуется сместить координату
/// @param coordinate передаем символ координаты, которую хотим поменять: 'x'
/// или 'y' или 'z'
void move_coordinate(Data_array *vertexes, const int vertexCount,
                     const double move_value, const char coordinate) {
  for (int i = 0; i < vertexCount * 3; i += 3) {
    if (coordinate == 'x') {
      vertexes->vertices[i] += move_value;
    } else {
      if (coordinate == 'y') {
        vertexes->vertices[i + 1] += move_value;
      } else {
        vertexes->vertices[i + 2] += move_value;
      }
    }
  }
}

void scale_all_coordinate(Data_array *vertexes, const int vertexCount,
                          const double scale_value) {
  scale_coordinate(vertexes, vertexCount, scale_value, 'x');
  scale_coordinate(vertexes, vertexCount, scale_value, 'y');
  scale_coordinate(vertexes, vertexCount, scale_value, 'z');
}

/// @brief изменение масштаба координат
/// @param vertexes массив с координатами вершин
/// @param vertexCount кол-во вершин
/// @param scale_value значение, на которое требуется масштабировать координату
/// @param coordinate передаем символ координаты, которую хотим поменять: 'x'
/// или 'y' или 'z'
void scale_coordinate(Data_array *vertexes, const int vertexCount,
                      const double scale_value, const char coordinate) {
  for (int i = 0; i < vertexCount * 3; i += 3) {
    if (coordinate == 'x') {
      vertexes->vertices[i] *= scale_value;
    } else {
      if (coordinate == 'y') {
        vertexes->vertices[i + 1] *= scale_value;
      } else {
        vertexes->vertices[i + 2] *= scale_value;
      }
    }
  }
}

/// @brief вращение по X
/// @param vertexes массив с координатами вершин
/// @param vertexCount кол-во вершин
/// @param angle угол в градусах
void rotate_x(Data_array *vertexes, const int vertexCount, const double angle) {
  double angle_rad = angle * PI / 180.0;
  for (int i = 0; i < vertexCount * 3; i += 3) {
    double Y = vertexes->vertices[i + 1];
    double Z = vertexes->vertices[i + 2];
    vertexes->vertices[i + 1] = Y * cos(angle_rad) + Z * sin(angle_rad);
    vertexes->vertices[i + 2] = -Y * sin(angle_rad) + Z * cos(angle_rad);
  }
}

/// @brief вращение по Y
/// @param vertexes массив с координатами вершин
/// @param vertexCount кол-во вершин
/// @param angle угол в градусах
void rotate_y(Data_array *vertexes, const int vertexCount, const double angle) {
  double angle_rad = angle * PI / 180.0;
  for (int i = 0; i < vertexCount * 3; i += 3) {
    double X = vertexes->vertices[i];
    double Z = vertexes->vertices[i + 2];
    vertexes->vertices[i] = X * cos(angle_rad) + Z * sin(angle_rad);
    vertexes->vertices[i + 2] = -X * sin(angle_rad) + Z * cos(angle_rad);
  }
}

/// @brief вращение по Z
/// @param vertexes массив с координатами вершин
/// @param vertexCount кол-во вершин
/// @param angle угол в градусах
void rotate_z(Data_array *vertexes, const int vertexCount, const double angle) {
  double angle_rad = angle * PI / 180.0;
  for (int i = 0; i < vertexCount * 3; i += 3) {
    double X = vertexes->vertices[i];
    double Y = vertexes->vertices[i + 1];
    vertexes->vertices[i] = X * cos(angle_rad) + Y * sin(angle_rad);
    vertexes->vertices[i + 1] = -X * sin(angle_rad) + Y * cos(angle_rad);
  }
}
