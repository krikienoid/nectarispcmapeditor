#ifndef APP_TERTILESPIXMAP_H
#define APP_TERTILESPIXMAP_H

#include <QPixmap>
#include <QWidget>

#include "constants.h"

namespace App {

class TerTilesPixmap : public QWidget {
    Q_OBJECT

public:
    explicit                    TerTilesPixmap(QWidget* parent = nullptr);
                                ~TerTilesPixmap();

    QPixmap                     getTerTile(int) const;

private:
    QPixmap*                    pixmap;
};

} // namespace App

#endif // APP_TERTILESPIXMAP_H
