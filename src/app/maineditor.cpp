#include "maineditor.h"

namespace App {

MainEditor::MainEditor(QWidget* const parent) : QWidget(parent) {
    // Init Nec Data
    Nec::initTerTypeMeta();

    // Init Children Widgets

    // LevelInfo Editor
    levelInfoEditor = new LevelInfoEditor(this);

    connect(
        levelInfoEditor, SIGNAL(signaledUpdate()),
        this,            SLOT(signalUpdate())
    );

    // LevelInfo Selector
    levelInfoSelector = new LevelInfoSelector(this);

    connect(
        levelInfoSelector, SIGNAL(selectedLevelInfo(int)),
        this,              SLOT(selectLevelInfo(int))
    );

    // LevelMap Editor
    levelMapEditor = new LevelMapEditor(this);

    // Players Editor
    playersEditor = new PlayersEditor(this);

    // Build Layout
    levelInfoSelector->setFixedWidth(180);
    levelInfoEditor->setFixedWidth(180);

    const auto layoutCol = new QVBoxLayout();
    layoutCol->addWidget(levelInfoEditor);
    layoutCol->addWidget(levelInfoSelector);

    const auto levelEditorTabGroup = new QTabWidget(this);
    levelEditorTabGroup->addTab(levelMapEditor, tr("Terrain"));
    levelEditorTabGroup->addTab(playersEditor, tr("Players"));
    levelEditorTabGroup->addTab(new QWidget(), tr("Units"));

    const auto mapEditorSplitter = new QSplitter(this);
    mapEditorSplitter->addWidget(levelMapEditor->mapView);
    mapEditorSplitter->addWidget(levelEditorTabGroup);

    const auto layoutMain = new QHBoxLayout();
    layoutMain->addLayout(layoutCol);
    layoutMain->addWidget(mapEditorSplitter);

    setLayout(layoutMain);
}

void MainEditor::selectLevelInfo(const int i) {
    loadSelectedLevelData(i);
}

void MainEditor::signalUpdate() {
    updateState();
}

void MainEditor::zoomMapFull() {
    zoomMap(1.0, false);
}

void MainEditor::zoomMapIn() {
    zoomMap(2.0, true);
}

void MainEditor::zoomMapOut() {
    zoomMap(0.5, true);
}

void MainEditor::toggleMapGrid(const bool isOn) {
    levelMapEditor->setMapGridVisible(isOn);
}

void MainEditor::setTargetData(Nec::FileData* const fileData) {
    targetFileData = fileData;

    levelInfoSelector->setTargetData(targetFileData);

    // Select empty map 0 by default
    loadSelectedLevelData(0);
}

void MainEditor::updateState() {
    levelInfoEditor->updateState();
    levelInfoSelector->updateState();
    playersEditor->updateState();
    levelMapEditor->updateState();
}

void MainEditor::zoomMap(const double level, const bool combine) {
    levelMapEditor->zoomMap(level, combine);
}

void MainEditor::loadSelectedLevelData(const int value) {
    const std::size_t i = static_cast<std::size_t>(value);

    const auto levelInfo = &(targetFileData->bigInfo->items[i]);
    const auto levelMap = &(targetFileData->bigMap->items[i]);

    levelInfoEditor->setTargetData(levelInfo);
    playersEditor->setTargetData(levelInfo);
    levelMapEditor->setTargetData(levelInfo, levelMap);

    // All updating is triggered by MainEditor
    updateState();
}

} // namespace App
