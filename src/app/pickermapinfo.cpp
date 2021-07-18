#include "pickermapinfo.h"

namespace App {

PickerMapInfo::PickerMapInfo(QWidget* const parent) : QWidget(parent) {
    // List Widget
    listMapInfo = new QListWidget(this);

    connect(
        listMapInfo, SIGNAL(itemClicked(QListWidgetItem*)),
        this,        SLOT(clickMapList(QListWidgetItem*))
    );

    // Build MapInfo List
    for (int i = 0, ii = static_cast<int>(Nec::BigInfo::LENGTH); i < ii; ++i) {
        const auto listItem = new QListWidgetItem(listMapInfo);

        setListItemData(listItem, i);

        listMapInfo->addItem(listItem);
    }

    // Layout
    const auto layoutColMapPicker = new QVBoxLayout();
    layoutColMapPicker->addWidget(listMapInfo);

    const auto groupMapPicker = new QGroupBox(tr("Map List"), this);
    groupMapPicker->setContentsMargins(0, 8, 0, 0);
    groupMapPicker->setLayout(layoutColMapPicker);

    const auto layoutMain = new QHBoxLayout(this);
    layoutMain->addWidget(groupMapPicker);

    setLayout(layoutMain);
}

void PickerMapInfo::clickMapList(QListWidgetItem* const mapItem) {
    emit selectedMapInfo(getListItemData(mapItem));
}

void PickerMapInfo::loadNecData(const Nec::DataManager* const newNecData) {
    necData = newNecData;
}

void PickerMapInfo::updateNecData() {
    // Reset MapInfo List
    for (std::size_t i = 0, ii = Nec::BigInfo::LENGTH; i < ii; ++i) {
        const int value = static_cast<int>(i);
        const auto listItem = listMapInfo->item(value);

        if (necData->bigInfo->mapInfoExists(i)) {
            listItem->setHidden(false);

            listItem->setText(
                QString::number(value + 1) +
                QString(" : ") +
                QString::fromStdString(
                    necData->bigInfo->items[i].mapName.toString()
                )
            );

            // setListItemData(listItem, value);
        } else {
            listItem->setHidden(true);
        }
    }
}

int PickerMapInfo::getListItemData(QListWidgetItem* const listItem) {
    return listItem->data(Qt::UserRole).toInt();
}

void PickerMapInfo::setListItemData(
    QListWidgetItem* const listItem,
    const int i
) {
    listItem->setData(Qt::UserRole, QVariant(i));
}

} // namespace App
