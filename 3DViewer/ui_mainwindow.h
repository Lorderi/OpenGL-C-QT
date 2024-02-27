/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include "oglviewerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QAction *actionOpen;
  QAction *actionClose;
  QWidget *centralwidget;
  QGridLayout *gridLayout_16;
  QScrollArea *scrollArea;
  QWidget *scrollAreaWidgetContents;
  QGridLayout *gridLayout_3;
  QSpacerItem *verticalSpacer;
  QFrame *frame_All;
  QGridLayout *gridLayout_15;
  QGroupBox *groupBox_2;
  QGridLayout *gridLayout_2;
  QRadioButton *radioButton_ViewPerspective;
  QRadioButton *radioButton_ViewParallel;
  QGroupBox *groupBox_Save;
  QGridLayout *gridLayout;
  QGridLayout *gridLayout_Save;
  QPushButton *pushButton_SaveGIF;
  QPushButton *pushButton_SaveImage;
  QGroupBox *groupBox_Settings;
  QGridLayout *gridLayout_10;
  QFrame *frame_Edges;
  QGridLayout *gridLayout_9;
  QGridLayout *gridLayout_Edges;
  QLabel *label_Edges;
  QSpinBox *spinBox_EdgesThick;
  QPushButton *pushButton_EdgesColour;
  QLabel *label_EdgesColourValue;
  QLabel *label_EdgesThick;
  QComboBox *comboBox_EdgesType;
  QLabel *label_EdgesType;
  QFrame *frame_Scale;
  QGridLayout *gridLayout_7;
  QGridLayout *gridLayout_Scale;
  QSlider *horizontalSlider_Scale;
  QSpinBox *spinBox_Scale;
  QLabel *label_Scale;
  QFrame *frame_Move;
  QGridLayout *gridLayout_5;
  QGridLayout *gridLayout_Move;
  QLabel *label_MoveZ;
  QSlider *horizontalSlider_MoveX;
  QSlider *horizontalSlider_MoveY;
  QLabel *label_MoveX;
  QLabel *label_MoveY;
  QSlider *horizontalSlider_MoveZ;
  QSpinBox *spinBox_MoveX;
  QSpinBox *spinBox_MoveY;
  QSpinBox *spinBox_MoveZ;
  QLabel *label_Move;
  QFrame *frame_Rotate;
  QGridLayout *gridLayout_6;
  QGridLayout *gridLayout_Rotate;
  QSlider *horizontalSlider_RotateX;
  QLabel *label_RotateY;
  QSpinBox *spinBox_RotateX;
  QSlider *horizontalSlider_RotateZ;
  QLabel *label_RotateX;
  QSpinBox *spinBox_RotateZ;
  QLabel *label_RotateZ;
  QSlider *horizontalSlider_RotateY;
  QSpinBox *spinBox_RotateY;
  QLabel *label_Rotate;
  QFrame *frame_BG;
  QGridLayout *gridLayout_8;
  QGridLayout *gridLayout_BGround;
  QLabel *label_BGColourValue;
  QPushButton *pushButton_BGColour;
  QLabel *label_BG;
  QFrame *frame_Vertices;
  QGridLayout *gridLayout_11;
  QGridLayout *gridLayout_Vertices;
  QComboBox *comboBox_VerticesType;
  QPushButton *pushButton_VerticesColour;
  QLabel *label_VerticesSize;
  QLabel *label_Vertices;
  QLabel *label_VerticesColourValue;
  QLabel *label_VerticesType;
  QSpinBox *spinBox_VerticesSize;
  QPushButton *pushButton_DefaultSettings;
  QGroupBox *groupBox_Info;
  QGridLayout *gridLayout_4;
  QGridLayout *gridLayout_Info;
  QFrame *frame_NameFile;
  QGridLayout *gridLayout_12;
  QLabel *label_NameFile;
  QLabel *label_NameFileValue;
  QFrame *frame_NumVerticles;
  QGridLayout *gridLayout_13;
  QLabel *label_NumVerticles;
  QLabel *label_NumVerticlesValue;
  QFrame *frame_NumEdges;
  QGridLayout *gridLayout_14;
  QLabel *label_NumEdges;
  QLabel *label_NumEdgesValue;
  OGLViewerWidget *oglViewerWidgetItem;
  QMenuBar *menubar;
  QMenu *menu_Open_file;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName("MainWindow");
    MainWindow->resize(1407, 1053);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
    MainWindow->setSizePolicy(sizePolicy);
    MainWindow->setMinimumSize(QSize(900, 600));
    actionOpen = new QAction(MainWindow);
    actionOpen->setObjectName("actionOpen");
    actionClose = new QAction(MainWindow);
    actionClose->setObjectName("actionClose");
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName("centralwidget");
    gridLayout_16 = new QGridLayout(centralwidget);
    gridLayout_16->setObjectName("gridLayout_16");
    scrollArea = new QScrollArea(centralwidget);
    scrollArea->setObjectName("scrollArea");
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
    scrollArea->setSizePolicy(sizePolicy1);
    scrollArea->setMinimumSize(QSize(300, 500));
    scrollArea->setMaximumSize(QSize(400, 16777215));
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 622, 961));
    gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
    gridLayout_3->setObjectName("gridLayout_3");
    verticalSpacer =
        new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Preferred);

    gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

    frame_All = new QFrame(scrollAreaWidgetContents);
    frame_All->setObjectName("frame_All");
    QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(frame_All->sizePolicy().hasHeightForWidth());
    frame_All->setSizePolicy(sizePolicy2);
    frame_All->setMinimumSize(QSize(300, 800));
    frame_All->setFrameShape(QFrame::NoFrame);
    frame_All->setFrameShadow(QFrame::Raised);
    gridLayout_15 = new QGridLayout(frame_All);
    gridLayout_15->setObjectName("gridLayout_15");
    groupBox_2 = new QGroupBox(frame_All);
    groupBox_2->setObjectName("groupBox_2");
    QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
    groupBox_2->setSizePolicy(sizePolicy3);
    groupBox_2->setAlignment(Qt::AlignCenter);
    gridLayout_2 = new QGridLayout(groupBox_2);
    gridLayout_2->setObjectName("gridLayout_2");
    radioButton_ViewPerspective = new QRadioButton(groupBox_2);
    radioButton_ViewPerspective->setObjectName("radioButton_ViewPerspective");
    sizePolicy1.setHeightForWidth(
        radioButton_ViewPerspective->sizePolicy().hasHeightForWidth());
    radioButton_ViewPerspective->setSizePolicy(sizePolicy1);
    radioButton_ViewPerspective->setLayoutDirection(Qt::LeftToRight);
    radioButton_ViewPerspective->setStyleSheet(QString::fromUtf8(""));
    radioButton_ViewPerspective->setChecked(true);
    radioButton_ViewPerspective->setAutoRepeat(false);

    gridLayout_2->addWidget(radioButton_ViewPerspective, 0, 0, 1, 1);

    radioButton_ViewParallel = new QRadioButton(groupBox_2);
    radioButton_ViewParallel->setObjectName("radioButton_ViewParallel");
    sizePolicy1.setHeightForWidth(
        radioButton_ViewParallel->sizePolicy().hasHeightForWidth());
    radioButton_ViewParallel->setSizePolicy(sizePolicy1);
    radioButton_ViewParallel->setStyleSheet(QString::fromUtf8(""));

    gridLayout_2->addWidget(radioButton_ViewParallel, 0, 1, 1, 1);

    gridLayout_15->addWidget(groupBox_2, 3, 0, 1, 1);

    groupBox_Save = new QGroupBox(frame_All);
    groupBox_Save->setObjectName("groupBox_Save");
    sizePolicy3.setHeightForWidth(
        groupBox_Save->sizePolicy().hasHeightForWidth());
    groupBox_Save->setSizePolicy(sizePolicy3);
    groupBox_Save->setAlignment(Qt::AlignCenter);
    gridLayout = new QGridLayout(groupBox_Save);
    gridLayout->setObjectName("gridLayout");
    gridLayout_Save = new QGridLayout();
    gridLayout_Save->setObjectName("gridLayout_Save");
    pushButton_SaveGIF = new QPushButton(groupBox_Save);
    pushButton_SaveGIF->setObjectName("pushButton_SaveGIF");
    sizePolicy1.setHeightForWidth(
        pushButton_SaveGIF->sizePolicy().hasHeightForWidth());
    pushButton_SaveGIF->setSizePolicy(sizePolicy1);

    gridLayout_Save->addWidget(pushButton_SaveGIF, 1, 0, 1, 1);

    pushButton_SaveImage = new QPushButton(groupBox_Save);
    pushButton_SaveImage->setObjectName("pushButton_SaveImage");
    sizePolicy1.setHeightForWidth(
        pushButton_SaveImage->sizePolicy().hasHeightForWidth());
    pushButton_SaveImage->setSizePolicy(sizePolicy1);

    gridLayout_Save->addWidget(pushButton_SaveImage, 0, 0, 1, 1);

    gridLayout->addLayout(gridLayout_Save, 0, 0, 1, 1);

    gridLayout_15->addWidget(groupBox_Save, 4, 0, 1, 1);

    groupBox_Settings = new QGroupBox(frame_All);
    groupBox_Settings->setObjectName("groupBox_Settings");
    sizePolicy3.setHeightForWidth(
        groupBox_Settings->sizePolicy().hasHeightForWidth());
    groupBox_Settings->setSizePolicy(sizePolicy3);
    groupBox_Settings->setAlignment(Qt::AlignCenter);
    gridLayout_10 = new QGridLayout(groupBox_Settings);
    gridLayout_10->setObjectName("gridLayout_10");
    frame_Edges = new QFrame(groupBox_Settings);
    frame_Edges->setObjectName("frame_Edges");
    sizePolicy3.setHeightForWidth(
        frame_Edges->sizePolicy().hasHeightForWidth());
    frame_Edges->setSizePolicy(sizePolicy3);
    frame_Edges->setFrameShape(QFrame::StyledPanel);
    frame_Edges->setFrameShadow(QFrame::Raised);
    gridLayout_9 = new QGridLayout(frame_Edges);
    gridLayout_9->setObjectName("gridLayout_9");
    gridLayout_Edges = new QGridLayout();
    gridLayout_Edges->setObjectName("gridLayout_Edges");
    label_Edges = new QLabel(frame_Edges);
    label_Edges->setObjectName("label_Edges");
    label_Edges->setLayoutDirection(Qt::LeftToRight);
    label_Edges->setAlignment(Qt::AlignCenter);

    gridLayout_Edges->addWidget(label_Edges, 0, 0, 1, 2);

    spinBox_EdgesThick = new QSpinBox(frame_Edges);
    spinBox_EdgesThick->setObjectName("spinBox_EdgesThick");
    sizePolicy1.setHeightForWidth(
        spinBox_EdgesThick->sizePolicy().hasHeightForWidth());
    spinBox_EdgesThick->setSizePolicy(sizePolicy1);
    spinBox_EdgesThick->setMinimum(1);
    spinBox_EdgesThick->setMaximum(20);
    spinBox_EdgesThick->setValue(1);

    gridLayout_Edges->addWidget(spinBox_EdgesThick, 4, 1, 1, 1);

    pushButton_EdgesColour = new QPushButton(frame_Edges);
    pushButton_EdgesColour->setObjectName("pushButton_EdgesColour");
    sizePolicy1.setHeightForWidth(
        pushButton_EdgesColour->sizePolicy().hasHeightForWidth());
    pushButton_EdgesColour->setSizePolicy(sizePolicy1);

    gridLayout_Edges->addWidget(pushButton_EdgesColour, 2, 1, 1, 1);

    label_EdgesColourValue = new QLabel(frame_Edges);
    label_EdgesColourValue->setObjectName("label_EdgesColourValue");
    sizePolicy3.setHeightForWidth(
        label_EdgesColourValue->sizePolicy().hasHeightForWidth());
    label_EdgesColourValue->setSizePolicy(sizePolicy3);
    label_EdgesColourValue->setMinimumSize(QSize(0, 0));
    label_EdgesColourValue->setStyleSheet(
        QString::fromUtf8("QLabel { border-style: solid; border-width: 1px; "
                          "border-color: black;  }"));

    gridLayout_Edges->addWidget(label_EdgesColourValue, 2, 0, 1, 1);

    label_EdgesThick = new QLabel(frame_Edges);
    label_EdgesThick->setObjectName("label_EdgesThick");
    sizePolicy3.setHeightForWidth(
        label_EdgesThick->sizePolicy().hasHeightForWidth());
    label_EdgesThick->setSizePolicy(sizePolicy3);

    gridLayout_Edges->addWidget(label_EdgesThick, 4, 0, 1, 1);

    comboBox_EdgesType = new QComboBox(frame_Edges);
    comboBox_EdgesType->addItem(QString());
    comboBox_EdgesType->addItem(QString());
    comboBox_EdgesType->setObjectName("comboBox_EdgesType");
    sizePolicy3.setHeightForWidth(
        comboBox_EdgesType->sizePolicy().hasHeightForWidth());
    comboBox_EdgesType->setSizePolicy(sizePolicy3);

    gridLayout_Edges->addWidget(comboBox_EdgesType, 3, 1, 1, 1);

    label_EdgesType = new QLabel(frame_Edges);
    label_EdgesType->setObjectName("label_EdgesType");
    sizePolicy3.setHeightForWidth(
        label_EdgesType->sizePolicy().hasHeightForWidth());
    label_EdgesType->setSizePolicy(sizePolicy3);

    gridLayout_Edges->addWidget(label_EdgesType, 3, 0, 1, 1);

    gridLayout_9->addLayout(gridLayout_Edges, 0, 0, 1, 1);

    gridLayout_10->addWidget(frame_Edges, 2, 2, 1, 1);

    frame_Scale = new QFrame(groupBox_Settings);
    frame_Scale->setObjectName("frame_Scale");
    sizePolicy3.setHeightForWidth(
        frame_Scale->sizePolicy().hasHeightForWidth());
    frame_Scale->setSizePolicy(sizePolicy3);
    frame_Scale->setFrameShape(QFrame::StyledPanel);
    frame_Scale->setFrameShadow(QFrame::Raised);
    gridLayout_7 = new QGridLayout(frame_Scale);
    gridLayout_7->setObjectName("gridLayout_7");
    gridLayout_Scale = new QGridLayout();
    gridLayout_Scale->setObjectName("gridLayout_Scale");
    horizontalSlider_Scale = new QSlider(frame_Scale);
    horizontalSlider_Scale->setObjectName("horizontalSlider_Scale");
    QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(
        horizontalSlider_Scale->sizePolicy().hasHeightForWidth());
    horizontalSlider_Scale->setSizePolicy(sizePolicy4);
    horizontalSlider_Scale->setMinimum(1);
    horizontalSlider_Scale->setMaximum(100);
    horizontalSlider_Scale->setValue(50);
    horizontalSlider_Scale->setOrientation(Qt::Horizontal);

    gridLayout_Scale->addWidget(horizontalSlider_Scale, 1, 0, 1, 1);

    spinBox_Scale = new QSpinBox(frame_Scale);
    spinBox_Scale->setObjectName("spinBox_Scale");
    sizePolicy1.setHeightForWidth(
        spinBox_Scale->sizePolicy().hasHeightForWidth());
    spinBox_Scale->setSizePolicy(sizePolicy1);
    spinBox_Scale->setMinimum(1);
    spinBox_Scale->setMaximum(100);
    spinBox_Scale->setValue(50);

    gridLayout_Scale->addWidget(spinBox_Scale, 1, 1, 1, 1);

    label_Scale = new QLabel(frame_Scale);
    label_Scale->setObjectName("label_Scale");
    sizePolicy3.setHeightForWidth(
        label_Scale->sizePolicy().hasHeightForWidth());
    label_Scale->setSizePolicy(sizePolicy3);
    label_Scale->setAlignment(Qt::AlignCenter);

    gridLayout_Scale->addWidget(label_Scale, 0, 0, 1, 2);

    gridLayout_7->addLayout(gridLayout_Scale, 0, 0, 1, 1);

    gridLayout_10->addWidget(frame_Scale, 1, 1, 1, 1);

    frame_Move = new QFrame(groupBox_Settings);
    frame_Move->setObjectName("frame_Move");
    sizePolicy3.setHeightForWidth(frame_Move->sizePolicy().hasHeightForWidth());
    frame_Move->setSizePolicy(sizePolicy3);
    frame_Move->setFrameShape(QFrame::StyledPanel);
    frame_Move->setFrameShadow(QFrame::Raised);
    gridLayout_5 = new QGridLayout(frame_Move);
    gridLayout_5->setObjectName("gridLayout_5");
    gridLayout_Move = new QGridLayout();
    gridLayout_Move->setObjectName("gridLayout_Move");
    label_MoveZ = new QLabel(frame_Move);
    label_MoveZ->setObjectName("label_MoveZ");
    sizePolicy3.setHeightForWidth(
        label_MoveZ->sizePolicy().hasHeightForWidth());
    label_MoveZ->setSizePolicy(sizePolicy3);

    gridLayout_Move->addWidget(label_MoveZ, 3, 0, 1, 1);

    horizontalSlider_MoveX = new QSlider(frame_Move);
    horizontalSlider_MoveX->setObjectName("horizontalSlider_MoveX");
    sizePolicy4.setHeightForWidth(
        horizontalSlider_MoveX->sizePolicy().hasHeightForWidth());
    horizontalSlider_MoveX->setSizePolicy(sizePolicy4);
    horizontalSlider_MoveX->setMinimum(-50);
    horizontalSlider_MoveX->setMaximum(50);
    horizontalSlider_MoveX->setValue(0);
    horizontalSlider_MoveX->setSliderPosition(0);
    horizontalSlider_MoveX->setOrientation(Qt::Horizontal);

    gridLayout_Move->addWidget(horizontalSlider_MoveX, 1, 1, 1, 1);

    horizontalSlider_MoveY = new QSlider(frame_Move);
    horizontalSlider_MoveY->setObjectName("horizontalSlider_MoveY");
    sizePolicy4.setHeightForWidth(
        horizontalSlider_MoveY->sizePolicy().hasHeightForWidth());
    horizontalSlider_MoveY->setSizePolicy(sizePolicy4);
    horizontalSlider_MoveY->setMinimum(-50);
    horizontalSlider_MoveY->setMaximum(50);
    horizontalSlider_MoveY->setValue(0);
    horizontalSlider_MoveY->setSliderPosition(0);
    horizontalSlider_MoveY->setOrientation(Qt::Horizontal);

    gridLayout_Move->addWidget(horizontalSlider_MoveY, 2, 1, 1, 1);

    label_MoveX = new QLabel(frame_Move);
    label_MoveX->setObjectName("label_MoveX");
    sizePolicy3.setHeightForWidth(
        label_MoveX->sizePolicy().hasHeightForWidth());
    label_MoveX->setSizePolicy(sizePolicy3);

    gridLayout_Move->addWidget(label_MoveX, 1, 0, 1, 1);

    label_MoveY = new QLabel(frame_Move);
    label_MoveY->setObjectName("label_MoveY");
    sizePolicy3.setHeightForWidth(
        label_MoveY->sizePolicy().hasHeightForWidth());
    label_MoveY->setSizePolicy(sizePolicy3);

    gridLayout_Move->addWidget(label_MoveY, 2, 0, 1, 1);

    horizontalSlider_MoveZ = new QSlider(frame_Move);
    horizontalSlider_MoveZ->setObjectName("horizontalSlider_MoveZ");
    sizePolicy4.setHeightForWidth(
        horizontalSlider_MoveZ->sizePolicy().hasHeightForWidth());
    horizontalSlider_MoveZ->setSizePolicy(sizePolicy4);
    horizontalSlider_MoveZ->setMinimum(-50);
    horizontalSlider_MoveZ->setMaximum(50);
    horizontalSlider_MoveZ->setValue(0);
    horizontalSlider_MoveZ->setSliderPosition(0);
    horizontalSlider_MoveZ->setOrientation(Qt::Horizontal);

    gridLayout_Move->addWidget(horizontalSlider_MoveZ, 3, 1, 1, 1);

    spinBox_MoveX = new QSpinBox(frame_Move);
    spinBox_MoveX->setObjectName("spinBox_MoveX");
    sizePolicy1.setHeightForWidth(
        spinBox_MoveX->sizePolicy().hasHeightForWidth());
    spinBox_MoveX->setSizePolicy(sizePolicy1);
    spinBox_MoveX->setMinimum(-50);
    spinBox_MoveX->setMaximum(50);

    gridLayout_Move->addWidget(spinBox_MoveX, 1, 2, 1, 1);

    spinBox_MoveY = new QSpinBox(frame_Move);
    spinBox_MoveY->setObjectName("spinBox_MoveY");
    sizePolicy1.setHeightForWidth(
        spinBox_MoveY->sizePolicy().hasHeightForWidth());
    spinBox_MoveY->setSizePolicy(sizePolicy1);
    spinBox_MoveY->setMinimum(-50);
    spinBox_MoveY->setMaximum(50);

    gridLayout_Move->addWidget(spinBox_MoveY, 2, 2, 1, 1);

    spinBox_MoveZ = new QSpinBox(frame_Move);
    spinBox_MoveZ->setObjectName("spinBox_MoveZ");
    sizePolicy1.setHeightForWidth(
        spinBox_MoveZ->sizePolicy().hasHeightForWidth());
    spinBox_MoveZ->setSizePolicy(sizePolicy1);
    spinBox_MoveZ->setMinimum(-50);
    spinBox_MoveZ->setMaximum(50);

    gridLayout_Move->addWidget(spinBox_MoveZ, 3, 2, 1, 1);

    label_Move = new QLabel(frame_Move);
    label_Move->setObjectName("label_Move");
    label_Move->setAlignment(Qt::AlignCenter);

    gridLayout_Move->addWidget(label_Move, 0, 0, 1, 3);

    gridLayout_5->addLayout(gridLayout_Move, 0, 0, 1, 1);

    gridLayout_10->addWidget(frame_Move, 0, 2, 1, 1);

    frame_Rotate = new QFrame(groupBox_Settings);
    frame_Rotate->setObjectName("frame_Rotate");
    sizePolicy3.setHeightForWidth(
        frame_Rotate->sizePolicy().hasHeightForWidth());
    frame_Rotate->setSizePolicy(sizePolicy3);
    frame_Rotate->setFrameShape(QFrame::StyledPanel);
    frame_Rotate->setFrameShadow(QFrame::Raised);
    gridLayout_6 = new QGridLayout(frame_Rotate);
    gridLayout_6->setObjectName("gridLayout_6");
    gridLayout_Rotate = new QGridLayout();
    gridLayout_Rotate->setObjectName("gridLayout_Rotate");
    horizontalSlider_RotateX = new QSlider(frame_Rotate);
    horizontalSlider_RotateX->setObjectName("horizontalSlider_RotateX");
    sizePolicy4.setHeightForWidth(
        horizontalSlider_RotateX->sizePolicy().hasHeightForWidth());
    horizontalSlider_RotateX->setSizePolicy(sizePolicy4);
    horizontalSlider_RotateX->setMinimum(-100);
    horizontalSlider_RotateX->setMaximum(100);
    horizontalSlider_RotateX->setValue(0);
    horizontalSlider_RotateX->setOrientation(Qt::Horizontal);

    gridLayout_Rotate->addWidget(horizontalSlider_RotateX, 1, 1, 1, 1);

    label_RotateY = new QLabel(frame_Rotate);
    label_RotateY->setObjectName("label_RotateY");
    sizePolicy3.setHeightForWidth(
        label_RotateY->sizePolicy().hasHeightForWidth());
    label_RotateY->setSizePolicy(sizePolicy3);

    gridLayout_Rotate->addWidget(label_RotateY, 2, 0, 1, 1);

    spinBox_RotateX = new QSpinBox(frame_Rotate);
    spinBox_RotateX->setObjectName("spinBox_RotateX");
    sizePolicy1.setHeightForWidth(
        spinBox_RotateX->sizePolicy().hasHeightForWidth());
    spinBox_RotateX->setSizePolicy(sizePolicy1);
    spinBox_RotateX->setMinimum(-100);
    spinBox_RotateX->setMaximum(100);

    gridLayout_Rotate->addWidget(spinBox_RotateX, 1, 2, 1, 1);

    horizontalSlider_RotateZ = new QSlider(frame_Rotate);
    horizontalSlider_RotateZ->setObjectName("horizontalSlider_RotateZ");
    sizePolicy4.setHeightForWidth(
        horizontalSlider_RotateZ->sizePolicy().hasHeightForWidth());
    horizontalSlider_RotateZ->setSizePolicy(sizePolicy4);
    horizontalSlider_RotateZ->setMinimum(-100);
    horizontalSlider_RotateZ->setMaximum(100);
    horizontalSlider_RotateZ->setValue(0);
    horizontalSlider_RotateZ->setOrientation(Qt::Horizontal);

    gridLayout_Rotate->addWidget(horizontalSlider_RotateZ, 3, 1, 1, 1);

    label_RotateX = new QLabel(frame_Rotate);
    label_RotateX->setObjectName("label_RotateX");
    sizePolicy3.setHeightForWidth(
        label_RotateX->sizePolicy().hasHeightForWidth());
    label_RotateX->setSizePolicy(sizePolicy3);

    gridLayout_Rotate->addWidget(label_RotateX, 1, 0, 1, 1);

    spinBox_RotateZ = new QSpinBox(frame_Rotate);
    spinBox_RotateZ->setObjectName("spinBox_RotateZ");
    sizePolicy1.setHeightForWidth(
        spinBox_RotateZ->sizePolicy().hasHeightForWidth());
    spinBox_RotateZ->setSizePolicy(sizePolicy1);
    spinBox_RotateZ->setMinimum(-100);
    spinBox_RotateZ->setMaximum(100);

    gridLayout_Rotate->addWidget(spinBox_RotateZ, 3, 2, 1, 1);

    label_RotateZ = new QLabel(frame_Rotate);
    label_RotateZ->setObjectName("label_RotateZ");
    sizePolicy3.setHeightForWidth(
        label_RotateZ->sizePolicy().hasHeightForWidth());
    label_RotateZ->setSizePolicy(sizePolicy3);

    gridLayout_Rotate->addWidget(label_RotateZ, 3, 0, 1, 1);

    horizontalSlider_RotateY = new QSlider(frame_Rotate);
    horizontalSlider_RotateY->setObjectName("horizontalSlider_RotateY");
    sizePolicy4.setHeightForWidth(
        horizontalSlider_RotateY->sizePolicy().hasHeightForWidth());
    horizontalSlider_RotateY->setSizePolicy(sizePolicy4);
    horizontalSlider_RotateY->setMinimum(-100);
    horizontalSlider_RotateY->setMaximum(100);
    horizontalSlider_RotateY->setValue(0);
    horizontalSlider_RotateY->setOrientation(Qt::Horizontal);

    gridLayout_Rotate->addWidget(horizontalSlider_RotateY, 2, 1, 1, 1);

    spinBox_RotateY = new QSpinBox(frame_Rotate);
    spinBox_RotateY->setObjectName("spinBox_RotateY");
    sizePolicy1.setHeightForWidth(
        spinBox_RotateY->sizePolicy().hasHeightForWidth());
    spinBox_RotateY->setSizePolicy(sizePolicy1);
    spinBox_RotateY->setMinimum(-100);
    spinBox_RotateY->setMaximum(100);

    gridLayout_Rotate->addWidget(spinBox_RotateY, 2, 2, 1, 1);

    label_Rotate = new QLabel(frame_Rotate);
    label_Rotate->setObjectName("label_Rotate");
    label_Rotate->setAlignment(Qt::AlignCenter);

    gridLayout_Rotate->addWidget(label_Rotate, 0, 0, 1, 3);

    gridLayout_6->addLayout(gridLayout_Rotate, 0, 0, 1, 1);

    gridLayout_10->addWidget(frame_Rotate, 0, 1, 1, 1);

    frame_BG = new QFrame(groupBox_Settings);
    frame_BG->setObjectName("frame_BG");
    sizePolicy3.setHeightForWidth(frame_BG->sizePolicy().hasHeightForWidth());
    frame_BG->setSizePolicy(sizePolicy3);
    frame_BG->setFrameShape(QFrame::StyledPanel);
    frame_BG->setFrameShadow(QFrame::Raised);
    gridLayout_8 = new QGridLayout(frame_BG);
    gridLayout_8->setObjectName("gridLayout_8");
    gridLayout_BGround = new QGridLayout();
    gridLayout_BGround->setObjectName("gridLayout_BGround");
    label_BGColourValue = new QLabel(frame_BG);
    label_BGColourValue->setObjectName("label_BGColourValue");
    sizePolicy3.setHeightForWidth(
        label_BGColourValue->sizePolicy().hasHeightForWidth());
    label_BGColourValue->setSizePolicy(sizePolicy3);
    label_BGColourValue->setStyleSheet(
        QString::fromUtf8("QLabel { border-style: solid; border-width: 1px; "
                          "border-color: black;  }"));

    gridLayout_BGround->addWidget(label_BGColourValue, 1, 0, 1, 1);

    pushButton_BGColour = new QPushButton(frame_BG);
    pushButton_BGColour->setObjectName("pushButton_BGColour");
    sizePolicy1.setHeightForWidth(
        pushButton_BGColour->sizePolicy().hasHeightForWidth());
    pushButton_BGColour->setSizePolicy(sizePolicy1);

    gridLayout_BGround->addWidget(pushButton_BGColour, 1, 1, 1, 1);

    label_BG = new QLabel(frame_BG);
    label_BG->setObjectName("label_BG");
    sizePolicy3.setHeightForWidth(label_BG->sizePolicy().hasHeightForWidth());
    label_BG->setSizePolicy(sizePolicy3);
    label_BG->setAlignment(Qt::AlignCenter);

    gridLayout_BGround->addWidget(label_BG, 0, 0, 1, 2);

    gridLayout_8->addLayout(gridLayout_BGround, 0, 0, 1, 1);

    gridLayout_10->addWidget(frame_BG, 1, 2, 1, 1);

    frame_Vertices = new QFrame(groupBox_Settings);
    frame_Vertices->setObjectName("frame_Vertices");
    sizePolicy3.setHeightForWidth(
        frame_Vertices->sizePolicy().hasHeightForWidth());
    frame_Vertices->setSizePolicy(sizePolicy3);
    frame_Vertices->setFrameShape(QFrame::StyledPanel);
    frame_Vertices->setFrameShadow(QFrame::Raised);
    gridLayout_11 = new QGridLayout(frame_Vertices);
    gridLayout_11->setObjectName("gridLayout_11");
    gridLayout_Vertices = new QGridLayout();
    gridLayout_Vertices->setObjectName("gridLayout_Vertices");
    comboBox_VerticesType = new QComboBox(frame_Vertices);
    comboBox_VerticesType->addItem(QString());
    comboBox_VerticesType->addItem(QString());
    comboBox_VerticesType->addItem(QString());
    comboBox_VerticesType->setObjectName("comboBox_VerticesType");
    sizePolicy3.setHeightForWidth(
        comboBox_VerticesType->sizePolicy().hasHeightForWidth());
    comboBox_VerticesType->setSizePolicy(sizePolicy3);

    gridLayout_Vertices->addWidget(comboBox_VerticesType, 4, 1, 1, 1);

    pushButton_VerticesColour = new QPushButton(frame_Vertices);
    pushButton_VerticesColour->setObjectName("pushButton_VerticesColour");
    sizePolicy1.setHeightForWidth(
        pushButton_VerticesColour->sizePolicy().hasHeightForWidth());
    pushButton_VerticesColour->setSizePolicy(sizePolicy1);

    gridLayout_Vertices->addWidget(pushButton_VerticesColour, 3, 1, 1, 1);

    label_VerticesSize = new QLabel(frame_Vertices);
    label_VerticesSize->setObjectName("label_VerticesSize");
    sizePolicy3.setHeightForWidth(
        label_VerticesSize->sizePolicy().hasHeightForWidth());
    label_VerticesSize->setSizePolicy(sizePolicy3);

    gridLayout_Vertices->addWidget(label_VerticesSize, 5, 0, 1, 1);

    label_Vertices = new QLabel(frame_Vertices);
    label_Vertices->setObjectName("label_Vertices");
    sizePolicy3.setHeightForWidth(
        label_Vertices->sizePolicy().hasHeightForWidth());
    label_Vertices->setSizePolicy(sizePolicy3);
    label_Vertices->setAlignment(Qt::AlignCenter);

    gridLayout_Vertices->addWidget(label_Vertices, 2, 0, 1, 2);

    label_VerticesColourValue = new QLabel(frame_Vertices);
    label_VerticesColourValue->setObjectName("label_VerticesColourValue");
    sizePolicy3.setHeightForWidth(
        label_VerticesColourValue->sizePolicy().hasHeightForWidth());
    label_VerticesColourValue->setSizePolicy(sizePolicy3);
    label_VerticesColourValue->setMinimumSize(QSize(0, 0));
    label_VerticesColourValue->setStyleSheet(
        QString::fromUtf8("QLabel { border-style: solid; border-width: 1px; "
                          "border-color: black;  }"));

    gridLayout_Vertices->addWidget(label_VerticesColourValue, 3, 0, 1, 1);

    label_VerticesType = new QLabel(frame_Vertices);
    label_VerticesType->setObjectName("label_VerticesType");
    sizePolicy3.setHeightForWidth(
        label_VerticesType->sizePolicy().hasHeightForWidth());
    label_VerticesType->setSizePolicy(sizePolicy3);

    gridLayout_Vertices->addWidget(label_VerticesType, 4, 0, 1, 1);

    spinBox_VerticesSize = new QSpinBox(frame_Vertices);
    spinBox_VerticesSize->setObjectName("spinBox_VerticesSize");
    sizePolicy1.setHeightForWidth(
        spinBox_VerticesSize->sizePolicy().hasHeightForWidth());
    spinBox_VerticesSize->setSizePolicy(sizePolicy1);
    spinBox_VerticesSize->setMaximum(20);
    spinBox_VerticesSize->setValue(1);

    gridLayout_Vertices->addWidget(spinBox_VerticesSize, 5, 1, 1, 1);

    gridLayout_11->addLayout(gridLayout_Vertices, 0, 0, 1, 1);

    gridLayout_10->addWidget(frame_Vertices, 2, 1, 1, 1);

    gridLayout_15->addWidget(groupBox_Settings, 2, 0, 1, 1);

    pushButton_DefaultSettings = new QPushButton(frame_All);
    pushButton_DefaultSettings->setObjectName("pushButton_DefaultSettings");
    sizePolicy1.setHeightForWidth(
        pushButton_DefaultSettings->sizePolicy().hasHeightForWidth());
    pushButton_DefaultSettings->setSizePolicy(sizePolicy1);
    pushButton_DefaultSettings->setMaximumSize(QSize(16777215, 30));

    gridLayout_15->addWidget(pushButton_DefaultSettings, 5, 0, 1, 1);

    groupBox_Info = new QGroupBox(frame_All);
    groupBox_Info->setObjectName("groupBox_Info");
    sizePolicy3.setHeightForWidth(
        groupBox_Info->sizePolicy().hasHeightForWidth());
    groupBox_Info->setSizePolicy(sizePolicy3);
    groupBox_Info->setMaximumSize(QSize(16777215, 180));
    groupBox_Info->setAlignment(Qt::AlignCenter);
    gridLayout_4 = new QGridLayout(groupBox_Info);
    gridLayout_4->setObjectName("gridLayout_4");
    gridLayout_Info = new QGridLayout();
    gridLayout_Info->setObjectName("gridLayout_Info");
    frame_NameFile = new QFrame(groupBox_Info);
    frame_NameFile->setObjectName("frame_NameFile");
    sizePolicy3.setHeightForWidth(
        frame_NameFile->sizePolicy().hasHeightForWidth());
    frame_NameFile->setSizePolicy(sizePolicy3);
    frame_NameFile->setFrameShape(QFrame::StyledPanel);
    frame_NameFile->setFrameShadow(QFrame::Raised);
    gridLayout_12 = new QGridLayout(frame_NameFile);
    gridLayout_12->setObjectName("gridLayout_12");
    label_NameFile = new QLabel(frame_NameFile);
    label_NameFile->setObjectName("label_NameFile");
    label_NameFile->setMaximumSize(QSize(16777215, 20));

    gridLayout_12->addWidget(label_NameFile, 0, 0, 1, 1);

    label_NameFileValue = new QLabel(frame_NameFile);
    label_NameFileValue->setObjectName("label_NameFileValue");
    label_NameFileValue->setMaximumSize(QSize(16777215, 20));

    gridLayout_12->addWidget(label_NameFileValue, 0, 1, 1, 1);

    gridLayout_Info->addWidget(frame_NameFile, 0, 0, 1, 2);

    frame_NumVerticles = new QFrame(groupBox_Info);
    frame_NumVerticles->setObjectName("frame_NumVerticles");
    sizePolicy3.setHeightForWidth(
        frame_NumVerticles->sizePolicy().hasHeightForWidth());
    frame_NumVerticles->setSizePolicy(sizePolicy3);
    frame_NumVerticles->setFrameShape(QFrame::StyledPanel);
    frame_NumVerticles->setFrameShadow(QFrame::Raised);
    gridLayout_13 = new QGridLayout(frame_NumVerticles);
    gridLayout_13->setObjectName("gridLayout_13");
    label_NumVerticles = new QLabel(frame_NumVerticles);
    label_NumVerticles->setObjectName("label_NumVerticles");
    label_NumVerticles->setMaximumSize(QSize(16777215, 20));

    gridLayout_13->addWidget(label_NumVerticles, 0, 0, 1, 1);

    label_NumVerticlesValue = new QLabel(frame_NumVerticles);
    label_NumVerticlesValue->setObjectName("label_NumVerticlesValue");
    label_NumVerticlesValue->setMaximumSize(QSize(16777215, 20));

    gridLayout_13->addWidget(label_NumVerticlesValue, 0, 1, 1, 1);

    gridLayout_Info->addWidget(frame_NumVerticles, 1, 0, 1, 2);

    frame_NumEdges = new QFrame(groupBox_Info);
    frame_NumEdges->setObjectName("frame_NumEdges");
    sizePolicy3.setHeightForWidth(
        frame_NumEdges->sizePolicy().hasHeightForWidth());
    frame_NumEdges->setSizePolicy(sizePolicy3);
    frame_NumEdges->setFrameShape(QFrame::StyledPanel);
    frame_NumEdges->setFrameShadow(QFrame::Raised);
    gridLayout_14 = new QGridLayout(frame_NumEdges);
    gridLayout_14->setObjectName("gridLayout_14");
    label_NumEdges = new QLabel(frame_NumEdges);
    label_NumEdges->setObjectName("label_NumEdges");
    label_NumEdges->setMaximumSize(QSize(16777215, 20));

    gridLayout_14->addWidget(label_NumEdges, 0, 0, 1, 1);

    label_NumEdgesValue = new QLabel(frame_NumEdges);
    label_NumEdgesValue->setObjectName("label_NumEdgesValue");
    label_NumEdgesValue->setMaximumSize(QSize(16777215, 20));

    gridLayout_14->addWidget(label_NumEdgesValue, 0, 1, 1, 1);

    gridLayout_Info->addWidget(frame_NumEdges, 2, 0, 1, 2);

    gridLayout_4->addLayout(gridLayout_Info, 0, 0, 1, 1);

    gridLayout_15->addWidget(groupBox_Info, 1, 0, 1, 1);

    gridLayout_3->addWidget(frame_All, 0, 0, 1, 1);

    scrollArea->setWidget(scrollAreaWidgetContents);

    gridLayout_16->addWidget(scrollArea, 0, 1, 1, 1);

    oglViewerWidgetItem = new OGLViewerWidget(centralwidget);
    oglViewerWidgetItem->setObjectName("oglViewerWidgetItem");
    sizePolicy1.setHeightForWidth(
        oglViewerWidgetItem->sizePolicy().hasHeightForWidth());
    oglViewerWidgetItem->setSizePolicy(sizePolicy1);
    oglViewerWidgetItem->setMinimumSize(QSize(600, 500));

    gridLayout_16->addWidget(oglViewerWidgetItem, 0, 0, 1, 1);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName("menubar");
    menubar->setGeometry(QRect(0, 0, 1407, 26));
    menu_Open_file = new QMenu(menubar);
    menu_Open_file->setObjectName("menu_Open_file");
    QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy5.setHorizontalStretch(0);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(
        menu_Open_file->sizePolicy().hasHeightForWidth());
    menu_Open_file->setSizePolicy(sizePolicy5);
    menu_Open_file->setMinimumSize(QSize(0, 0));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName("statusbar");
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menu_Open_file->menuAction());
    menu_Open_file->addAction(actionOpen);
    menu_Open_file->addSeparator();
    menu_Open_file->addAction(actionClose);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    actionOpen->setText(
        QCoreApplication::translate("MainWindow", "Open", nullptr));
    actionClose->setText(
        QCoreApplication::translate("MainWindow", "Close", nullptr));
    groupBox_2->setTitle(
        QCoreApplication::translate("MainWindow", "View", nullptr));
    radioButton_ViewPerspective->setText(
        QCoreApplication::translate("MainWindow", "Perspective", nullptr));
    radioButton_ViewParallel->setText(
        QCoreApplication::translate("MainWindow", "Parallel", nullptr));
    groupBox_Save->setTitle(
        QCoreApplication::translate("MainWindow", "Save", nullptr));
    pushButton_SaveGIF->setText(
        QCoreApplication::translate("MainWindow", "GIF", nullptr));
    pushButton_SaveImage->setText(
        QCoreApplication::translate("MainWindow", "ScreenShot", nullptr));
    groupBox_Settings->setTitle(
        QCoreApplication::translate("MainWindow", "Settings", nullptr));
    label_Edges->setText(
        QCoreApplication::translate("MainWindow", "Edges", nullptr));
    pushButton_EdgesColour->setText(
        QCoreApplication::translate("MainWindow", "Choose", nullptr));
    label_EdgesColourValue->setText(QString());
    label_EdgesThick->setText(
        QCoreApplication::translate("MainWindow", "Thickness", nullptr));
    comboBox_EdgesType->setItemText(
        0, QCoreApplication::translate("MainWindow", "Solid", "0"));
    comboBox_EdgesType->setItemText(
        1, QCoreApplication::translate("MainWindow", "Dotted", "1"));

    label_EdgesType->setText(
        QCoreApplication::translate("MainWindow", "Type", nullptr));
    label_Scale->setText(
        QCoreApplication::translate("MainWindow", "Scale", nullptr));
    label_MoveZ->setText(
        QCoreApplication::translate("MainWindow", "z", nullptr));
    label_MoveX->setText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    label_MoveY->setText(
        QCoreApplication::translate("MainWindow", "y", nullptr));
    label_Move->setText(
        QCoreApplication::translate("MainWindow", "Move", nullptr));
    label_RotateY->setText(
        QCoreApplication::translate("MainWindow", "y", nullptr));
    label_RotateX->setText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    label_RotateZ->setText(
        QCoreApplication::translate("MainWindow", "z", nullptr));
    label_Rotate->setText(
        QCoreApplication::translate("MainWindow", "Rotate", nullptr));
    label_BGColourValue->setText(QString());
    pushButton_BGColour->setText(
        QCoreApplication::translate("MainWindow", "Choose", nullptr));
    label_BG->setText(
        QCoreApplication::translate("MainWindow", "Background", nullptr));
    comboBox_VerticesType->setItemText(
        0, QCoreApplication::translate("MainWindow", "None", "0"));
    comboBox_VerticesType->setItemText(
        1, QCoreApplication::translate("MainWindow", "Circle", "1"));
    comboBox_VerticesType->setItemText(
        2, QCoreApplication::translate("MainWindow", "Square", "2"));

    pushButton_VerticesColour->setText(
        QCoreApplication::translate("MainWindow", "Choose", nullptr));
    label_VerticesSize->setText(
        QCoreApplication::translate("MainWindow", "Size", nullptr));
    label_Vertices->setText(
        QCoreApplication::translate("MainWindow", "Vertices", nullptr));
    label_VerticesColourValue->setText(QString());
    label_VerticesType->setText(
        QCoreApplication::translate("MainWindow", "Type", nullptr));
    pushButton_DefaultSettings->setText(
        QCoreApplication::translate("MainWindow", "Default settings", nullptr));
    groupBox_Info->setTitle(
        QCoreApplication::translate("MainWindow", "Info", nullptr));
    label_NameFile->setText(
        QCoreApplication::translate("MainWindow", "Name of file", nullptr));
    label_NameFileValue->setText(QString());
    label_NumVerticles->setText(QCoreApplication::translate(
        "MainWindow", "Number of vertices", nullptr));
    label_NumVerticlesValue->setText(QString());
    label_NumEdges->setText(
        QCoreApplication::translate("MainWindow", "Number of edges", nullptr));
    label_NumEdgesValue->setText(QString());
    menu_Open_file->setTitle(
        QCoreApplication::translate("MainWindow", "File", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
