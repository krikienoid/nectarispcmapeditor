#include "levelmapscene.h"

namespace App {

LevelMapScene::LevelMapScene(QWidget* const parent) : QGraphicsScene(parent) {
    // Init tileset.
    terTilesPixmap = new TerTilesPixmap(parent);

    // Init grid square.
    QPixmap gridSquare(16, 16);
    gridSquare.fill(QColor("transparent"));

    QPainter painter(&gridSquare);
    painter.drawRect(0, 0, 16, 16);

    // Init tiles.
    constexpr int maxWidth = static_cast<int>(Nec::MapSize::maxWidth);

    for (int i = 0, ii = static_cast<int>(Nec::MapSize::maxSize); i < ii; ++i) {
        const auto x        = i % maxWidth;
        const auto y        = i / maxWidth;
        const auto offsetY  = (x % 2) ? Constants::tileHeight / 2 : 0;
        const auto posX     = x * Constants::tileWidth;
        const auto posY     = y * Constants::tileHeight + offsetY;

        const auto terTile = addPixmap(terTilesPixmap->getTerTile(0));
        terTile->setPos(posX, posY);
        terTile->setData(MapCellIndexDataRole, QVariant(i));

        terTiles.append(terTile);

        const auto gridTile = addPixmap(gridSquare);
        gridTile->setPos(posX, posY);

        gridTiles.append(gridTile);
    }
}

void LevelMapScene::mousePressEvent(QGraphicsSceneMouseEvent* const event) {
    const auto terTile = itemAt(event->scenePos(), QTransform());

    if (terTile) {
        emit selectedMapCell(terTile->data(MapCellIndexDataRole).toInt());
    }
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
    if (targetLevelMap->items.size() == 0) {
        // Exit if LevelMap is not initialized.
        return;
    }

    constexpr int maxWidth = static_cast<int>(Nec::MapSize::maxWidth);
    const auto width  =
        Nec::MapSize::getWidth(targetLevelInfo->chunkCountX.getValue() + 1);
    const auto height =
        Nec::MapSize::getHeight(targetLevelInfo->chunkCountY.getValue() + 1);

    for (int i = 0, ii = terTiles.size(); i < ii; ++i) {
        const auto x = i % maxWidth;
        const auto y = i / maxWidth;
        int terIndex = 0;

        const auto terTile = terTiles[i];

        if (
            Nec::MapSize::isInBounds(static_cast<std::size_t>(i), width, height)
        ) {
            terIndex = targetLevelMap->items[static_cast<std::size_t>(i)]
                .getValue();

            terTile->setVisible(true);

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
        }

        terTile->setPixmap(terTilesPixmap->getTerTile(terIndex));
    }
}

void LevelMapScene::updateGridTiles() {
    const auto width  =
        Nec::MapSize::getWidth(targetLevelInfo->chunkCountX.getValue() + 1);
    const auto height =
        Nec::MapSize::getHeight(targetLevelInfo->chunkCountY.getValue() + 1);

    for (int i = 0, ii = gridTiles.size(); i < ii; ++i) {
        gridTiles[i]->setVisible(
            isMapGridVisible &&
            Nec::MapSize::isInBounds(static_cast<std::size_t>(i), width, height)
        );
    }
}

} // namespace App
