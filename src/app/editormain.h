#ifndef NECMAPEDIT_EDITORMAIN_H
#define NECMAPEDIT_EDITORMAIN_H

// Dependencies

#include <QWidget>
#include <QTabWidget>
#include <QSplitter>
#include "editormapinfo.h"
#include "pickermapinfo.h"
#include "editormapmap.h"
#include "editorplayers.h"
#include "datamanager.h"
#include "tertype.h"

// Class

class EditorMain : public QWidget {
    Q_OBJECT

public:

    explicit EditorMain    (QWidget * parent = 0);

    // Methods
    void     loadNecData   (Nec::DataManager *);
    void     updateNecData ();
    void     zoomMap       (const double, const bool);

public slots:

    void selectMapInfo (int);
    void signalUpdate  ();

    void zoomMapFull () {zoomMap(1.0, false);}
    void zoomMapIn   () {zoomMap(2.0, true);}
    void zoomMapOut  () {zoomMap(0.5, true);}
    void toggleMapGrid (bool mapGridOn) {editorMapMap->setMapGridVisible(mapGridOn);}

private:

    // Methods
    void loadSelectedMapData (const std::size_t);

    // Children
    EditorMapInfo * editorMapInfo;
    PickerMapInfo * pickerMapInfo;
    EditorMapMap  * editorMapMap;
    EditorPlayers * editorPlayers;

    // Nec Data
    Nec::DataManager * necData;

};

#endif // NECMAPEDIT_EDITORMAIN_H
