#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <QColorDialog>
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    r = g = b = 255;
    dimY = dimX = dimZ = 10;
    currentObject = VOXEL;
    s = new Sculptor(dimX,dimY,dimZ);
    ui->sliderAxisX->setMaximum(dimX-1);
    ui->sliderAxisY->setMaximum(dimY-1);
    ui->sliderAxisZ->setMaximum(dimZ-1);
    ui->actionXY->trigger();
    updateColor();
    ui->drawWidget->loadMatrix(s->getPlane(ui->sliderAxisZ->value(),XY));
    currentPlane=XY;
    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionInsert_Box);
    actionGroup->addAction(ui->actionRemove_Box);
    actionGroup->addAction(ui->actionInsert_Sphere);
    actionGroup->addAction(ui->actionRemove_Sphere);
    actionGroup->addAction(ui->actionInsert_Elipse);
    actionGroup->addAction(ui->actionRemove_Elipse);
    actionGroup->addAction(ui->actionInsert_Voxel);
    actionGroup->addAction(ui->actionRemove_Voxel);
    ui->actionInsert_Voxel->setChecked(true);
    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionXY);
    actionGroup->addAction(ui->actionYZ);
    actionGroup->addAction(ui->actionZX);
    ui->actionXY->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateColor()
{
    QString color, textcolor;
    textcolor = "QPushButton { background-color: rgb("+
            QString().setNum(255-r) + ","+
            QString().setNum(255-g) + ","+
            QString().setNum(255-b) + ");}";
    color = "QPushButton { background-color: rgb("+
            QString().setNum(r) + ","+
            QString().setNum(g) + ","+
            QString().setNum(b) + ");}";

    ui->pushButtonColor->setStyleSheet(color);
    s->setColor(r,g,b,255);
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionInsert_Sphere_triggered()
{
    currentObject = SPHERE;
}

void MainWindow::on_actionRemove_Sphere_triggered()
{
    currentObject = NOSPHERE;
}

void MainWindow::on_actionInsert_Voxel_triggered()
{
    currentObject = VOXEL;
}

void MainWindow::on_actionRemove_Voxel_triggered()
{
    currentObject = NOVOXEL;
}

void MainWindow::on_actionInsert_Box_triggered()
{
    currentObject = BOX;
}

void MainWindow::on_actionRemove_Box_triggered()
{
    currentObject = NOBOX;
}

void MainWindow::on_actionInsert_Elipse_triggered()
{
    currentObject = ELIPSE;
}

void MainWindow::on_actionRemove_Elipse_triggered()
{
    currentObject = NOELIPSE;
}

void MainWindow::clickedXY()
{
    ui->drawWidget->loadMatrix(s->getPlane(ui->sliderAxisZ->value(),XY));
    currentPlane = XY;
}

void MainWindow::clickedZX()
{
    ui->drawWidget->loadMatrix(s->getPlane(ui->sliderAxisZ->value(),ZX));
    currentPlane = ZX;
}

void MainWindow::clickedYZ()
{
    ui->drawWidget->loadMatrix(s->getPlane(ui->sliderAxisZ->value(),YZ));
    currentPlane = YZ;
}

void MainWindow::on_sliderAxisX_valueChanged(int value)
{
   if(currentPlane==YZ)
        ui->drawWidget->loadMatrix(s->getPlane(value,YZ));

}

void MainWindow::on_sliderAxisY_valueChanged(int value)
{
       if(currentPlane==ZX)
           ui->drawWidget->loadMatrix(s->getPlane(value,ZX));
}

void MainWindow::on_sliderAxisZ_valueChanged(int value)
{
        if(currentPlane==XY)
            ui->drawWidget->loadMatrix(s->getPlane(value,XY));
}

void MainWindow::on_actionGeomview_triggered()
{

}


void MainWindow::setR(int _r)
{
    r=_r;
    updateColor();
}

void MainWindow::setG(int _r)
{
    g=_r;
    updateColor();
}

void MainWindow::setB(int _r)
{
    b=_r;
    updateColor();
}

void MainWindow::pickColor()
{
    QColorDialog d;
    d.exec();
    r = d.selectedColor().red();
    g=d.selectedColor().green();
    b = d.selectedColor().blue();
    ui->horizontalSliderR->setValue(r);
    ui->horizontalSliderG->setValue(g);
    ui->horizontalSliderB->setValue(b);
    updateColor();
}

void MainWindow::drawShape(int horizClick, int vertClick)
{
    switch (currentPlane) {
    case XY:
        switch (currentObject) {
        case SPHERE:
            s->putSphere(vertClick,horizClick,ui->sliderAxisZ->value(),ui->sliderRadius->value());
            ui->drawWidget->loadMatrix(s->getPlane(ui->sliderAxisZ->value(),XY));
            break;

        }
    case ZX:
        switch (currentObject) {
        case SPHERE:
            s->putSphere(horizClick,ui->sliderAxisY->value(),vertClick,ui->sliderRadius->value());
            ui->drawWidget->loadMatrix(s->getPlane(ui->sliderAxisY->value(),ZX));
            break;

        }
    case YZ:
        switch (currentObject) {
        case SPHERE:
            s->putSphere(ui->sliderAxisX->value(),vertClick,horizClick,ui->sliderRadius->value());
            ui->drawWidget->loadMatrix(s->getPlane(ui->sliderAxisX->value(),YZ));
            break;

        }
    }
}

void MainWindow::updateCoords(int horizClick, int vertClick)
{
    switch (currentPlane) {
    case XY:
        ui->labelAxisX->setNum(vertClick);
        ui->labelAxisY->setNum(horizClick);
        break;
    case ZX:
        ui->labelAxisX->setNum(vertClick);
        ui->labelAxisZ->setNum(horizClick);
        break;
    case YZ:
        ui->labelAxisY->setNum(vertClick);
        ui->labelAxisZ->setNum(horizClick);
        break;
    }
}

