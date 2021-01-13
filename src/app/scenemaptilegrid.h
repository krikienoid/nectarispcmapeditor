#ifndef APP_SCENEMAPTILEGRID_H
#define APP_SCENEMAPTILEGRID_H

#include <QColor>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QPainter>
#include <QPixmap>
#include <QTransform>
#include <QVariant>
#include <QWidget>

#include "nec/mapinfo.h"
#include "nec/mapmap.h"
#include "pixmaptertiles.h"

namespace App {

class SceneMapTileGrid : public QGraphicsScene {
    Q_OBJECT

public:
    explicit                    SceneMapTileGrid(QWidget* parent = nullptr);

    void                        mousePressEvent(QGraphicsSceneMouseEvent*);

    void                        loadNecData(Nec::MapInfo*, Nec::MapMap*);
    void                        updateNecData();
    void                        setMapGridVisible(const bool);

    static const int            TILE_WIDTH      = 16;
    static const int            TILE_HEIGHT     = 16;
    static const int            TILESET_COLUMNS = 16;
    static const int            TILESET_ROWS    = 144;

    PixmapTerTiles*             pixmapTerTiles;

signals:
    void                        selectedMapTile(int);

private:
    void                        updateTerTiles();
    void                        updateGridTiles();

    QList<QGraphicsPixmapItem*> listTerTiles;
    QList<QGraphicsPixmapItem*> listGridTiles;

    bool                        isMapGridVisible;

    Nec::MapInfo*               necMapInfo;
    Nec::MapMap*                necMapMap;
};

} // namespace App

#endif // APP_SCENEMAPTILEGRID_H
