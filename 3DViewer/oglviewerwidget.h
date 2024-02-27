#ifndef OGLVIEWERWIDGET_H
#define OGLVIEWERWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

extern "C" {
#include "source/models.h"
}

namespace Ui {
class OGLViewerWidget;
}

enum class projection { Parallel, Perspective };
enum class e_type { Solid, Stripple };
enum class v_type { None, Circle, Square };

class OGLViewerWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit OGLViewerWidget(QWidget *parent = nullptr);
  ~OGLViewerWidget();
  File_data file_info = {};
  Data_array data_array = {};
  projection projection_value = {projection::Perspective};
  const float rotateCoef = {0.3};
  float moveCoef = {0};
  e_type edges_type = {e_type::Solid};
  v_type vert_type = {v_type::None};
  float edges_thick = {1};
  float vertices_size = {1};
  QColor color_v = {};
  QColor color_e = {};
  QColor color_bg = {};
  double rotateX = {0};
  double rotateY = {0};
  double rotateZ = {0};
  double moveX = {0};
  double moveY = {0};
  double moveZ = {0};
  double scale = {50};
  double prev_rotateX = {0};
  double prev_rotateY = {0};
  double prev_rotateZ = {0};
  double prev_moveX = {0};
  double prev_moveY = {0};
  double prev_moveZ = {0};
  double prev_scale = {50};

 private:
  QPoint lastPos = {};

 protected:
  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;
  void changeProjection();
  void drawLines();
  void drawPoints();
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
};

#endif  // OGLVIEWERWIDGET_H
