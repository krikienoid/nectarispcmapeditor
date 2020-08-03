#include "pickertertile.h"

PickerTerTile::PickerTerTile(QWidget * parent) : QListWidget(parent), terTypeFilter(0) {

    // Initialize internal resource ter.bin
    QFile terBin(":data/bin/ter.bin");
    terBin.open(QIODevice::ReadOnly);
    Q_ASSERT(terBin.isReadable());
    bytesTerBin = terBin.readAll();
    terBin.close();

    // Init tileset
    PixmapTerTiles * pixmapTerTiles = new PixmapTerTiles;

    // Terrain tiles
    for (int i = 0; i < PixmapTerTiles::TILE_MAX; ++i) {
        QIcon * tileIcon = new QIcon(pixmapTerTiles->getTerTile(i));
        QListWidgetItem * newItem = new QListWidgetItem(*tileIcon, NULL);
        newItem->setData(TILE_TYPE, QVariant(i));
        this->addItem(newItem);
    }

    delete pixmapTerTiles;

    // Standard view settings
    setViewMode(QListView::IconMode);
    setUniformItemSizes(true);
    setIconSize(QSize(16, 16));
    setSpacing(0);
    setFlow(QListView::LeftToRight);
    setWrapping(true);
    setResizeMode(QListView::Adjust);
    setMinimumWidth(240);
    setMaximumWidth(450);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("QListView {background-color: #222;}");
    setDragEnabled(false);

    // Terrain Filter Dropdown list
    dropdownTerTypes = new QComboBox;
    dropdownTerTypes->addItem(tr("All"), QVariant(0));
    dropdownTerTypes->insertSeparator(1);
    for (int i = Nec::TerTypeData::TER_FIRST; i <= Nec::TerTypeData::TER_LAST; i++) {
        dropdownTerTypes->addItem(
            QString::fromStdString(Nec::TER_GROUP_NAMES[i]),
            QVariant(i + 1)
        );
    }

    connect(
        dropdownTerTypes, SIGNAL(currentIndexChanged(int)),
        this,             SLOT(selectTerTypeFilter(int))
    );

    // Connect slots and signals
    connect(
        this, SIGNAL(itemClicked(QListWidgetItem *)),
        this, SLOT(selectTerTile(QListWidgetItem *))
    );

}

// Public Slots

void PickerTerTile::selectTerTypeFilter (int i) {
    terTypeFilter = dropdownTerTypes->itemData(i).toInt();
    updateTilesetRanges();
}

void PickerTerTile::selectTerTile (QListWidgetItem * selectedItem) {
    emit selectedTerTile(selectedItem->data(TILE_TYPE).toInt());
}

void PickerTerTile::updateTilesetRanges () {
    for (int i = 0; i < PixmapTerTiles::TILE_MAX; ++i) {
        item(i)->setHidden(
            !enabledTilesetRange[i / 128] ||
            (terTypeFilter > 0 && Nec::TER_TYPE_DATA[bytesTerBin[i]].terGroup + 1 != terTypeFilter)
        );
    }
}
