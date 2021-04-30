#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QVector>
#include <sculptor.h>
#include <vector>

using namespace std;

class DrawWidget : public QWidget
{
    Q_OBJECT

private:
    float fase;
    float freq;
    int nlinhas, ncolunas;
    vector<vector<Voxel>> v;
    int borderv;
    int borderh;
    int dimCelula;
    int larguraTela, alturaTela;
    int larguraCelula, alturaCelula;
    bool pressed;
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    void setTamanho(int _nlinhas, int _ncolunas);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void loadMatrix(vector<vector<Voxel>> m);

signals:
    void updatePos(int,int);

public slots:
    void setfreq(int);

};

#endif // DRAWWIDGET_H
