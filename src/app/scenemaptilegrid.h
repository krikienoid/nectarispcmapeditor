#ifndef NECMAPEDIT_SCENEMAPTILEGRID_H
#define NECMAPEDIT_SCENEMAPTILEGRID_H

// Dependencies

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QList>
#include "pixmaptertiles.h"
#include "mapinfo.h"
#include "mapmap.h"

#include <QDebug>

// Class

class SceneMapTileGrid : public QGraphicsScene {
    Q_OBJECT

public:

    explicit SceneMapTileGrid  (QWidget * parent = 0);

    void     mousePressEvent   (QGraphicsSceneMouseEvent *);

    // Methods
    void     loadNecData       (Nec::MapInfo *, Nec::MapMap *);
    void     updateNecData     ();
    void     setMapGridVisible (const bool);

    // Static Constants
    static const int TILE_WIDTH      = 16;
    static const int TILE_HEIGHT     = 16;
    static const int TILESET_COLUMNS = 16;
    static const int TILESET_ROWS    = 144;

    // Children
    PixmapTerTiles * pixmapTerTiles;

signals:

    void selectedMapTile (int);

public slots:

private:

    // Methods
    void updateTerTiles  ();
    void updateGridTiles ();

    // Children
    QList<QGraphicsPixmapItem *> listTerTiles;
    QList<QGraphicsPixmapItem *> listGridTiles;

    // Data
    bool           isMapGridVisible;

    // Nec Data
    Nec::MapInfo * necMapInfo;
    Nec::MapMap  * necMapMap;

};

#endif // NECMAPEDIT_SCENEMAPTILEGRID_H
