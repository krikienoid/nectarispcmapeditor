#include "scenemaptilegrid.h"

namespace App {

SceneMapTileGrid::SceneMapTileGrid(QWidget* const parent) :
    QGraphicsScene(parent)
{
    // Init tileset
    pixmapTerTiles = new PixmapTerTiles(parent);

    // Grid Square template
    QPixmap gridSquare(16, 16);
    gridSquare.fill(QColor("transparent"));

    QPainter painter(&gridSquare);
    painter.drawRect(0, 0, 16, 16);

    // Build terrain tile graphics
    const int maxWidth = Nec::MapMap::getWidth(4);

    for (int i = 0, ii = Nec::MapMap::getSize(4, 4); i < ii; ++i) {
        const int x        = i % maxWidth;
        const int y        = i / maxWidth;
        const int shift    = (x % 2) ? TILE_HEIGHT / 2 : 0;
        const int pX       = x * TILE_WIDTH;
        const int pY       = y * TILE_HEIGHT + shift;
        const int tileType = 0;

        // Tile
        const auto terTile = addPixmap(pixmapTerTiles->getTerTile(tileType));
        terTile->setPos(pX, pY);
        terTile->setData(0, QVariant(i));

        listTerTiles.append(terTile);

        // Grid Tile
        const auto gridTile = addPixmap(gridSquare);
        gridTile->setPos(pX, pY);

        listGridTiles.append(gridTile);
    }
}

void SceneMapTileGrid::mousePressEvent(QGraphicsSceneMouseEvent* const event) {
    emit selectedMapTile(itemAt(
        event->scenePos(),
        QTransform()
    )->data(0).toInt());
}

void SceneMapTileGrid::loadNecData(
    const Nec::MapInfo* const newNecMapInfo,
    const Nec::MapMap* const newNecMapMap
) {
    necMapMap  = newNecMapMap;
    necMapInfo = newNecMapInfo;
}

void SceneMapTileGrid::updateNecData() {
    updateTerTiles();
    updateGridTiles();
}

void SceneMapTileGrid::setMapGridVisible(const bool mapGridOn) {
    isMapGridVisible = mapGridOn;

    updateGridTiles();
}

void SceneMapTileGrid::updateTerTiles() {
    const int maxWidth  = Nec::MapMap::getWidth(4);
    const int width     = Nec::MapMap::getWidth(necMapInfo->quadrantsX + 1);
    const int height    = Nec::MapMap::getHeight(necMapInfo->quadrantsY + 1);

    for (int i = 0, ii = listTerTiles.size(); i < ii; ++i) {
        const int x = i % maxWidth;
        const int y = i / maxWidth;
        int tileType = 0;

        if (x < width && y < height && i < int(necMapMap->size())) {
            listTerTiles[i]->setVisible(true);
            listTerTiles[i]->setData(0, QVariant(i));
            tileType = necMapMap->at(i).toInt();
        } else {
            listTerTiles[i]->setVisible(false);
            listTerTiles[i]->setData(0, QVariant(0xffff));
        }

        listTerTiles[i]->setPixmap(pixmapTerTiles->getTerTile(tileType));
    }
}

void SceneMapTileGrid::updateGridTiles() {
    const int maxWidth  = Nec::MapMap::getWidth(4);
    const int width     = Nec::MapMap::getWidth(necMapInfo->quadrantsX + 1);
    const int height    = Nec::MapMap::getHeight(necMapInfo->quadrantsY + 1);

    for (int i = 0, ii = listGridTiles.size(); i < ii; ++i) {
        const int x = i % maxWidth;
        const int y = i / maxWidth;

        listGridTiles[i]->setVisible(
            isMapGridVisible && x < width && y < height
        );
    }
}

} // namespace App
