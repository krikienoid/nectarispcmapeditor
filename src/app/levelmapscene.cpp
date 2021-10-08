#include "levelmapscene.h"

namespace App {

LevelMapScene::LevelMapScene(QWidget* const parent) : QGraphicsScene(parent) {
    // Init tileset
    terTilesPixmap = new TerTilesPixmap(parent);

    // Grid Square template
    QPixmap gridSquare(16, 16);
    gridSquare.fill(QColor("transparent"));

    QPainter painter(&gridSquare);
    painter.drawRect(0, 0, 16, 16);

    // Build terrain tile graphics
    constexpr int maxWidth = static_cast<int>(Nec::MapSize::getWidth(4));
    constexpr int mapSize  = static_cast<int>(Nec::MapSize::maxSize);

    for (int i = 0, ii = mapSize; i < ii; ++i) {
        const auto x        = i % maxWidth;
        const auto y        = i / maxWidth;
        const auto offsetY  = (x % 2) ? Constants::tileHeight / 2 : 0;
        const auto posX     = x * Constants::tileWidth;
        const auto posY     = y * Constants::tileHeight + offsetY;
        const int terIndex  = 0;

        // Tile
        const auto terTile = addPixmap(terTilesPixmap->getTerTile(terIndex));
        terTile->setPos(posX, posY);
        terTile->setData(0, QVariant(i));

        terTiles.append(terTile);

        // Grid Tile
        const auto gridTile = addPixmap(gridSquare);
        gridTile->setPos(posX, posY);

        gridTiles.append(gridTile);
    }
}

void LevelMapScene::mousePressEvent(QGraphicsSceneMouseEvent* const event) {
    emit selectedMapCell(
        itemAt(event->scenePos(), QTransform())->data(0).toInt()
    );
}

void LevelMapScene::setTargetData(
    const Nec::LevelInfo* const levelInfo,
    const Nec::LevelMap* const levelMap
) {
    targetLevelMap  = levelMap;
    targetLevelInfo = levelInfo;
}

void LevelMapScene::updateState() {
    updateTerTiles();
    updateGridTiles();
}

void LevelMapScene::setMapGridVisible(const bool isOn) {
    isMapGridVisible = isOn;

    updateGridTiles();
}

void LevelMapScene::updateTerTiles() {
    constexpr int maxWidth = static_cast<int>(Nec::MapSize::getWidth(4));
    const int width        = static_cast<int>(
        Nec::MapSize::getWidth(targetLevelInfo->chunkCountX.value() + 1)
    );
    const int height       = static_cast<int>(
        Nec::MapSize::getHeight(targetLevelInfo->chunkCountY.value() + 1)
    );
    const int mapSize      = static_cast<int>(targetLevelMap->items.size());

    for (int i = 0, ii = terTiles.size(); i < ii; ++i) {
        const auto x = i % maxWidth;
        const auto y = i / maxWidth;
        int terIndex = 0;

        const auto terTile = terTiles[i];

        if (x < width && y < height && i < mapSize) {
            terIndex = targetLevelMap->items[static_cast<std::size_t>(i)].toInt();

            terTile->setVisible(true);
            terTile->setData(0, QVariant(i));

            terTile->setToolTip(
                QString("(") +
                QString::number(x) +
                QString(", ") +
                QString::number(y) +
                QString(")\n") +
                QString(tr("Ter: ")) +
                QString::number(terIndex)
            );
        } else {
            terTile->setVisible(false);
            terTile->setData(0, QVariant(0xffff));
        }

        terTile->setPixmap(terTilesPixmap->getTerTile(terIndex));
    }
}

void LevelMapScene::updateGridTiles() {
    constexpr int maxWidth = static_cast<int>(Nec::MapSize::getWidth(4));
    const int width        = static_cast<int>(
        Nec::MapSize::getWidth(targetLevelInfo->chunkCountX.value() + 1)
    );
    const int height       = static_cast<int>(
        Nec::MapSize::getHeight(targetLevelInfo->chunkCountY.value() + 1)
    );

    for (int i = 0, ii = gridTiles.size(); i < ii; ++i) {
        const auto x = i % maxWidth;
        const auto y = i / maxWidth;

        gridTiles[i]->setVisible(
            isMapGridVisible && x < width && y < height
        );
    }
}

} // namespace App
