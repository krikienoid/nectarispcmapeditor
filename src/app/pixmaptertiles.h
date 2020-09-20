#ifndef APP_PIXMAPTERTILES_H
#define APP_PIXMAPTERTILES_H

#include <QPixmap>
#include <QWidget>

namespace App {

class PixmapTerTiles : public QWidget {
    Q_OBJECT

public:
    explicit                    PixmapTerTiles(QWidget* parent = 0);
                                ~PixmapTerTiles();

    QPixmap                     getTerTile(int) const;

    static const int            TILE_WIDTH      = 16;
    static const int            TILE_HEIGHT     = 16;
    static const int            TILESET_COLUMNS = 16;
    static const int            TILESET_ROWS    = 144;
    static const int            TILE_MAX        = 0x480;

private:
    QPixmap*                    terTileset;
};

} // namespace App

#endif // APP_PIXMAPTERTILES_H
