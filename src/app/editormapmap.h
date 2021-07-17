#ifndef APP_EDITORMAPMAP_H
#define APP_EDITORMAPMAP_H

#include <QCheckBox>
#include <QComboBox>
#include <QFrame>
#include <QGraphicsView>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QList>
#include <QScrollBar>
#include <QSignalMapper>
#include <QString>
#include <QTransform>
#include <QVBoxLayout>
#include <QWidget>

#include "raw/byte.h"
#include "raw/bytestring.h"
#include "nec/mapinfo.h"
#include "nec/mapmap.h"
#include "nec/mapsize.h"
#include "nec/tertype.h"
#include "pickertertile.h"
#include "pixmaptertiles.h"
#include "scenemaptilegrid.h"

namespace App {

class EditorMapMap : public QWidget {
    Q_OBJECT

public:
    explicit                    EditorMapMap(QWidget* parent = nullptr);

    void                        loadNecData(Nec::MapInfo*, Nec::MapMap*);
    void                        updateNecData();
    void                        zoomMap(double, bool);
    void                        setMapGridVisible(bool);

    QGraphicsView*              viewMapTileGrid;

public slots:
    void                        selectTerTile(int);
    void                        selectMapTile(int);
    void                        changeTilesetRange();
    void                        changeMapSizeX(int);
    void                        changeMapSizeY(int);

private:
    enum class                  ToolMode { TOOL_TER };

    static constexpr int        TILESETS = 9;

    void                        updateSelectedTerTile(int);
    void                        updateEnabledTilesetRange();
    bool                        hasTilesetEnabled(int);

    void                        createViewMapTileGrid();
    void                        createTilesetRangePicker();
    void                        createPickerTerTile();
    void                        createMapSizePicker();

    SceneMapTileGrid*           sceneMapTileGrid;
    PickerTerTile*              pickerTerTile;
    QLabel*                     labelTerTileImg;
    QLabel*                     labelTerTileName;
    QGroupBox*                  groupChecks;
    QGroupBox*                  groupMapSize;
    QGroupBox*                  groupTerTile;
    QList<QCheckBox*>           checksTilesetRange;
    QComboBox*                  comboMapSizeX;
    QComboBox*                  comboMapSizeY;

    ToolMode                    toolMode;
    int                         selectedTerTile;

    Nec::MapInfo*               necMapInfo;
    Nec::MapMap*                necMapMap;
};

} // namespace App

#endif // APP_EDITORMAPMAP_H
