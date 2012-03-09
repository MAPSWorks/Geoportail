#ifndef OVERLAY_H
#define OVERLAY_H

#include "mapwidget.h"
#include <QWidget>
#include <QRect>
#include <QPolygon>
#include <constants.h>
#include <QListWidget>
#include <QLabel>

class MapWidget;

typedef QVector<QPointF> Trace ;

class Overlay : public QWidget
{
    Q_OBJECT
public:
    explicit Overlay(MapWidget *parent = 0);
    double dist();
    void setListWidget(QListWidget* list = NULL);
signals:
    void gotoLongLat(QPointF longLat);

public slots:
    void setSelection(QRect rect) {selection = rect.normalized();}
    QPolygon getSelection(){return selection;}
    void addPoint(QPoint point);
    void setSelectionType(SelectionType s) {selType = s;}
    void clear() {selection.clear();}
    void hideSelection(){selectionOn = false;}
    void showSelection(){selectionOn = true;}
    void showScale(){scaleOn = true;}
    void hideScale(){scaleOn = false;}
    void setScaleRatio(double ratio){scaleRatio = ratio;}
    void loadTraceFromGPX(QString filename);
    void removeTraces();
    void showTrace(QListWidgetItem* trace);
protected :
    virtual void paintEvent(QPaintEvent *);

private :
    void drawDepartArrivee(QPolygon trace);

    QPolygon selection;
    SelectionType selType;
    QVector<Trace> traces;
    bool selectionOn;
    bool scaleOn;
    double scaleRatio; //en m/pixel
    MapWidget* map;
    int scaleLength(); // calcule la longueur de l'échelle en pixels
    int scaleDist();   // la distance représentée par l'échelle en m
    QListWidget* gpxList;

};

#endif // OVERLAY_H
