#include "oglviewerwidget.h"

#include <QMessageBox>
#include <QMouseEvent>
#include <cmath>
extern "C" {
#include "source/afin.h"
#include "source/parser.h"
}

OGLViewerWidget::OGLViewerWidget(QWidget *parent) : QOpenGLWidget(parent) {}

OGLViewerWidget::~OGLViewerWidget() { free_memory(&this->data_array); }

void OGLViewerWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void OGLViewerWidget::changeProjection() {
  GLfloat h = this->height();
  GLfloat w = this->width();
  GLfloat ratioW = (w > h) ? w / h : 1;
  GLfloat ratioH = (w > h) ? 1 : h / w;
  GLfloat max_coef_with_ratioW = this->file_info.max_coef * ratioW;
  GLfloat max_coef_with_ratioH = this->file_info.max_coef * ratioH;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (projection_value == projection::Parallel) {
    glOrtho(-max_coef_with_ratioW, max_coef_with_ratioW, -max_coef_with_ratioH,
            max_coef_with_ratioH,
            -std::max(max_coef_with_ratioW, max_coef_with_ratioH),
            1000 * this->file_info.max_coef);
  } else if (projection_value == projection::Perspective) {
    float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
    float heapHeight = this->file_info.max_coef / (2 * tan(fov / 2));
    glFrustum(-max_coef_with_ratioW, max_coef_with_ratioW,
              -max_coef_with_ratioH, max_coef_with_ratioH, heapHeight,
              1000 * this->file_info.max_coef);
    glTranslated(0, 0, -heapHeight * 3);
  }
  glMatrixMode(GL_MODELVIEW);
}

void OGLViewerWidget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
}

void OGLViewerWidget::drawLines() {
  if (this->edges_type == e_type::Stripple) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  }
  glLineWidth(this->edges_thick);
  glColor3f(this->color_e.redF(), this->color_e.greenF(),
            this->color_e.blueF());
  glDrawElements(GL_LINES, this->file_info.indices_len, GL_UNSIGNED_INT,
                 data_array.indices);
  if (this->edges_type == e_type::Stripple) {
    glDisable(GL_LINE_STIPPLE);
  }
}

void OGLViewerWidget::drawPoints() {
  if (this->vert_type == v_type::Circle) {
    glEnable(GL_POINT_SMOOTH);
  }
  glPointSize(this->vertices_size);
  glColor3d(this->color_v.redF(), this->color_v.greenF(),
            this->color_v.blueF());
  glDrawArrays(GL_POINTS, 0, this->file_info.vertex_count);
  if (this->vert_type == v_type::Circle) {
    glDisable(GL_POINT_SMOOTH);
  }
}

void OGLViewerWidget::paintGL() {
  glClearColor(this->color_bg.redF(), this->color_bg.greenF(),
               this->color_bg.blueF(), this->color_bg.alphaF());
  changeProjection();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glVertexPointer(3, GL_DOUBLE, 0, this->data_array.vertices);

  glEnableClientState(GL_VERTEX_ARRAY);
  drawLines();
  if (this->vert_type != v_type::None) {
    drawPoints();
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void OGLViewerWidget::mousePressEvent(QMouseEvent *event) {
  this->lastPos = event->pos();
}
void OGLViewerWidget::mouseMoveEvent(QMouseEvent *event) {
  const int dx = event->position().x() - this->lastPos.x();
  const int dy = event->position().y() - this->lastPos.y();

  if (event->buttons() & Qt::LeftButton) {
    rotate_x(&this->data_array, this->file_info.vertex_count,
             this->rotateCoef * dy);
    rotate_y(&this->data_array, this->file_info.vertex_count,
             this->rotateCoef * dx);
    update();
  } else if (event->buttons() & Qt::RightButton) {
    move_coordinate(&this->data_array, this->file_info.vertex_count,
                    this->moveCoef * dx, 'x');
    move_coordinate(&this->data_array, this->file_info.vertex_count,
                    this->moveCoef * dy, 'y');
    update();
  }
  this->lastPos = event->pos();
}
void OGLViewerWidget::wheelEvent(QWheelEvent *event) {
  const int delta = event->angleDelta().y() / 120;
  const double scale_value = 1.05;
  scale_all_coordinate(&this->data_array, this->file_info.vertex_count,
                       pow(scale_value, delta));
  update();
}
