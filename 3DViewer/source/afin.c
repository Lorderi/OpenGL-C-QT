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

// /// @brief после загрузки файла и центровки объекта он может оказаться
// слишком
// /// большим и частично или полностью не поместиться в виджет, функция вмещает
// /// объект в виджет
// /// @param vertexes массив с координатами вершин
// /// @param vertexCount кол-во вершин
// void auto_scale(Data_array *vertexes, const int vertexCount) {
//   double max_scale = pow(vertexes->vertices[0], 2) +
//                      pow(vertexes->vertices[1], 2) +
//                      pow(vertexes->vertices[2], 2);
//   for (int i = 1; i < vertexCount * 3; i += 3) {
//     double tmp_scale, x, y, z;
//     x = vertexes->vertices[i];
//     y = vertexes->vertices[i + 1];
//     z = vertexes->vertices[i + 2];
//     tmp_scale = pow(x, 2) + pow(y, 2) + pow(z, 2);
//     if (tmp_scale > max_scale) {
//       max_scale = tmp_scale;
//     }
//   }
//   max_scale = 1.0 / sqrt(max_scale);
//   scale_all_coordinate(vertexes, vertexCount, max_scale);
// }

// /// @brief Центровка нашего объекта. Необходимо запускать эту функцию сразу
// /// после открытия файла *.obj. Точки в исходном файле могут выходить за
// пределы
// /// области виджита, поэтому сначала центруем наш объект, переписывая
// значения
// /// спарсенных координат вершин
// /// @param vertexes массив с координатами вершин
// /// @param vertexCount кол-во вершин
// /// @param maxX максимальное значение X среди всех значений
// /// @param minX минимальное значение X среди всех значений
// /// @param maxY максимальное значение Y среди всех значений
// /// @param minY минимальное значение Y среди всех значений
// /// @param maxZ максимальное значение Z среди всех значений
// /// @param minZ минимальное значениеZ среди всех значений
// void set_center_object(Data_array *vertexes, const int vertexCount,
//                        const double maxX, const double minX, const double
//                        maxY, const double minY, const double maxZ, const
//                        double minZ) {
//   double centerX = minX + (maxX - minX) / 2.0;
//   double centerY = minY + (maxY - minY) / 2.0;
//   double centerZ = minZ + (maxZ - minZ) / 2.0;
//   for (int i = 0; i < vertexCount * 3; i += 3) {
//     vertexes->vertices[i] -= centerX;
//     vertexes->vertices[i + 1] -= centerY;
//     vertexes->vertices[i + 2] -= centerZ;
//   }
// }
