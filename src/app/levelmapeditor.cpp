#include "levelmapeditor.h"

namespace App {

LevelMapEditor::LevelMapEditor(QWidget* const parent) : QWidget(parent) {
    // Init children widgets.
    initMapView();
    initTerSelector();
    initTilesetSelector();
    initMapSizeSelector();

    // Init layout.
    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(terSelectorGroupBox);
    layoutMain->addWidget(mapSizeGroupBox);
    layoutMain->addWidget(tilesetSelectorGroupBox);

    setLayout(layoutMain);

    // Init state.
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
        targetLevelMap->items[i] = Raw::UInt16(selectedTer);

        updateState();
    }
}

void LevelMapEditor::editActiveTilesets() {
    // Update widget data.
    for (int i = 0; i < Constants::tilesetCount; ++i) {
        terSelector->tilesetSelections[i] = tilesetCheckBoxes[i]->isChecked();
    }

    // Update file data.
    for (
        std::size_t i = 0, ii = Nec::LevelInfo::activeTilesetCount;
        i < ii;
        ++i
    ) {
        targetLevelInfo->activeTilesets[i] = Raw::UInt8(0);
    }

    std::size_t j = 0;

    for (
        int i = 0;
        i < Constants::tilesetCount && j < Nec::LevelInfo::activeTilesetCount;
        ++i
    ) {
        if (terSelector->tilesetSelections[i]) {
            targetLevelInfo->activeTilesets[j] = Raw::UInt8(i);

            ++j;
        }
    }

    // Update widget state.
    updateActiveTilesets();
}

void LevelMapEditor::editChunkCountX(const int cX) {
    targetLevelInfo->chunkCountX = Raw::UInt8(cX);
    targetLevelMap->cX = static_cast<std::size_t>(cX);

    updateState();
}

void LevelMapEditor::editChunkCountY(const int cY) {
    targetLevelInfo->chunkCountY = Raw::UInt8(cY);
    targetLevelMap->cY = static_cast<std::size_t>(cY);

    updateState();
}

void LevelMapEditor::setTargetData(
    Nec::LevelInfo* const levelInfo,
    Nec::LevelMap* const levelMap
) {
    targetLevelInfo = levelInfo;
    targetLevelMap  = levelMap;

    for (int i = 0; i < Constants::tilesetCount; ++i) {
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
        ) * Constants::tileWidth,
        static_cast<int>(
            Nec::MapSize::getHeight(targetLevelInfo->chunkCountY.value()) + 1
        ) * Constants::tileHeight
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
    if (terIndex >= Constants::tileCount) {
        terIndex = 0;
    }

    selectedTer = terIndex;

    const std::size_t terTypeIndex = static_cast<std::size_t>(
        terSelector->terData[terIndex]
    );

    if (terTypeIndex < Nec::TerType::data.size()) {
        selectedTerImageLabel->setPixmap(
            levelMapScene->terTilesPixmap->getTerTile(terIndex)
        );

        const auto& terTypeMeta = Nec::TerType::data[terTypeIndex];

        selectedTerTypeNameLabel->setText(
            QString::fromStdString(terTypeMeta.name) +
            QString(" (") +
            QString::number((terTypeMeta.defense - 1) * 100) +
            QString("%)")
        );
    }
}

void LevelMapEditor::updateActiveTilesets() {
    for (int i = 0; i < Constants::tilesetCount; ++i) {
        tilesetCheckBoxes[i]->setChecked(terSelector->tilesetSelections[i]);
    }

    terSelector->updateActiveTilesets();
}

bool LevelMapEditor::hasActiveTileset(int i) {
    for (const auto& item : targetLevelInfo->activeTilesets) {
        if (item.value() == i) {
            return true;
        }
    }

    return false;
}

void LevelMapEditor::initMapView() {
    levelMapScene = new LevelMapScene(this);

    mapView = new QGraphicsView(levelMapScene);
    mapView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    mapView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    mapView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    mapView->setSceneRect(
        0,
        0,
        static_cast<int>(Nec::MapSize::getWidth(1)) * Constants::tileWidth,
        static_cast<int>(Nec::MapSize::getHeight(1)) * Constants::tileHeight
    );

    connect(
        levelMapScene, SIGNAL(selectedMapCell(int)),
        this,          SLOT(selectMapCell(int))
    );
}

void LevelMapEditor::initTilesetSelector() {
    const auto layoutRow1 = new QHBoxLayout();
    const auto layoutRow2 = new QHBoxLayout();

    layoutRow1->setAlignment(Qt::AlignLeft);
    layoutRow2->setAlignment(Qt::AlignLeft);

    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0; i < Constants::tilesetCount; ++i) {
        const auto checkBox = new QCheckBox(this);

        checkBox->setText(
            QString("bg") +
            QString::number(i + 1)
        );

        if (i <= Constants::tilesetCount / 2) {
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

    const auto layout = new QVBoxLayout();
    layout->addLayout(layoutRow1);
    layout->addLayout(layoutRow2);

    tilesetSelectorGroupBox = new QGroupBox(tr("Tilesets"));
    tilesetSelectorGroupBox->setToolTip(tr("Select up to 5 tilesets to load for this level."));
    tilesetSelectorGroupBox->setLayout(layout);
}

void LevelMapEditor::initTerSelector() {
    terSelector = new TerSelector(this);

    connect(
        terSelector, SIGNAL(selectedTer(int)),
        this,        SLOT(selectTer(int))
    );

    selectedTerImageLabel    = new QLabel(this);
    selectedTerTypeNameLabel = new QLabel(this);

    const auto line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    const auto layoutRow1 = new QHBoxLayout();
    layoutRow1->setAlignment(Qt::AlignLeft);
    layoutRow1->addWidget(new QLabel(tr("Selected tile: "), this));
    layoutRow1->addWidget(selectedTerImageLabel);
    layoutRow1->addWidget(selectedTerTypeNameLabel);

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
