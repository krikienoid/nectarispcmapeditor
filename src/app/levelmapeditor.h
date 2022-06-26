#ifndef APP_LEVELMAPEDITOR_H
#define APP_LEVELMAPEDITOR_H

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

#include "nec/levelinfo.h"
#include "nec/levelmap.h"
#include "nec/mapsize.h"
#include "nec/tertype.h"
#include "constants.h"
#include "levelmapscene.h"
#include "terselector.h"

namespace App {

class LevelMapEditor : public QWidget {
    Q_OBJECT

public:
    explicit                    LevelMapEditor(QWidget* parent = nullptr);

    void                        setTargetData(Nec::LevelInfo*, Nec::LevelMap*);
    void                        updateState();
    void                        zoomMap(double, bool);
    void                        setMapGridVisible(bool);

    QGraphicsView*              mapView;

public slots:
    void                        selectTer(int);
    void                        selectMapCell(int);
    void                        editActiveTilesets();
    void                        editChunkCountX(int);
    void                        editChunkCountY(int);

private:
    enum class                  ToolMode { Ter };

    void                        updateSelectedTer(int);
    void                        updateActiveTilesets();
    bool                        hasActiveTileset(int);

    void                        initMapView();
    void                        initTilesetSelector();
    void                        initTerSelector();
    void                        initMapSizeSelector();

    LevelMapScene*              levelMapScene;
    TerSelector*                terSelector;
    QLabel*                     selectedTerImageLabel;
    QLabel*                     selectedTerTypeNameLabel;
    QGroupBox*                  tilesetSelectorGroupBox;
    QGroupBox*                  mapSizeGroupBox;
    QGroupBox*                  terSelectorGroupBox;
    QList<QCheckBox*>           tilesetCheckBoxes;
    QComboBox*                  chunkCountXComboBox;
    QComboBox*                  chunkCountYComboBox;

    ToolMode                    toolMode;
    int                         selectedTer;

    Nec::LevelInfo*             targetLevelInfo;
    Nec::LevelMap*              targetLevelMap;
};

} // namespace App

#endif // APP_LEVELMAPEDITOR_H
