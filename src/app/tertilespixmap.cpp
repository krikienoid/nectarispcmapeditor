#include "tertilespixmap.h"

namespace App {

TerTilesPixmap::TerTilesPixmap(QWidget* const parent) : QWidget(parent) {
    pixmap = new QPixmap(":/data/images/terraintiles.png");
}

TerTilesPixmap::~TerTilesPixmap() {
    delete pixmap;
}

QPixmap TerTilesPixmap::getTerTile(int i) const {
    if (i >= Constants::tileCount) {
        i = 0;
    }

    return pixmap->copy(
        (i % Constants::tilesetColCount) * Constants::tileWidth,
        (i / Constants::tilesetColCount) * Constants::tileHeight,
        Constants::tileWidth,
        Constants::tileHeight
    );
}

} // namespace App
