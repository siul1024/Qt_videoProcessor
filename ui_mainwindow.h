/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *videoEdit;
    QPushButton *Button_start;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QGraphicsView *graphicsView_B;
    QLabel *label;
    QGraphicsView *graphicsView_G;
    QGraphicsView *graphicsView_R;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *tabVideo;
    QGraphicsView *graphicsView_Video;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_R;
    QCheckBox *checkBox_G;
    QCheckBox *checkBox_B;
    QWidget *tabTransform;
    QGraphicsView *graphicsView_trans;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSlider_trans;
    QDial *dial_trans;
    QWidget *tabREC;
    QGraphicsView *graphicsView_rec;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QLabel *label_5;
    QLineEdit *lineEdit_path;
    QPushButton *Button_capture;
    QPushButton *Button_rec;
    QPushButton *Button_rec_stop;
    QWidget *tabDetecting;
    QGraphicsView *graphicsView_detecting;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Button_FACE;
    QPushButton *pushButton_3;
    QPushButton *Button_LINE;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(790, 563);
        QPalette palette;
        QBrush brush(QColor(203, 203, 203, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        QBrush brush1(QColor(145, 145, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setTabletTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 500, 771, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        videoEdit = new QLineEdit(horizontalLayoutWidget);
        videoEdit->setObjectName(QString::fromUtf8("videoEdit"));

        horizontalLayout->addWidget(videoEdit);

        Button_start = new QPushButton(horizontalLayoutWidget);
        Button_start->setObjectName(QString::fromUtf8("Button_start"));

        horizontalLayout->addWidget(Button_start);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 191, 471));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        graphicsView_B = new QGraphicsView(gridLayoutWidget);
        graphicsView_B->setObjectName(QString::fromUtf8("graphicsView_B"));

        gridLayout->addWidget(graphicsView_B, 6, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        graphicsView_G = new QGraphicsView(gridLayoutWidget);
        graphicsView_G->setObjectName(QString::fromUtf8("graphicsView_G"));

        gridLayout->addWidget(graphicsView_G, 3, 0, 1, 1);

        graphicsView_R = new QGraphicsView(gridLayoutWidget);
        graphicsView_R->setObjectName(QString::fromUtf8("graphicsView_R"));

        gridLayout->addWidget(graphicsView_R, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(210, 10, 571, 481));
        tabVideo = new QWidget();
        tabVideo->setObjectName(QString::fromUtf8("tabVideo"));
        graphicsView_Video = new QGraphicsView(tabVideo);
        graphicsView_Video->setObjectName(QString::fromUtf8("graphicsView_Video"));
        graphicsView_Video->setGeometry(QRect(10, 10, 551, 391));
        horizontalLayoutWidget_5 = new QWidget(tabVideo);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(150, 410, 261, 26));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_R = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_R->setObjectName(QString::fromUtf8("checkBox_R"));
        checkBox_R->setChecked(true);

        horizontalLayout_5->addWidget(checkBox_R);

        checkBox_G = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_G->setObjectName(QString::fromUtf8("checkBox_G"));
        checkBox_G->setChecked(true);

        horizontalLayout_5->addWidget(checkBox_G);

        checkBox_B = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_B->setObjectName(QString::fromUtf8("checkBox_B"));
        checkBox_B->setChecked(true);

        horizontalLayout_5->addWidget(checkBox_B);

        tabWidget->addTab(tabVideo, QString());
        tabTransform = new QWidget();
        tabTransform->setObjectName(QString::fromUtf8("tabTransform"));
        graphicsView_trans = new QGraphicsView(tabTransform);
        graphicsView_trans->setObjectName(QString::fromUtf8("graphicsView_trans"));
        graphicsView_trans->setGeometry(QRect(10, 10, 551, 391));
        horizontalLayoutWidget_4 = new QWidget(tabTransform);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(60, 410, 441, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_trans = new QSlider(horizontalLayoutWidget_4);
        horizontalSlider_trans->setObjectName(QString::fromUtf8("horizontalSlider_trans"));
        horizontalSlider_trans->setMinimum(-150);
        horizontalSlider_trans->setMaximum(150);
        horizontalSlider_trans->setValue(0);
        horizontalSlider_trans->setTracking(true);
        horizontalSlider_trans->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_trans);

        dial_trans = new QDial(tabTransform);
        dial_trans->setObjectName(QString::fromUtf8("dial_trans"));
        dial_trans->setGeometry(QRect(460, 300, 101, 101));
        dial_trans->setMaximum(36);
        dial_trans->setValue(0);
        dial_trans->setWrapping(true);
        tabWidget->addTab(tabTransform, QString());
        tabREC = new QWidget();
        tabREC->setObjectName(QString::fromUtf8("tabREC"));
        graphicsView_rec = new QGraphicsView(tabREC);
        graphicsView_rec->setObjectName(QString::fromUtf8("graphicsView_rec"));
        graphicsView_rec->setGeometry(QRect(10, 10, 551, 391));
        horizontalLayoutWidget_2 = new QWidget(tabREC);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 410, 401, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(horizontalLayoutWidget_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_path = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));

        horizontalLayout_2->addWidget(lineEdit_path);

        Button_capture = new QPushButton(tabREC);
        Button_capture->setObjectName(QString::fromUtf8("Button_capture"));
        Button_capture->setGeometry(QRect(480, 410, 81, 31));
        Button_rec = new QPushButton(tabREC);
        Button_rec->setObjectName(QString::fromUtf8("Button_rec"));
        Button_rec->setGeometry(QRect(420, 410, 31, 31));
        QPalette palette1;
        QBrush brush2(QColor(204, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        Button_rec->setPalette(palette1);
        Button_rec_stop = new QPushButton(tabREC);
        Button_rec_stop->setObjectName(QString::fromUtf8("Button_rec_stop"));
        Button_rec_stop->setGeometry(QRect(450, 410, 31, 31));
        tabWidget->addTab(tabREC, QString());
        tabDetecting = new QWidget();
        tabDetecting->setObjectName(QString::fromUtf8("tabDetecting"));
        graphicsView_detecting = new QGraphicsView(tabDetecting);
        graphicsView_detecting->setObjectName(QString::fromUtf8("graphicsView_detecting"));
        graphicsView_detecting->setGeometry(QRect(10, 10, 551, 391));
        horizontalLayoutWidget_3 = new QWidget(tabDetecting);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 410, 551, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Button_FACE = new QPushButton(horizontalLayoutWidget_3);
        Button_FACE->setObjectName(QString::fromUtf8("Button_FACE"));

        horizontalLayout_3->addWidget(Button_FACE);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        Button_LINE = new QPushButton(horizontalLayoutWidget_3);
        Button_LINE->setObjectName(QString::fromUtf8("Button_LINE"));

        horizontalLayout_3->addWidget(Button_LINE);

        tabWidget->addTab(tabDetecting, QString());
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 540, 51, 18));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 540, 711, 18));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "File Path / RTSP Url / Camera Index :", nullptr));
        videoEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        Button_start->setText(QApplication::translate("MainWindow", "START", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "GREEN CHANNEL HISTOGRAM", nullptr));
        label->setText(QApplication::translate("MainWindow", "RED CHANNEL HISTOGRAM", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "BLUE CHANNEL HISTOGRAM", nullptr));
        checkBox_R->setText(QApplication::translate("MainWindow", "RED", nullptr));
        checkBox_G->setText(QApplication::translate("MainWindow", "GREEN", nullptr));
        checkBox_B->setText(QApplication::translate("MainWindow", "BLUE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabVideo), QApplication::translate("MainWindow", "Video", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTransform), QApplication::translate("MainWindow", "Transform", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "Brightness", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "PATH", nullptr));
        lineEdit_path->setText(QApplication::translate("MainWindow", "./videotest.avi", nullptr));
        Button_capture->setText(QApplication::translate("MainWindow", "CAPTURE", nullptr));
        Button_rec->setText(QApplication::translate("MainWindow", "\342\227\217", nullptr));
        Button_rec_stop->setText(QApplication::translate("MainWindow", "\342\226\240", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabREC), QApplication::translate("MainWindow", "REC", nullptr));
        Button_FACE->setText(QApplication::translate("MainWindow", "FACE", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "CAR", nullptr));
        Button_LINE->setText(QApplication::translate("MainWindow", "LINE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDetecting), QApplication::translate("MainWindow", "Detecting", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "status:", nullptr));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
