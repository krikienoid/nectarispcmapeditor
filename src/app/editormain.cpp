#include "editormain.h"

namespace App {

EditorMain::EditorMain(QWidget* const parent) : QWidget(parent) {
    // Init Nec Data
    Nec::initTerTypeData();

    // Init Children Widgets

    // MapInfo Editor
    editorMapInfo = new EditorMapInfo(this);

    connect(
        editorMapInfo, SIGNAL(signaledUpdate()),
        this,          SLOT(signalUpdate())
    );

    // MapInfo Picker
    pickerMapInfo = new PickerMapInfo(this);

    connect(
        pickerMapInfo, SIGNAL(selectedMapInfo(int)),
        this,          SLOT(selectMapInfo(int))
    );

    // MapMap Editor
    editorMapMap  = new EditorMapMap(this);

    // Players Editor
    editorPlayers = new EditorPlayers(this);

    // Build Layout
    pickerMapInfo->setFixedWidth(180);
    editorMapInfo->setFixedWidth(180);

    const auto layoutMapInfo = new QVBoxLayout();
    layoutMapInfo->addWidget(editorMapInfo);
    layoutMapInfo->addWidget(pickerMapInfo);

    const auto tabsMapEdit = new QTabWidget(this);
    tabsMapEdit->addTab(editorMapMap,  "Terrain");
    tabsMapEdit->addTab(editorPlayers, "Players");
    tabsMapEdit->addTab(new QWidget(), "Units");

    const auto splitMapEditor = new QSplitter(this);
    splitMapEditor->addWidget(editorMapMap->viewMapTileGrid);
    splitMapEditor->addWidget(tabsMapEdit);

    const auto layoutMain = new QHBoxLayout();
    layoutMain->addLayout(layoutMapInfo);
    layoutMain->addWidget(splitMapEditor);

    setLayout(layoutMain);
}

void EditorMain::selectMapInfo(const int i) {
    loadSelectedMapData(i);
}

void EditorMain::signalUpdate() {
    updateNecData();
}

void EditorMain::zoomMapFull() {
    zoomMap(1.0, false);
}

void EditorMain::zoomMapIn() {
    zoomMap(2.0, true);
}

void EditorMain::zoomMapOut() {
    zoomMap(0.5, true);
}

void EditorMain::toggleMapGrid(const bool mapGridOn) {
    editorMapMap->setMapGridVisible(mapGridOn);
}

void EditorMain::loadNecData(Nec::DataManager* const newNecData) {
    necData = newNecData;

    pickerMapInfo->loadNecData(necData);

    // Select empty map 0 by default
    loadSelectedMapData(0);
}

void EditorMain::updateNecData() {
    editorMapInfo->updateNecData();
    pickerMapInfo->updateNecData();
    editorPlayers->updateNecData();
    editorMapMap->updateNecData();
}

void EditorMain::zoomMap(const double level, const bool combine) {
    editorMapMap->zoomMap(level, combine);
}

void EditorMain::loadSelectedMapData(const std::size_t i) {
    const auto necMapInfo = &(necData->bigInfo->at(i));
    const auto necMapMap = &(necData->bigMap->at(i));

    editorMapInfo->loadNecData(necMapInfo);
    editorPlayers->loadNecData(necMapInfo);
    editorMapMap->loadNecData(necMapInfo, necMapMap);

    // All updating is triggered by NecMapEditorMain
    updateNecData();
}

} // namespace App
