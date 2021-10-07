#include "tertilespixmap.h"

namespace App {

TerTilesPixmap::TerTilesPixmap(QWidget* const parent) : QWidget(parent) {
    pixmap = new QPixmap(":/data/images/terraintiles.png");
}

TerTilesPixmap::~TerTilesPixmap() {
    delete pixmap;
}

QPixmap TerTilesPixmap::getTerTile(int i) const {
    if (i >= tileCount) {
        i = 0;
    }

    return pixmap->copy(
        (i % tilesetColCount) * tileWidth,
        (i / tilesetColCount) * tileHeight,
        tileWidth,
        tileHeight
    );
}

} // namespace App
