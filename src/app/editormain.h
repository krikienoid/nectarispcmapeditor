#ifndef APP_EDITORMAIN_H
#define APP_EDITORMAIN_H

#include <QHBoxLayout>
#include <QSplitter>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/datamanager.h"
#include "nec/tertype.h"
#include "editormapinfo.h"
#include "editormapmap.h"
#include "editorplayers.h"
#include "pickermapinfo.h"

namespace App {

class EditorMain : public QWidget {
    Q_OBJECT

public:
    explicit                    EditorMain(QWidget* parent = nullptr);

    void                        loadNecData(Nec::DataManager*);
    void                        updateNecData();
    void                        zoomMap(double, bool);

public slots:
    void                        selectMapInfo(int);
    void                        signalUpdate();

    void                        zoomMapFull();
    void                        zoomMapIn();
    void                        zoomMapOut();
    void                        toggleMapGrid(bool);

private:
    void                        loadSelectedMapData(int);

    EditorMapInfo*              editorMapInfo;
    PickerMapInfo*              pickerMapInfo;
    EditorMapMap*               editorMapMap;
    EditorPlayers*              editorPlayers;

    Nec::DataManager*           necData;
};

} // namespace App

#endif // APP_EDITORMAIN_H
