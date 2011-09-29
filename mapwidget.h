#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QList>
#include <QPoint>
#include <QRect>
#include <QString>
#include <QMouseEvent>
#include <QPixmap>
#include <QProgressBar>
#include "tile.h"
#include "geoengine.h"
#include "constants.h"
#include "overlay.h"

class MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = 0);
    void setCouche(Couche c);
    double getLongitude() {return geoEngine->convertToLongitude(center.x());}
    double getLatitude() {return geoEngine->convertToLatitude(center.y());}

signals:
    void coordChange(double longitude, double latitude);
    void mouseCoordChange(double, double);
    void setDLEnabled(bool);

public slots:
    void receiveData(QByteArray,int);
   // void startDownload();
    void updateMap();
    void goToLongLat(double longit, double latit);

    //télécharge la zone selectionnee au niveau de zoom 'zoomLevel'
    void downloadSelection(int zoomLevel, bool split=false, int maxWidth=768, int maxHeight=768);
    void saveCache(QString directory) {geoEngine->saveCachedTilesToDir(directory);}

private:
    //QList<Tile*> tiles;
    GeoEngine* geoEngine;

    QPoint center;      // les coordonnes du centre dans le referentiel carte
    int zoomLevel;
    Couche couche;
    QRect tilesRect;    // le rectangles des tuiles en numeros

    QPoint convertScreenToMapNum(QPoint pos);
    QPoint convertScreenToMapXY(QPoint pos);
    QRect convertScreenToMapXY(QRect rect);
    QPoint convertMapToScreenXY(QPoint pos);

    void saveCalibrationToFile(QString filename,QRect mapXYRect, QSize mapSize);

    Overlay* selectionOverlay;
    QList<Tile*> tiles;

    QMap<int,Tile*> downIds;
    QMap<int,QPoint> toSavePositions;
    //int nbTilesToDown;

    QProgressBar progressBar;

    QVector<QPixmap> savedMap;
    QVector<QRect> mapRect;
    QVector<QPoint> mapPos;   //position de la petite partie de carte dans la carte globale
    int nbXMaps;
    int nbYMaps;

    bool moving;
    bool selecting;
    bool splitMaps;

    int mapsMaxWidth;
    int mapsMaxHeight;

    QPoint originalPos;
    QPoint startingPos;

    QRect downloadedXYRect;

    QPoint firstCorner, secondCorner; // selection
protected:
    virtual void mousePressEvent ( QMouseEvent * event );
    virtual void mouseMoveEvent ( QMouseEvent * event );
    virtual void mouseReleaseEvent ( QMouseEvent * event );
    virtual void resizeEvent(QResizeEvent *);
    virtual void wheelEvent(QWheelEvent *);
    //virtual void paintEvent(QPaintEvent *);
};

#endif // MAPWIDGET_H
