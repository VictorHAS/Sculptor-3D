#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include <sculptor.h>
#include <drawwidget.h>

enum {
    BOX, NOBOX, SPHERE, NOSPHERE, VOXEL, NOVOXEL, ELIPSE, NOELIPSE
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setR(int);
    void setG(int);
    void setB(int);
    void pickColor();
    void drawShape(int,int);
    void updateCoords(int,int);

private:
    Ui::MainWindow *ui;
    int r,g,b;
    void updateColor();
    Sculptor *s;
    int dimX, dimY, dimZ;
    int currentObject;
    int currentPlane;
    QActionGroup *actionGroup;

private slots:
    void on_actionSave_triggered();
    void on_actionNew_triggered();
    void on_actionInsert_Sphere_triggered();
    void on_actionRemove_Sphere_triggered();
    void on_actionInsert_Voxel_triggered();
    void on_actionRemove_Voxel_triggered();
    void on_actionInsert_Box_triggered();
    void on_actionRemove_Box_triggered();
    void on_actionInsert_Elipse_triggered();
    void on_actionRemove_Elipse_triggered();
    void clickedXY();
    void clickedZX();
    void clickedYZ();
    void on_sliderAxisX_valueChanged(int);
    void on_sliderAxisY_valueChanged(int);
    void on_sliderAxisZ_valueChanged(int);
    void on_actionGeomview_triggered(void);

};
#endif // MAINWINDOW_H
