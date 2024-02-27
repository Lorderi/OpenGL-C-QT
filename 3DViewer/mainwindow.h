#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QSettings>
#include <QSlider>
#include <QSpinBox>
#include <QTimer>

#include "./QtGifImage/src/gifimage/qgifimage.h"
#include "oglviewerwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_actionClose_triggered();
  void on_actionOpen_triggered();
  void update_projection_value();
  void on_horizontalSlider_RotateX_valueChanged(int value);
  void on_horizontalSlider_RotateY_valueChanged(int value);
  void on_horizontalSlider_RotateZ_valueChanged(int value);
  void on_horizontalSlider_MoveX_valueChanged(int value);
  void on_horizontalSlider_MoveY_valueChanged(int value);
  void on_horizontalSlider_MoveZ_valueChanged(int value);
  void on_horizontalSlider_Scale_valueChanged(int value);
  void on_pushButton_DefaultSettings_clicked();
  void on_pushButton_BGColour_clicked();
  void on_pushButton_VerticesColour_clicked();
  void on_pushButton_EdgesColour_clicked();
  void on_spinBox_EdgesThick_valueChanged(int arg1);
  void on_spinBox_VerticesSize_valueChanged(int arg1);
  void on_comboBox_VerticesType_currentIndexChanged(int index);
  void on_comboBox_EdgesType_currentIndexChanged(int index);
  void on_pushButton_SaveImage_clicked();
  void on_pushButton_SaveGIF_clicked();
  void gif_add_frame();

 private:
  Ui::MainWindow *ui;
  OGLViewerWidget *oglViewerWidget = nullptr;
  QSettings *settings;
  std::string file_name = "";
  const unsigned int size_value = {7};
  QSlider *sliders[7];
  QSpinBox *spinBoxes[7];
  unsigned int parser_count = {0};
  QGifImage *gif = {};
  QTimer *timer = {};
  unsigned int gif_frame_counter = {0};
  QString gif_name = "";
  double move_coeff = {0};
  void update_label();
  void init_signals();
  void init_ui_items();
  void init_item_values();
  void init_zero_values();
  void getAndSetColour(QColor *color, QLabel *label);
  void setLabelColour(QColor *color, QLabel *label);
  void initParser();
  void updateLabelColour();
  void writeSettings();
  void readSettings();
  bool check_ogl_box();
};
#endif  // MAINWINDOW_H
