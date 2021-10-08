#include "terselector.h"

namespace App {

TerSelector::TerSelector(QWidget* const parent) :
    QListWidget(parent),
    selectedTerFilterGroup(0)
{
    // Initialize internal resource ter.bin
    QFile terBin(":data/bin/ter.bin");

    terBin.open(QIODevice::ReadOnly);

    Q_ASSERT(terBin.isReadable());

    terData = terBin.readAll();

    terBin.close();

    // Init tileset
    const TerTilesPixmap terTilesPixmap;

    // Terrain tiles
    for (int i = 0; i < TerTilesPixmap::tileCount; ++i) {
        const auto icon = new QIcon(terTilesPixmap.getTerTile(i));
        const auto terItem = new QListWidgetItem(*icon, nullptr);

        terItem->setData(static_cast<int>(DataRole::TerIndex), QVariant(i));

        terItem->setToolTip(
            QString(tr("Ter: ")) +
            QString::number(i)
        );

        this->addItem(terItem);
    }

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
    setStyleSheet("QListView { background-color: #222; }");
    setDragEnabled(false);

    // Terrain Filter Dropdown list
    terFilterGroupComboBox = new QComboBox();
    terFilterGroupComboBox->addItem(tr("All"), QVariant(0));
    terFilterGroupComboBox->insertSeparator(1);

    for (
        int i = static_cast<int>(Nec::TerTypeMeta::TerFilterGroup::First);
        i <= static_cast<int>(Nec::TerTypeMeta::TerFilterGroup::Last);
        i++
    ) {
        terFilterGroupComboBox->addItem(
            QString::fromStdString(
                Nec::TER_FILTER_GROUP_NAMES[static_cast<std::size_t>(i)]
            ),
            QVariant(i + 1)
        );
    }

    connect(
        terFilterGroupComboBox, SIGNAL(currentIndexChanged(int)),
        this,                   SLOT(selectTerFilterGroup(int))
    );

    connect(
        this, SIGNAL(itemClicked(QListWidgetItem*)),
        this, SLOT(selectTer(QListWidgetItem*))
    );
}

void TerSelector::selectTerFilterGroup(const int i) {
    selectedTerFilterGroup = terFilterGroupComboBox->itemData(i).toInt();

    updateActiveTilesets();
}

void TerSelector::selectTer(QListWidgetItem* const terItem) {
    emit selectedTer(
        terItem->data(static_cast<int>(DataRole::TerIndex)).toInt()
    );
}

void TerSelector::updateActiveTilesets() {
    static constexpr int tilesetItemCount = 128;

    for (int i = 0; i < TerTilesPixmap::tileCount; ++i) {
        item(i)->setHidden(
            !tilesetSelections[i / tilesetItemCount] ||
            (
                selectedTerFilterGroup > 0 &&
                static_cast<int>(
                    Nec::TER_TYPE_DATA[static_cast<std::size_t>(terData[i])]
                        .terFilterGroup
                ) + 1 != selectedTerFilterGroup
            )
        );
    }
}

} // namespace App
