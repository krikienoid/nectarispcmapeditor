#include "pixmaptertiles.h"

namespace App {

PixmapTerTiles::PixmapTerTiles(QWidget* parent) : QWidget(parent) {
    terTileset = new QPixmap(":/data/images/terraintiles.png");
}

PixmapTerTiles::~PixmapTerTiles() {
    delete terTileset;
}

QPixmap PixmapTerTiles::getTerTile(int i) const {
    if (i >= TILE_MAX) {
        i = 0;
    }

    return terTileset->copy(
        (i % TILESET_COLUMNS) * TILE_WIDTH,
        (i / TILESET_COLUMNS) * TILE_HEIGHT,
        TILE_WIDTH,
        TILE_HEIGHT
    );
}

} // namespace App
