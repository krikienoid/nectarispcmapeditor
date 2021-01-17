#ifndef APP_PIXMAPTERTILES_H
#define APP_PIXMAPTERTILES_H

#include <QPixmap>
#include <QWidget>

namespace App {

class PixmapTerTiles : public QWidget {
    Q_OBJECT

public:
    static constexpr int        TILE_WIDTH      = 16;
    static constexpr int        TILE_HEIGHT     = 16;
    static constexpr int        TILESET_COLUMNS = 16;
    static constexpr int        TILESET_ROWS    = 144;
    static constexpr int        TILE_MAX        = 0x480;

    explicit                    PixmapTerTiles(QWidget* parent = nullptr);
                                ~PixmapTerTiles();

    QPixmap                     getTerTile(int) const;

private:
    QPixmap*                    terTileset;
};

} // namespace App

#endif // APP_PIXMAPTERTILES_H
