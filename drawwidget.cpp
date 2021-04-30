#include "drawwidget.h"
#include <QPainter>
#include <QSize>
#include <QPen>
#include <QPoint>
#include <cmath>
#include <QTimerEvent>
#include <QMouseEvent>
#include <iostream>
#include <QMessageBox>
#include <QMessageBox>
#include <QGradient>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    fase=0.0;
    freq=1;
    nlinhas=10;
    ncolunas=10;
    pressed=false;
    larguraTela = rect().width();
    alturaTela = rect().height();
    larguraCelula = larguraTela/ncolunas;
    alturaCelula = alturaTela/nlinhas;
    if(alturaCelula > larguraCelula){
        dimCelula = larguraCelula;
    }else{
        dimCelula = alturaCelula;
    }
    setTamanho(nlinhas,ncolunas);
}
void DrawWidget::paintEvent(QPaintEvent *)
{
    QPen pen;
    QPainter p(this);
    QColor color;
    QRadialGradient gradient(QPointF(1,1),20);
    gradient.setColorAt(0,Qt::black);
    gradient.setColorAt(1,Qt::white);

    QBrush brush;
    p.setRenderHint(QPainter::Antialiasing,true);
    pen.setWidth(1);
    larguraTela = rect().width();
    alturaTela = rect().height();
    larguraCelula = larguraTela/ncolunas;
    alturaCelula = alturaTela/nlinhas;
    if(alturaCelula > larguraCelula){
        dimCelula = larguraCelula;
    }else{
        dimCelula = alturaCelula;
    }
    borderh = (larguraTela - ncolunas*dimCelula)/2;
    borderv = (alturaTela - nlinhas*dimCelula)/2;
    gradient.setRadius(dimCelula);
    gradient.setFocalPoint(-0.15*dimCelula,-0.15*dimCelula);
    gradient.setCenter(-0.15*dimCelula,-0.15*dimCelula);
    p.setPen(pen);
    p.drawRect(rect());

    for(uint i=0; i<v.size();i++){
        for(uint j=0; j<v[i].size();j++){
            if(v[i][j].isOn == true){
                p.save();
                p.translate(j*dimCelula+borderh+dimCelula/2,i*dimCelula+borderv/2);
                p.setPen(Qt::NoPen);
                color.setRgba(qRgba(v[i][j].r,v[i][j].g,v[i][j].b,v[i][j].a));
                gradient.setColorAt(0,Qt::white);
                gradient.setColorAt(.3,color);
                gradient.setColorAt(1,color.darker());
                p.setBrush(gradient);
                p.drawEllipse(-dimCelula/2+1,-dimCelula/2+1,dimCelula-1,dimCelula-1);
                p.restore();
            }else{
                brush.setColor(QColor(255,255,255,0));
                p.setBrush(brush);
                p.drawRect(j*dimCelula+borderh,i*dimCelula+borderv,dimCelula,dimCelula);
            }
        }
    }
}

void DrawWidget::setTamanho(int _nlinhas, int _ncolunas)
{
    nlinhas = _nlinhas;
    ncolunas = _ncolunas;
    update();
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    pressed = true;
    ret.adjust(borderh,borderv,-borderh,-borderv);
    if(ret.contains(e->pos())){
        posh = (e->pos().x()-borderh)*ncolunas/ret.width();
        posv = (e->pos().y()-borderv)*nlinhas/ret.height();
        emit updatePos(posh,posv);
    }
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    pressed = true;
    ret.adjust(borderh,borderv,-borderh,-borderv);
    if(ret.contains(e->pos()) && pressed){
        posh = (e->pos().x()-borderh)*ncolunas/ret.width();
        posv = (e->pos().y()-borderv)*nlinhas/ret.height();
        emit updatePos(posh,posv);
    }
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *)
{
    pressed = false;
}

void DrawWidget::loadMatrix(vector<vector<Voxel>> m)
{
    nlinhas = m.size();
    ncolunas = m[0].size();
    v = m;
    repaint();
}

void DrawWidget::setfreq(int _freq)
{
    freq = _freq;
    fase=0;
}
