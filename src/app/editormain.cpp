#include "editormain.h"

namespace App {

EditorMain::EditorMain(QWidget* parent) : QWidget(parent) {
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

    QVBoxLayout* layoutMapInfo = new QVBoxLayout;
    layoutMapInfo->addWidget(editorMapInfo);
    layoutMapInfo->addWidget(pickerMapInfo);

    QTabWidget* tabsMapEdit = new QTabWidget(this);
    tabsMapEdit->addTab(editorMapMap,  "Terrain");
    tabsMapEdit->addTab(editorPlayers, "Players");
    tabsMapEdit->addTab(new QWidget, "Units");

    QSplitter* splitMapEditor = new QSplitter(this);
    splitMapEditor->addWidget(editorMapMap->viewMapTileGrid);
    splitMapEditor->addWidget(tabsMapEdit);

    QHBoxLayout* layoutMain = new QHBoxLayout;
    layoutMain->addLayout(layoutMapInfo);
    layoutMain->addWidget(splitMapEditor);

    setLayout(layoutMain);
}

void EditorMain::selectMapInfo(int i) {
    loadSelectedMapData(i);
}

void EditorMain::signalUpdate() {
    updateNecData();
}

void EditorMain::loadNecData(Nec::DataManager* newNecData) {
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
    Nec::MapInfo* necMapInfo = &(necData->bigInfo->at(i));
    Nec::MapMap* necMapMap = &(necData->bigMap->at(i));

    editorMapInfo->loadNecData(necMapInfo);
    editorPlayers->loadNecData(necMapInfo);
    editorMapMap->loadNecData(necMapInfo, necMapMap);

    // All updating is triggered by NecMapEditorMain
    updateNecData();
}

} // namespace App
