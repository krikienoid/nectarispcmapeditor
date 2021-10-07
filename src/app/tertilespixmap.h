#ifndef APP_TERTILESPIXMAP_H
#define APP_TERTILESPIXMAP_H

#include <QPixmap>
#include <QWidget>

namespace App {

class TerTilesPixmap : public QWidget {
    Q_OBJECT

public:
    static constexpr int        tileWidth       = 16;
    static constexpr int        tileHeight      = 16;
    static constexpr int        tilesetColCount = 16;
    static constexpr int        tilesetRowCount = 144;
    static constexpr int        tileCount       = 0x480;

    explicit                    TerTilesPixmap(QWidget* parent = nullptr);
                                ~TerTilesPixmap();

    QPixmap                     getTerTile(int) const;

private:
    QPixmap*                    pixmap;
};

} // namespace App

#endif // APP_TERTILESPIXMAP_H
