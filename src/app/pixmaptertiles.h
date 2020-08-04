#ifndef NECMAPEDIT_PIXMAPTERTILES_H
#define NECMAPEDIT_PIXMAPTERTILES_H

// Dependencies

#include <QPixmap>
#include <QWidget>

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

#endif // NECMAPEDIT_PIXMAPTERTILES_H
