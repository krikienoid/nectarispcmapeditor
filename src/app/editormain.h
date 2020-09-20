#ifndef APP_EDITORMAIN_H
#define APP_EDITORMAIN_H

#include <QHBoxLayout>
#include <QSplitter>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/datamanager.h"
#include "nec/mapinfo.h"
#include "nec/mapmap.h"
#include "nec/tertype.h"
#include "editormapinfo.h"
#include "editormapmap.h"
#include "editorplayers.h"
#include "pickermapinfo.h"

namespace App {

class EditorMain : public QWidget {
    Q_OBJECT

public:
    explicit                    EditorMain(QWidget* parent = 0);

    void                        loadNecData(Nec::DataManager*);
    void                        updateNecData();
    void                        zoomMap(const double, const bool);

public slots:
    void                        selectMapInfo(int);
    void                        signalUpdate();

    void                        zoomMapFull() { zoomMap(1.0, false); }
    void                        zoomMapIn() { zoomMap(2.0, true); }
    void                        zoomMapOut() { zoomMap(0.5, true); }
    void                        toggleMapGrid(bool mapGridOn) {
                                    editorMapMap->setMapGridVisible(mapGridOn);
                                }

private:
    void                        loadSelectedMapData(const std::size_t);

    EditorMapInfo*              editorMapInfo;
    PickerMapInfo*              pickerMapInfo;
    EditorMapMap*               editorMapMap;
    EditorPlayers*              editorPlayers;

    Nec::DataManager*           necData;
};

} // namespace App

#endif // APP_EDITORMAIN_H
