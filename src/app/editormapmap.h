#ifndef NECMAPEDIT_EDITORMAPMAP_H
#define NECMAPEDIT_EDITORMAPMAP_H

// Dependencies

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

#include "raw/bytestring.h"
#include "nec/mapinfo.h"
#include "nec/mapmap.h"
#include "nec/tertype.h"
#include "pickertertile.h"
#include "pixmaptertiles.h"
#include "scenemaptilegrid.h"


// Class

class EditorMapMap : public QWidget {
    Q_OBJECT

public:

    explicit EditorMapMap       (QWidget * parent = 0);

    // Methods
    void     loadNecData        (Nec::MapInfo *, Nec::MapMap *);
    void     updateNecData      ();
    void     zoomMap            (const double, const bool);
    void     setMapGridVisible  (const bool);

    // Children
    QGraphicsView    * viewMapTileGrid;

public slots:

    void     selectTerTile      (int);
    void     selectMapTile      (int);
    void     changeTilesetRange (int);
    void     changeMapSizeX     (int);
    void     changeMapSizeY     (int);

private:

    // Enums
    enum ToolMode {TOOL_TER};

    // Static Consts
    static const int TILESETS = 9;

    // Methods
    void updateSelectedTerTile     (int);
    void updateEnabledTilesetRange ();
    bool hasTilesetEnabled         (int);

    void createViewMapTileGrid     ();
    void createTilesetRangePicker  ();
    void createPickerTerTile       ();
    void createMapSizePicker       ();

    // Children
    SceneMapTileGrid * sceneMapTileGrid;
    PickerTerTile    * pickerTerTile;
    QLabel           * labelTerTileImg;
    QLabel           * labelTerTileName;
    QGroupBox        * groupChecks;
    QGroupBox        * groupMapSize;
    QGroupBox        * groupTerTile;
    QList<QCheckBox *> checksTilesetRange;
    QComboBox        * comboMapSizeX;
    QComboBox        * comboMapSizeY;

    // Data
    ToolMode           toolMode;
    int                selectedTerTile;

    // Nec Data
    Nec::MapInfo     * necMapInfo;
    Nec::MapMap      * necMapMap;

};

#endif // NECMAPEDIT_EDITORMAPMAP_H
