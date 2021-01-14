#include "editormapmap.h"

namespace App {

EditorMapMap::EditorMapMap(QWidget* const parent) : QWidget(parent) {
    // Init Children
    createViewMapTileGrid();
    createPickerTerTile();
    createTilesetRangePicker();
    createMapSizePicker();

    // Main Layout
    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(groupTerTile);
    layoutMain->addWidget(groupMapSize);
    layoutMain->addWidget(groupChecks);

    setLayout(layoutMain);

    // Init State
    updateSelectedTerTile(0);

    toolMode = TOOL_TER;
}

void EditorMapMap::selectTerTile(const int i) {
    toolMode = TOOL_TER;

    updateSelectedTerTile(i);
}

void EditorMapMap::selectMapTile(const int i) {
    if (toolMode == TOOL_TER && i < int(necMapMap->size())) {
        necMapMap->at(i) = Raw::ByteString::fromInt(selectedTerTile);
        necMapMap->at(i).resize(2);

        updateNecData();
    }
}

void EditorMapMap::changeTilesetRange(int) {
    // Widget Data
    for (int i = 0; i < TILESETS; ++i) {
        pickerTerTile->enabledTilesetRange[i] =
            checksTilesetRange[i]->isChecked();
    }

    // Nec Data
    for (int i = 0, ii = necMapInfo->bgFiles.size(); i < ii; ++i) {
        necMapInfo->bgFiles[i] = 0;
    }

    for (
        int j = 0, k = 0, kk = necMapInfo->bgFiles.size();
        j < TILESETS && k < kk;
        ++j
    ) {
        if (pickerTerTile->enabledTilesetRange[j]) {
            necMapInfo->bgFiles[k++] = j;
        }
    }

    // Widget State
    updateEnabledTilesetRange();
}

void EditorMapMap::changeMapSizeX(const int qX) {
    necMapInfo->quadrantsX = qX;
    necMapMap->qX = qX;

    updateNecData();
}

void EditorMapMap::changeMapSizeY(const int qY) {
    necMapInfo->quadrantsY = qY;
    necMapMap->qY = qY;

    updateNecData();
}

void EditorMapMap::loadNecData(
    Nec::MapInfo* const newNecMapInfo,
    Nec::MapMap* const newNecMapMap
) {
    necMapInfo = newNecMapInfo;
    necMapMap  = newNecMapMap;

    for (int i = 0; i < TILESETS; ++i) {
        pickerTerTile->enabledTilesetRange[i] = hasTilesetEnabled(i);
    }

    sceneMapTileGrid->loadNecData(newNecMapInfo, newNecMapMap);
}

void EditorMapMap::updateNecData() {
    comboMapSizeX->setCurrentIndex(necMapInfo->quadrantsX);
    comboMapSizeY->setCurrentIndex(necMapInfo->quadrantsY);

    sceneMapTileGrid->updateNecData();

    viewMapTileGrid->setSceneRect(
        0,
        0,
        Nec::MapMap::getWidth(necMapInfo->quadrantsX + 1) *
            SceneMapTileGrid::TILE_WIDTH,
        Nec::MapMap::getHeight(necMapInfo->quadrantsY + 1) *
            SceneMapTileGrid::TILE_HEIGHT
    );

    viewMapTileGrid->verticalScrollBar()->setValue(0);
    viewMapTileGrid->horizontalScrollBar()->setValue(0);

    updateEnabledTilesetRange();
}

void EditorMapMap::zoomMap(const double level, const bool combine) {
    viewMapTileGrid->setTransform(QTransform::fromScale(level, level), combine);
}

void EditorMapMap::setMapGridVisible(const bool mapGridOn) {
    sceneMapTileGrid->setMapGridVisible(mapGridOn);
}

void EditorMapMap::updateSelectedTerTile(int terTileNum) {
    if (terTileNum >= PixmapTerTiles::TILE_MAX) {
        terTileNum = 0;
    }

    selectedTerTile = terTileNum;

    const int terTypeNum = pickerTerTile->bytesTerBin.at(terTileNum);

    if (terTypeNum < int(Nec::TER_TYPE_DATA.size())) {
        labelTerTileImg->setPixmap(
            sceneMapTileGrid->pixmapTerTiles->getTerTile(terTileNum)
        );

        labelTerTileName->setText(
            QString::fromStdString(Nec::TER_TYPE_DATA[terTypeNum].name) +
            QString(" (") +
            QString::number((Nec::TER_TYPE_DATA[terTypeNum].defMod - 1) * 100) +
            QString("%)")
        );
    }
}

void EditorMapMap::updateEnabledTilesetRange() {
    for (int i = 0; i < TILESETS; ++i) {
        checksTilesetRange[i]->setChecked(
            pickerTerTile->enabledTilesetRange[i]
        );
    }

    pickerTerTile->updateTilesetRanges();
}

bool EditorMapMap::hasTilesetEnabled(int bgN) {
    for (int i = 0, ii = necMapInfo->bgFiles.size(); i < ii; ++i) {
        if (int(necMapInfo->bgFiles[i]) == bgN) {
            return true;
        }
    }

    return false;
}

void EditorMapMap::createViewMapTileGrid() {
    // Map Grid
    sceneMapTileGrid = new SceneMapTileGrid(this);

    viewMapTileGrid  = new QGraphicsView(sceneMapTileGrid);
    viewMapTileGrid->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    viewMapTileGrid->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    viewMapTileGrid->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    viewMapTileGrid->setSceneRect(
        0,
        0,
        Nec::MapMap::getWidth(1) * SceneMapTileGrid::TILE_WIDTH,
        Nec::MapMap::getHeight(1) * SceneMapTileGrid::TILE_HEIGHT
    );

    connect(
        sceneMapTileGrid, SIGNAL(selectedMapTile(int)),
        this,             SLOT(selectMapTile(int))
    );
}

void EditorMapMap::createTilesetRangePicker() {
    // Selected Tileset Range Frame
    const auto layoutRowFile1 = new QHBoxLayout();
    const auto layoutRowFile2 = new QHBoxLayout();

    layoutRowFile1->setAlignment(Qt::AlignLeft);
    layoutRowFile2->setAlignment(Qt::AlignLeft);

    // QComboBoxes
    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0; i < TILESETS; ++i) {
        const auto newCheckBox = new QCheckBox(this);

        newCheckBox->setText(
            QString("bg") +
            QString::number(i + 1)
        );

        if (i <= TILESETS / 2) {
            layoutRowFile1->addWidget(newCheckBox);
        } else {
            layoutRowFile2->addWidget(newCheckBox);
        }

        connect(
            newCheckBox,  SIGNAL(clicked()),
            signalMapper, SLOT(map())
        );

        signalMapper->setMapping(newCheckBox, i);
        checksTilesetRange.append(newCheckBox);
        pickerTerTile->enabledTilesetRange.append(false);
    }

    connect(
        signalMapper, SIGNAL(mapped(int)),
        this,         SLOT(changeTilesetRange(int))
    );

    // Layout
    const auto layoutColFile = new QVBoxLayout();
    layoutColFile->addLayout(layoutRowFile1);
    layoutColFile->addLayout(layoutRowFile2);

    groupChecks = new QGroupBox(tr("Tilesets"));
    groupChecks->setToolTip("Pick up to 5 tileset files to load");
    groupChecks->setLayout(layoutColFile);
}

void EditorMapMap::createPickerTerTile() {
    // PickerTerTile
    pickerTerTile = new PickerTerTile(this);

    connect(
        pickerTerTile, SIGNAL(selectedTerTile(int)),
        this,          SLOT(selectTerTile(int))
    );

    // Picker Status
    labelTerTileImg  = new QLabel(this);
    labelTerTileName = new QLabel(this);

    // Separator
    const auto line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    // Layout

    // Selected Tile
    const auto layoutRowTile = new QHBoxLayout();
    layoutRowTile->setAlignment(Qt::AlignLeft);
    layoutRowTile->addWidget(new QLabel("Selected Tile: ", this));
    layoutRowTile->addWidget(labelTerTileImg);
    layoutRowTile->addWidget(labelTerTileName);

    // Show Tiles
    const auto layoutRowShow = new QHBoxLayout();
    layoutRowShow->setAlignment(Qt::AlignLeft);
    layoutRowShow->addWidget(new QLabel("Show: ", this));
    layoutRowShow->addWidget(pickerTerTile->dropdownTerTypes);

    const auto layoutColTile = new QVBoxLayout();
    layoutColTile->addLayout(layoutRowTile);
    layoutColTile->addWidget(line);
    layoutColTile->addLayout(layoutRowShow);
    layoutColTile->addWidget(pickerTerTile);

    groupTerTile = new QGroupBox(tr("Terrain Tiles"));
    groupTerTile->setLayout(layoutColTile);
}

void EditorMapMap::createMapSizePicker() {
    // Dropdown Menus
    comboMapSizeX = new QComboBox(this);
    comboMapSizeY = new QComboBox(this);
    comboMapSizeX->setFixedWidth(60);
    comboMapSizeY->setFixedWidth(60);

    for (int i = 0; i < 4; ++i) {
        comboMapSizeX->addItem(QString::number(i + 1));
        comboMapSizeY->addItem(QString::number(i + 1));
    }

    connect(
        comboMapSizeX, SIGNAL(currentIndexChanged(int)),
        this,          SLOT(changeMapSizeX(int))
    );

    connect(
        comboMapSizeY, SIGNAL(currentIndexChanged(int)),
        this,          SLOT(changeMapSizeY(int))
    );

    // Layout
    const auto layoutRowMapSize = new QHBoxLayout();
    layoutRowMapSize->setAlignment(Qt::AlignLeft);
    layoutRowMapSize->addWidget(new QLabel("Width: ", this));
    layoutRowMapSize->addWidget(comboMapSizeX);
    layoutRowMapSize->addWidget(new QLabel("Height: ", this));
    layoutRowMapSize->addWidget(comboMapSizeY);

    groupMapSize = new QGroupBox(tr("Map Size"));
    groupMapSize->setLayout(layoutRowMapSize);
}

} // namespace App
