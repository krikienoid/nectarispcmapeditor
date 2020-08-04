#ifndef APP_PIXMAPTERTILES_H
#define APP_PIXMAPTERTILES_H

// Dependencies

#include <QPixmap>
#include <QWidget>

namespace App {

// Class

class PixmapTerTiles : public QWidget {
    Q_OBJECT

public:

    explicit PixmapTerTiles (QWidget * parent = 0);
            ~PixmapTerTiles ();

    // Methods
    QPixmap  getTerTile     (int) const;

    // Static Constants
    static const int TILE_WIDTH      = 16;
    static const int TILE_HEIGHT     = 16;
    static const int TILESET_COLUMNS = 16;
    static const int TILESET_ROWS    = 144;
    static const int TILE_MAX        = 0x480;

private:

    // Children
    QPixmap * terTileset;

};

} // namespace App

#endif // APP_PIXMAPTERTILES_H
