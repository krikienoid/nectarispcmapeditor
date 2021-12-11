#include "terselector.h"

namespace App {

TerSelector::TerSelector(QWidget* const parent) :
    QListWidget(parent),
    selectedTerFilterGroup(0)
{
    // Initialize internal resource from ter.bin file.
    QFile terBin(":data/bin/ter.bin");

    terBin.open(QIODevice::ReadOnly);

    Q_ASSERT(terBin.isReadable());

    terData = terBin.readAll();

    terBin.close();

    // Init tileset.
    const TerTilesPixmap terTilesPixmap;

    // Init terrain tiles.
    for (int i = 0; i < Constants::tileCount; ++i) {
        const auto icon = new QIcon(terTilesPixmap.getTerTile(i));
        const auto terItem = new QListWidgetItem(*icon, nullptr);

        terItem->setData(TerIndexDataRole, QVariant(i));

        terItem->setToolTip(
            QString(tr("Ter: ")) +
            QString::number(i)
        );

        this->addItem(terItem);
    }

    // Set standard view settings.
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

    // Init terrain group filter dropdown.
    terFilterGroupComboBox = new QComboBox();
    terFilterGroupComboBox->addItem(tr("All"), QVariant(0));
    terFilterGroupComboBox->insertSeparator(1);

    for (std::size_t i = 0, ii = Nec::TerMoveType::data.size(); i < ii; ++i) {
        terFilterGroupComboBox->addItem(
            QString::fromStdString(Nec::TerMoveType::data[i].name),
            QVariant(static_cast<int>(i) + 1)
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
        terItem->data(TerIndexDataRole).toInt()
    );
}

void TerSelector::updateActiveTilesets() {
    static constexpr int tilesetItemCount = 128;

    for (int i = 0; i < Constants::tileCount; ++i) {
        item(i)->setHidden(
            !tilesetSelections[i / tilesetItemCount] ||
            (
                selectedTerFilterGroup > 0 &&
                static_cast<int>(
                    Nec::TerType::data[static_cast<std::size_t>(terData[i])]
                        .terMoveType
                ) + 1 != selectedTerFilterGroup
            )
        );
    }
}

} // namespace App
