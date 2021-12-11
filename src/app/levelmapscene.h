#ifndef APP_LEVELMAPSCENE_H
#define APP_LEVELMAPSCENE_H

#include <QColor>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QPainter>
#include <QPixmap>
#include <QString>
#include <QTransform>
#include <QVariant>
#include <QWidget>

#include "nec/levelinfo.h"
#include "nec/levelmap.h"
#include "nec/mapsize.h"
#include "constants.h"
#include "tertilespixmap.h"

namespace App {

class LevelMapScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit                    LevelMapScene(QWidget* parent = nullptr);

    void                        mousePressEvent(QGraphicsSceneMouseEvent*);

    void                        setTargetData(
                                    const Nec::LevelInfo*,
                                    const Nec::LevelMap*
                                );
    void                        updateState();
    void                        setMapGridVisible(bool);

    TerTilesPixmap*             terTilesPixmap;

signals:
    void                        selectedMapCell(int);

private:
    enum DataRole {
        MapCellIndexDataRole    = Qt::UserRole + 1
    };

    void                        updateTerTiles();
    void                        updateGridTiles();

    QList<QGraphicsPixmapItem*> terTiles;
    QList<QGraphicsPixmapItem*> gridTiles;

    bool                        isMapGridVisible;

    const Nec::LevelInfo*       targetLevelInfo;
    const Nec::LevelMap*        targetLevelMap;
};

} // namespace App

#endif // APP_LEVELMAPSCENE_H
