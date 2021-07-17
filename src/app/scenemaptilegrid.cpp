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
    constexpr int maxWidth = static_cast<int>(Nec::MapSize::getWidth(4));
    constexpr int mapSize  = static_cast<int>(Nec::MapSize::MAX_SIZE);

    for (int i = 0, ii = mapSize; i < ii; ++i) {
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
    constexpr int maxWidth = static_cast<int>(Nec::MapSize::getWidth(4));
    const int width        = static_cast<int>(
        Nec::MapSize::getWidth(necMapInfo->quadrantsX.value() + 1)
    );
    const int height       = static_cast<int>(
        Nec::MapSize::getHeight(necMapInfo->quadrantsY.value() + 1)
    );
    const int mapSize      = static_cast<int>(necMapMap->size());

    for (int i = 0, ii = listTerTiles.size(); i < ii; ++i) {
        const int x = i % maxWidth;
        const int y = i / maxWidth;
        int tileType = 0;

        if (x < width && y < height && i < mapSize) {
            listTerTiles[i]->setVisible(true);
            listTerTiles[i]->setData(0, QVariant(i));
            tileType = necMapMap->at(static_cast<std::size_t>(i)).toInt();
        } else {
            listTerTiles[i]->setVisible(false);
            listTerTiles[i]->setData(0, QVariant(0xffff));
        }

        listTerTiles[i]->setPixmap(pixmapTerTiles->getTerTile(tileType));
    }
}

void SceneMapTileGrid::updateGridTiles() {
    constexpr int maxWidth = static_cast<int>(Nec::MapSize::getWidth(4));
    const int width        = static_cast<int>(
        Nec::MapSize::getWidth(necMapInfo->quadrantsX.value() + 1)
    );
    const int height       = static_cast<int>(
        Nec::MapSize::getHeight(necMapInfo->quadrantsY.value() + 1)
    );

    for (int i = 0, ii = listGridTiles.size(); i < ii; ++i) {
        const int x = i % maxWidth;
        const int y = i / maxWidth;

        listGridTiles[i]->setVisible(
            isMapGridVisible && x < width && y < height
        );
    }
}

} // namespace App
