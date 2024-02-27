#include "mainwindow.h"

#include <QBuffer>
#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include "ui_mainwindow.h"
extern "C" {
#include "source/afin.h"
#include "source/parser.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  settings = new QSettings("3dViewerConfig.ini", QSettings::IniFormat);
  timer = new QTimer;
  this->oglViewerWidget = ui->oglViewerWidgetItem;
  init_ui_items();
  init_signals();
  init_item_values();
}

MainWindow::~MainWindow() {
  writeSettings();
  delete this->settings;
  delete this->timer;
  delete this->gif;
  delete ui;
}

void MainWindow::writeSettings() {
  settings->beginGroup("oglViewerWidget");
  settings->setValue("rotateX", this->oglViewerWidget->rotateX);
  settings->setValue("rotateY", this->oglViewerWidget->rotateY);
  settings->setValue("rotateZ", this->oglViewerWidget->rotateZ);
  settings->setValue("moveX", this->oglViewerWidget->moveX);
  settings->setValue("moveY", this->oglViewerWidget->moveY);
  settings->setValue("moveZ", this->oglViewerWidget->moveZ);
  settings->setValue("scale", this->oglViewerWidget->scale);
  settings->setValue("color_bg", this->oglViewerWidget->color_bg);
  settings->setValue("color_v", this->oglViewerWidget->color_v);
  settings->setValue("color_e", this->oglViewerWidget->color_e);
  settings->endGroup();
  settings->beginGroup("mainwindow");
  settings->setValue("ViewPerspective",
                     ui->radioButton_ViewPerspective->isChecked());
  settings->setValue("EdgesType", ui->comboBox_EdgesType->currentIndex());
  settings->setValue("VerticesType", ui->comboBox_VerticesType->currentIndex());
  settings->setValue("VerticesSize", ui->spinBox_VerticesSize->value());
  settings->setValue("EdgesThick", ui->spinBox_EdgesThick->value());
  settings->setValue("Scale", ui->spinBox_Scale->value());
  settings->endGroup();
}

void MainWindow::readSettings() {
  if (settings->contains("oglViewerWidget/rotateX") &&
      settings->contains("oglViewerWidget/rotateY") &&
      settings->contains("oglViewerWidget/rotateZ") &&
      settings->contains("oglViewerWidget/moveX") &&
      settings->contains("oglViewerWidget/moveY") &&
      settings->contains("oglViewerWidget/moveZ") &&
      settings->contains("oglViewerWidget/scale") &&
      settings->contains("oglViewerWidget/color_bg") &&
      settings->contains("oglViewerWidget/color_v") &&
      settings->contains("oglViewerWidget/color_e")) {
    this->settings->beginGroup("oglViewerWidget");
    ui->horizontalSlider_RotateX->setValue(
        this->settings->value("rotateX").toInt());
    ui->horizontalSlider_RotateY->setValue(
        this->settings->value("rotateY").toInt());
    ui->horizontalSlider_RotateZ->setValue(
        this->settings->value("rotateZ").toInt());
    ui->horizontalSlider_MoveX->setValue(
        this->settings->value("moveX").toInt());
    ui->horizontalSlider_MoveY->setValue(
        this->settings->value("moveY").toInt());
    ui->horizontalSlider_MoveZ->setValue(
        this->settings->value("moveZ").toInt());
    ui->horizontalSlider_Scale->setValue(
        this->settings->value("scale").toInt());
    oglViewerWidget->color_bg =
        this->settings->value("color_bg", oglViewerWidget->color_bg)
            .value<QColor>();
    oglViewerWidget->color_v =
        this->settings->value("color_v", oglViewerWidget->color_bg)
            .value<QColor>();
    oglViewerWidget->color_e =
        this->settings->value("color_e", oglViewerWidget->color_bg)
            .value<QColor>();
    this->settings->value("color_v", oglViewerWidget->color_v);
    this->settings->value("color_e", oglViewerWidget->color_e);
    this->settings->endGroup();
  }
  if (settings->contains("mainwindow/ViewPerspective") &&
      settings->contains("mainwindow/EdgesType") &&
      settings->contains("mainwindow/VerticesType") &&
      settings->contains("mainwindow/VerticesSize") &&
      settings->contains("mainwindow/EdgesThick") &&
      settings->contains("mainwindow/Scale")) {
    this->settings->beginGroup("mainwindow");
    if (this->settings->value("ViewPerspective").toBool())
      ui->radioButton_ViewPerspective->setChecked(true);
    else
      ui->radioButton_ViewParallel->setChecked(true);
    update_projection_value();
    ui->comboBox_EdgesType->setCurrentIndex(
        this->settings->value("EdgesType").toInt());
    ui->comboBox_VerticesType->setCurrentIndex(
        this->settings->value("VerticesType").toInt());
    ui->spinBox_VerticesSize->setValue(
        this->settings->value("VerticesSize").toInt());
    ui->spinBox_EdgesThick->setValue(
        this->settings->value("EdgesThick").toInt());
    ui->spinBox_Scale->setValue(this->settings->value("Scale").toInt());
    this->settings->endGroup();
  }
  updateLabelColour();
  update();
}

void MainWindow::updateLabelColour() {
  setLabelColour(&this->oglViewerWidget->color_bg, ui->label_BGColourValue);
  setLabelColour(&this->oglViewerWidget->color_v,
                 ui->label_VerticesColourValue);
  setLabelColour(&this->oglViewerWidget->color_e, ui->label_EdgesColourValue);
}

void MainWindow::init_zero_values() {
  this->oglViewerWidget->prev_rotateX = this->oglViewerWidget->rotateX;
  this->oglViewerWidget->prev_rotateY = this->oglViewerWidget->rotateY;
  this->oglViewerWidget->prev_rotateZ = this->oglViewerWidget->rotateZ;
  this->oglViewerWidget->prev_moveX = this->oglViewerWidget->moveX;
  this->oglViewerWidget->prev_moveY = this->oglViewerWidget->moveY;
  this->oglViewerWidget->prev_moveZ = this->oglViewerWidget->moveZ;
  this->oglViewerWidget->prev_scale = this->oglViewerWidget->scale;
  ui->horizontalSlider_RotateX->setValue(0);
  ui->horizontalSlider_RotateY->setValue(0);
  ui->horizontalSlider_RotateZ->setValue(0);
  ui->horizontalSlider_MoveX->setValue(0);
  ui->horizontalSlider_MoveY->setValue(0);
  ui->horizontalSlider_MoveZ->setValue(0);
  ui->horizontalSlider_Scale->setValue(50);
}

void MainWindow::init_item_values() {
  init_zero_values();
  ui->horizontalSlider_Scale->setValue(this->oglViewerWidget->scale);
  this->oglViewerWidget->color_v.setRgbF(255, 255, 255, 1);
  this->oglViewerWidget->color_e.setRgbF(255, 255, 255, 1);
  this->oglViewerWidget->color_bg.setRgbF(0, 0, 0, 1);

  ui->radioButton_ViewPerspective->setChecked(true);
  update_projection_value();

  ui->comboBox_EdgesType->setCurrentIndex(0);
  ui->comboBox_VerticesType->setCurrentIndex(0);
  ui->spinBox_VerticesSize->setValue(1);
  ui->spinBox_EdgesThick->setValue(1);

  updateLabelColour();
}

void MainWindow::init_ui_items() {
  this->sliders[0] = ui->horizontalSlider_RotateX;
  this->sliders[1] = ui->horizontalSlider_RotateY;
  this->sliders[2] = ui->horizontalSlider_RotateZ;
  this->sliders[3] = ui->horizontalSlider_MoveX;
  this->sliders[4] = ui->horizontalSlider_MoveY;
  this->sliders[5] = ui->horizontalSlider_MoveZ;
  this->sliders[6] = ui->horizontalSlider_Scale;
  this->spinBoxes[0] = ui->spinBox_RotateX;
  this->spinBoxes[1] = ui->spinBox_RotateY;
  this->spinBoxes[2] = ui->spinBox_RotateZ;
  this->spinBoxes[3] = ui->spinBox_MoveX;
  this->spinBoxes[4] = ui->spinBox_MoveY;
  this->spinBoxes[5] = ui->spinBox_MoveZ;
  this->spinBoxes[6] = ui->spinBox_Scale;
}

void MainWindow::init_signals() {
  connect(ui->radioButton_ViewParallel, SIGNAL(clicked()), this,
          SLOT(update_projection_value()));
  connect(ui->radioButton_ViewPerspective, SIGNAL(clicked()), this,
          SLOT(update_projection_value()));
  connect(timer, SIGNAL(timeout()), this, SLOT(gif_add_frame()));
  for (unsigned int i = 0; i < size_value; i++) {
    connect(this->sliders[i], SIGNAL(valueChanged(int)), this->spinBoxes[i],
            SLOT(setValue(int)));
    connect(this->spinBoxes[i], SIGNAL(valueChanged(int)), this->sliders[i],
            SLOT(setValue(int)));
  }
}

void MainWindow::update_projection_value() {
  if (ui->radioButton_ViewPerspective->isChecked())
    this->oglViewerWidget->projection_value = projection::Perspective;
  else if (ui->radioButton_ViewParallel->isChecked())
    this->oglViewerWidget->projection_value = projection::Parallel;
  this->oglViewerWidget->update();
}

void MainWindow::update_label() {
  ui->label_NameFileValue->setText(
      QString::fromStdString(this->file_name).section('/', -1));
  ui->label_NumEdgesValue->setText(
      QString::number(this->oglViewerWidget->file_info.facets_count));
  ui->label_NumVerticlesValue->setText(
      QString::number(this->oglViewerWidget->file_info.vertex_count));
}

void MainWindow::on_actionClose_triggered() { close(); }

void MainWindow::initParser() {
  bool parser_rtrn =
      obj_parser(&this->oglViewerWidget->file_info,
                 &this->oglViewerWidget->data_array, this->file_name.c_str());
  if (parser_rtrn) {
    QMessageBox::warning(this, "Error", "Error: obj_parser");
  } else {
    update_label();
    this->oglViewerWidget->update();
  }
}

void MainWindow::on_actionOpen_triggered() {
  QString qfile_name = QFileDialog::getOpenFileName(
      this, tr("Open a file"), QDir::homePath(), tr("Obj Files (*.obj)"));
  if (qfile_name.isEmpty()) {
    QMessageBox::warning(this, "Error", "Error: empty qfile_name");
  } else {
    this->file_name = qfile_name.toStdString();

    if (this->parser_count == 0) readSettings();

    init_zero_values();
    initParser();
    double coeff =
        std::to_string(this->oglViewerWidget->file_info.vertex_count).size();
    if (coeff == 0) coeff = 1;
    this->move_coeff = 0.1 * coeff;
    this->oglViewerWidget->moveCoef = 0.01 * coeff;

    this->oglViewerWidget->update();
    parser_count++;
  }
}

bool MainWindow::check_ogl_box() {
  bool error_flag = false;
  if (!this->oglViewerWidget->data_array.vertices ||
      !this->oglViewerWidget->file_info.vertex_count) {
    error_flag = true;
  }
  return error_flag;
}

void MainWindow::on_horizontalSlider_RotateX_valueChanged(int value) {
  if (check_ogl_box()) return;
  rotate_x(&this->oglViewerWidget->data_array,
           this->oglViewerWidget->file_info.vertex_count,
           2 * (value - this->oglViewerWidget->rotateX));
  this->oglViewerWidget->rotateX = value;
  this->oglViewerWidget->update();
}

void MainWindow::on_horizontalSlider_RotateY_valueChanged(int value) {
  if (check_ogl_box()) return;
  rotate_y(&this->oglViewerWidget->data_array,
           this->oglViewerWidget->file_info.vertex_count,
           value - this->oglViewerWidget->rotateY);
  this->oglViewerWidget->rotateY = value;
  this->oglViewerWidget->update();
}

void MainWindow::on_horizontalSlider_RotateZ_valueChanged(int value) {
  if (check_ogl_box()) return;
  rotate_z(&this->oglViewerWidget->data_array,
           this->oglViewerWidget->file_info.vertex_count,
           value - this->oglViewerWidget->rotateZ);
  this->oglViewerWidget->rotateZ = value;
  this->oglViewerWidget->update();
}

void MainWindow::on_horizontalSlider_MoveX_valueChanged(int value) {
  if (check_ogl_box()) return;
  move_coordinate(&this->oglViewerWidget->data_array,
                  this->oglViewerWidget->file_info.vertex_count,
                  0.1 * (value - this->oglViewerWidget->moveX), 'x');
  this->oglViewerWidget->moveX = value;
  this->oglViewerWidget->update();
}

void MainWindow::on_horizontalSlider_MoveY_valueChanged(int value) {
  if (check_ogl_box()) return;
  move_coordinate(&this->oglViewerWidget->data_array,
                  this->oglViewerWidget->file_info.vertex_count,
                  this->move_coeff * (value - this->oglViewerWidget->moveY),
                  'y');
  this->oglViewerWidget->moveY = value;
  this->oglViewerWidget->update();
}

void MainWindow::on_horizontalSlider_MoveZ_valueChanged(int value) {
  if (check_ogl_box()) return;
  move_coordinate(&this->oglViewerWidget->data_array,
                  this->oglViewerWidget->file_info.vertex_count,
                  this->move_coeff * (value - this->oglViewerWidget->moveZ),
                  'z');
  this->oglViewerWidget->moveZ = value;
  this->oglViewerWidget->update();
}

void MainWindow::on_horizontalSlider_Scale_valueChanged(int value) {
  if (check_ogl_box()) return;
  scale_all_coordinate(&this->oglViewerWidget->data_array,
                       this->oglViewerWidget->file_info.vertex_count,
                       (double)value / this->oglViewerWidget->scale);
  this->oglViewerWidget->scale = value;
  this->oglViewerWidget->update();
}

void MainWindow::on_pushButton_DefaultSettings_clicked() {
  init_item_values();
  if (!this->file_name.empty()) {
    initParser();
  }
  this->oglViewerWidget->update();
}

void MainWindow::setLabelColour(QColor *color, QLabel *label) {
  label->setAutoFillBackground(true);
  QString values = QString::number(color->red()) + ", " +
                   QString::number(color->green()) + ", " +
                   QString::number(color->blue()) + ", " +
                   QString::number(color->alpha());
  label->setStyleSheet(
      "QLabel { background-color: rgba(" + values +
      "); border-style: solid; border-width: 1px; border-color: black; }");
}

void MainWindow::getAndSetColour(QColor *color, QLabel *label) {
  *color = QColorDialog::getColor(Qt::white, this, "Select Color");
  if (color->isValid()) {
    setLabelColour(color, label);
  }
}

void MainWindow::on_pushButton_BGColour_clicked() {
  getAndSetColour(&this->oglViewerWidget->color_bg, ui->label_BGColourValue);
  this->oglViewerWidget->update();
}

void MainWindow::on_pushButton_VerticesColour_clicked() {
  getAndSetColour(&this->oglViewerWidget->color_v,
                  ui->label_VerticesColourValue);
  this->oglViewerWidget->color_v.setAlpha(1);
  this->oglViewerWidget->update();
}

void MainWindow::on_pushButton_EdgesColour_clicked() {
  getAndSetColour(&this->oglViewerWidget->color_e, ui->label_EdgesColourValue);
  this->oglViewerWidget->color_e.setAlpha(1);
  this->oglViewerWidget->update();
}

void MainWindow::on_spinBox_EdgesThick_valueChanged(int arg1) {
  this->oglViewerWidget->edges_thick = arg1 * 0.7;
  this->oglViewerWidget->update();
}

void MainWindow::on_spinBox_VerticesSize_valueChanged(int arg1) {
  this->oglViewerWidget->vertices_size = arg1 * 0.7;
  this->oglViewerWidget->update();
}

void MainWindow::on_comboBox_VerticesType_currentIndexChanged(int index) {
  if (index == 0) {
    this->oglViewerWidget->vert_type = v_type::None;
  } else if (index == 1) {
    this->oglViewerWidget->vert_type = v_type::Circle;
  } else if (index == 2) {
    this->oglViewerWidget->vert_type = v_type::Square;
  }
  this->oglViewerWidget->update();
}

void MainWindow::on_comboBox_EdgesType_currentIndexChanged(int index) {
  if (index == 0) {
    this->oglViewerWidget->edges_type = e_type::Solid;
  } else if (index == 1) {
    this->oglViewerWidget->edges_type = e_type::Stripple;
  }
  this->oglViewerWidget->update();
}

void MainWindow::on_pushButton_SaveImage_clicked() {
  QString file_name = QFileDialog::getSaveFileName(
      this, "Save file", QDir::homePath(), "Images (*.jpeg *.bmp)");
  const char *file_extension = {};
  if (file_name.right(5).contains(".jpeg")) {
    file_extension = "JPEG";
  } else if (file_name.right(4).contains(".bmp")) {
    file_extension = "BMP";
  } else {
    QMessageBox::warning(this, "Error", "Error: filename");
    return;
  }
  bool error_flag =
      this->oglViewerWidget->grab().save(file_name, file_extension);
  if (!error_flag) {
    QMessageBox::warning(this, "Error", "Error: Save");
  }
}

void MainWindow::on_pushButton_SaveGIF_clicked() {
  gif_name = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(),
                                          "Gifs (*.gif)");
  if (!this->gif_name.right(4).contains(".gif")) {
    QMessageBox::warning(this, "Error", "Error: filename");
  } else {
    gif = new QGifImage;
    gif->setDefaultDelay(10);
    timer->setInterval(100);
    timer->start();
  }
}

void MainWindow::gif_add_frame() {
  QImage image = this->oglViewerWidget->grabFramebuffer();
  QImage scaled_image = image.scaled(QSize(640, 480));
  gif->addFrame(scaled_image);
  this->gif_frame_counter++;
  ui->statusbar->showMessage(QString::number(this->gif_frame_counter / 10) +
                             " second out of 5 seconds");
  if (this->gif_frame_counter == 50) {
    timer->stop();
    this->gif->save(gif_name);
    this->gif_frame_counter = 0;
    this->gif = 0;
    QMessageBox::information(this, "Gif", "Gif saved");
    ui->statusbar->showMessage("");
  }
}
