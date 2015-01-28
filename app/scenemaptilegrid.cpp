#include "scenemaptilegrid.h"

// Constructors

SceneMapTileGrid::SceneMapTileGrid (QWidget * parent) : QGraphicsScene(parent) {

    // Init tileset
    pixmapTerTiles = new PixmapTerTiles(parent);

    // Grid Square template
    QPixmap gridSquare(16, 16);
    gridSquare.fill(QColor("transparent"));
    QPainter painter(&gridSquare);
    painter.drawRect(0, 0, 16, 16);

    // Build terrain tile graphics
    int maxWidth = Nec::MapMap::getWidth(4);
    for (int i = 0, ii = Nec::MapMap::getSize(4, 4); i < ii; ++i) {
        int x        = i % maxWidth;
        int y        = i / maxWidth;
        int shift    = (x % 2)? TILE_HEIGHT / 2 : 0;
        int pX       = x * TILE_WIDTH;
        int pY       = y * TILE_HEIGHT + shift;
        int tileType = 0;

        // Tile
        QGraphicsPixmapItem * terTile = addPixmap(pixmapTerTiles->getTerTile(tileType));
        terTile->setPos(pX, pY);
        terTile->setData(0, QVariant(i));
        listTerTiles.append(terTile);

        // Grid Tile
        QGraphicsPixmapItem * gridTile = addPixmap(gridSquare);
        gridTile->setPos(pX, pY);
        listGridTiles.append(gridTile);
    }

}

// Methods

void SceneMapTileGrid::mousePressEvent  (QGraphicsSceneMouseEvent * event) {
    emit selectedMapTile(itemAt(event->scenePos(), QTransform())->data(0).toInt());
}

void SceneMapTileGrid::loadNecData (Nec::MapInfo * newNecMapInfo, Nec::MapMap * newNecMapMap) {
    necMapMap  = newNecMapMap;
    necMapInfo = newNecMapInfo;
}

void SceneMapTileGrid::updateNecData () {
    updateTerTiles();
    updateGridTiles();
}

void SceneMapTileGrid::setMapGridVisible (const bool mapGridOn) {
    isMapGridVisible = mapGridOn;
    updateGridTiles();
}

// Private Methods

void SceneMapTileGrid::updateTerTiles () {
    int maxWidth  = Nec::MapMap::getWidth (4);
    int width     = Nec::MapMap::getWidth (necMapInfo->quadrantsX + 1);
    int height    = Nec::MapMap::getHeight(necMapInfo->quadrantsY + 1);

    for (int i = 0, ii = listTerTiles.size(); i < ii; ++i) {
        int x = i % maxWidth;
        int y = i / maxWidth;
        int tileType = 0;
        if (x < width && y < height && i < int(necMapMap->size())) {
            listTerTiles[i]->setVisible(true);
            listTerTiles[i]->setData(0, QVariant(i));
            tileType = necMapMap->at(i).toInt();
        }
        else {
            listTerTiles[i]->setVisible(false);
            listTerTiles[i]->setData(0, QVariant(0xffff));
        }
        listTerTiles[i]->setPixmap(pixmapTerTiles->getTerTile(tileType));
    }
}

void SceneMapTileGrid::updateGridTiles () {
    int maxWidth  = Nec::MapMap::getWidth (4);
    int width     = Nec::MapMap::getWidth (necMapInfo->quadrantsX + 1);
    int height    = Nec::MapMap::getHeight(necMapInfo->quadrantsY + 1);

    for (int i = 0, ii = listGridTiles.size(); i < ii; ++i) {
        int x = i % maxWidth;
        int y = i / maxWidth;
        listGridTiles[i]->setVisible(isMapGridVisible && x < width && y < height);
    }
}
