#include "levelmapeditor.h"

namespace App {

LevelMapEditor::LevelMapEditor(QWidget* const parent) : QWidget(parent) {
    // Init Children
    initMapView();
    initTerSelector();
    initTilesetSelector();
    initMapSizeSelector();

    // Main Layout
    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(terSelectorGroupBox);
    layoutMain->addWidget(mapSizeGroupBox);
    layoutMain->addWidget(tilesetSelectorGroupBox);

    setLayout(layoutMain);

    // Init State
    updateSelectedTer(0);

    toolMode = ToolMode::Ter;
}

void LevelMapEditor::selectTer(const int i) {
    toolMode = ToolMode::Ter;

    updateSelectedTer(i);
}

void LevelMapEditor::selectMapCell(const int value) {
    const std::size_t i = static_cast<std::size_t>(value);

    if (toolMode == ToolMode::Ter && i < targetLevelMap->items.size()) {
        targetLevelMap->items[i] = Raw::ByteArray::fromInt(selectedTer);
        targetLevelMap->items[i].resize(2);

        updateState();
    }
}

void LevelMapEditor::editActiveTilesets() {
    // Widget Data
    for (int i = 0; i < tilesetCount; ++i) {
        terSelector->tilesetSelections[i] = tilesetCheckBoxes[i]->isChecked();
    }

    // Nec Data
    for (
        std::size_t i = 0, ii = Nec::LevelInfo::activeTilesetCount;
        i < ii;
        ++i
    ) {
        targetLevelInfo->activeTilesets[i] = Raw::Byte(0);
    }

    for (
        int i = 0, j = 0, jj = static_cast<int>(Nec::LevelInfo::activeTilesetCount);
        i < tilesetCount && j < jj;
        ++i
    ) {
        if (terSelector->tilesetSelections[i]) {
            targetLevelInfo->activeTilesets[static_cast<std::size_t>(j++)] = Raw::Byte(i);
        }
    }

    // Widget State
    updateActiveTilesets();
}

void LevelMapEditor::editChunkCountX(const int cX) {
    targetLevelInfo->chunkCountX = Raw::Byte(cX);
    targetLevelMap->cX = static_cast<std::size_t>(cX);

    updateState();
}

void LevelMapEditor::editChunkCountY(const int cY) {
    targetLevelInfo->chunkCountY = Raw::Byte(cY);
    targetLevelMap->cY = static_cast<std::size_t>(cY);

    updateState();
}

void LevelMapEditor::setTargetData(
    Nec::LevelInfo* const levelInfo,
    Nec::LevelMap* const levelMap
) {
    targetLevelInfo = levelInfo;
    targetLevelMap  = levelMap;

    for (int i = 0; i < tilesetCount; ++i) {
        terSelector->tilesetSelections[i] = hasActiveTileset(i);
    }

    levelMapScene->setTargetData(levelInfo, levelMap);
}

void LevelMapEditor::updateState() {
    chunkCountXComboBox->setCurrentIndex(targetLevelInfo->chunkCountX.value());
    chunkCountYComboBox->setCurrentIndex(targetLevelInfo->chunkCountY.value());

    levelMapScene->updateState();

    mapView->setSceneRect(
        0,
        0,
        static_cast<int>(
            Nec::MapSize::getWidth(targetLevelInfo->chunkCountX.value()) + 1
        ) * LevelMapScene::tileWidth,
        static_cast<int>(
            Nec::MapSize::getHeight(targetLevelInfo->chunkCountY.value()) + 1
        ) * LevelMapScene::tileHeight
    );

    mapView->verticalScrollBar()->setValue(0);
    mapView->horizontalScrollBar()->setValue(0);

    updateActiveTilesets();
}

void LevelMapEditor::zoomMap(const double level, const bool combine) {
    mapView->setTransform(QTransform::fromScale(level, level), combine);
}

void LevelMapEditor::setMapGridVisible(const bool isOn) {
    levelMapScene->setMapGridVisible(isOn);
}

void LevelMapEditor::updateSelectedTer(int terIndex) {
    if (terIndex >= TerTilesPixmap::tileCount) {
        terIndex = 0;
    }

    selectedTer = terIndex;

    const std::size_t terTypeIndex = static_cast<std::size_t>(
        terSelector->terData[terIndex]
    );

    if (terTypeIndex < Nec::TER_TYPE_DATA.size()) {
        selectedTerImageLabel->setPixmap(
            levelMapScene->terTilesPixmap->getTerTile(terIndex)
        );

        selectedTerTypeNameLabel->setText(
            QString::fromStdString(Nec::TER_TYPE_DATA[terTypeIndex].name) +
            QString(" (") +
            QString::number((Nec::TER_TYPE_DATA[terTypeIndex].defense - 1) * 100) +
            QString("%)")
        );
    }
}

void LevelMapEditor::updateActiveTilesets() {
    for (int i = 0; i < tilesetCount; ++i) {
        tilesetCheckBoxes[i]->setChecked(
            terSelector->tilesetSelections[i]
        );
    }

    terSelector->updateActiveTilesets();
}

bool LevelMapEditor::hasActiveTileset(int i) {
    for (const auto& b : targetLevelInfo->activeTilesets) {
        if (b.value() == i) {
            return true;
        }
    }

    return false;
}

void LevelMapEditor::initMapView() {
    // Map Grid
    levelMapScene = new LevelMapScene(this);

    mapView = new QGraphicsView(levelMapScene);
    mapView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    mapView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    mapView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    mapView->setSceneRect(
        0,
        0,
        static_cast<int>(Nec::MapSize::getWidth(1)) *
            LevelMapScene::tileWidth,
        static_cast<int>(Nec::MapSize::getHeight(1)) *
            LevelMapScene::tileHeight
    );

    connect(
        levelMapScene, SIGNAL(selectedMapCell(int)),
        this,          SLOT(selectMapCell(int))
    );
}

void LevelMapEditor::initTilesetSelector() {
    // Selected Tileset Range Frame
    const auto layoutRow1 = new QHBoxLayout();
    const auto layoutRow2 = new QHBoxLayout();

    layoutRow1->setAlignment(Qt::AlignLeft);
    layoutRow2->setAlignment(Qt::AlignLeft);

    // QComboBoxes
    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0; i < tilesetCount; ++i) {
        const auto checkBox = new QCheckBox(this);

        checkBox->setText(
            QString(tr("bg")) +
            QString::number(i + 1)
        );

        if (i <= tilesetCount / 2) {
            layoutRow1->addWidget(checkBox);
        } else {
            layoutRow2->addWidget(checkBox);
        }

        connect(
            checkBox,     SIGNAL(clicked()),
            signalMapper, SLOT(map())
        );

        signalMapper->setMapping(checkBox, i);
        tilesetCheckBoxes.append(checkBox);
        terSelector->tilesetSelections.append(false);
    }

    connect(
        signalMapper, SIGNAL(mapped(int)),
        this,         SLOT(editActiveTilesets())
    );

    // Layout
    const auto layout = new QVBoxLayout();
    layout->addLayout(layoutRow1);
    layout->addLayout(layoutRow2);

    tilesetSelectorGroupBox = new QGroupBox(tr("Tilesets"));
    tilesetSelectorGroupBox->setToolTip(tr("Select up to 5 tilesets to load for this level."));
    tilesetSelectorGroupBox->setLayout(layout);
}

void LevelMapEditor::initTerSelector() {
    // TerSelector
    terSelector = new TerSelector(this);

    connect(
        terSelector, SIGNAL(selectedTer(int)),
        this,        SLOT(selectTer(int))
    );

    // Selector Status
    selectedTerImageLabel    = new QLabel(this);
    selectedTerTypeNameLabel = new QLabel(this);

    // Separator
    const auto line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    // Layout

    // Selected Tile
    const auto layoutRow1 = new QHBoxLayout();
    layoutRow1->setAlignment(Qt::AlignLeft);
    layoutRow1->addWidget(new QLabel(tr("Selected tile: "), this));
    layoutRow1->addWidget(selectedTerImageLabel);
    layoutRow1->addWidget(selectedTerTypeNameLabel);

    // Show Tiles
    const auto layoutRow2 = new QHBoxLayout();
    layoutRow2->setAlignment(Qt::AlignLeft);
    layoutRow2->addWidget(new QLabel(tr("Filter by type: "), this));
    layoutRow2->addWidget(terSelector->terFilterGroupComboBox);

    const auto layout = new QVBoxLayout();
    layout->addLayout(layoutRow1);
    layout->addWidget(line);
    layout->addLayout(layoutRow2);
    layout->addWidget(terSelector);

    terSelectorGroupBox = new QGroupBox(tr("Terrain tiles"));
    terSelectorGroupBox->setLayout(layout);
}

void LevelMapEditor::initMapSizeSelector() {
    // Dropdown Menus
    chunkCountXComboBox = new QComboBox(this);
    chunkCountYComboBox = new QComboBox(this);
    chunkCountXComboBox->setFixedWidth(60);
    chunkCountYComboBox->setFixedWidth(60);

    for (int i = 0; i < 4; ++i) {
        chunkCountXComboBox->addItem(QString::number(i + 1));
        chunkCountYComboBox->addItem(QString::number(i + 1));
    }

    connect(
        chunkCountXComboBox, SIGNAL(currentIndexChanged(int)),
        this,                SLOT(editChunkCountX(int))
    );

    connect(
        chunkCountYComboBox, SIGNAL(currentIndexChanged(int)),
        this,                SLOT(editChunkCountY(int))
    );

    // Layout
    const auto layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignLeft);
    layout->addWidget(new QLabel(tr("Width: "), this));
    layout->addWidget(chunkCountXComboBox);
    layout->addWidget(new QLabel(tr("Height: "), this));
    layout->addWidget(chunkCountYComboBox);

    mapSizeGroupBox = new QGroupBox(tr("Map size"));
    mapSizeGroupBox->setLayout(layout);
}

} // namespace App
