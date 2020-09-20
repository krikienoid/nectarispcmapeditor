#include "pickermapinfo.h"

namespace App {

PickerMapInfo::PickerMapInfo(QWidget* parent) : QWidget(parent) {
    // List Widget
    listMapInfo = new QListWidget(this);

    connect(
        listMapInfo, SIGNAL(itemClicked(QListWidgetItem*)),
        this,        SLOT(clickMapList(QListWidgetItem*))
    );

    // Build MapInfo List
    for (int i = 0, ii = Nec::BigInfo::LENGTH; i < ii; ++i) {
        QListWidgetItem* listItem = new QListWidgetItem(listMapInfo);

        setListItemData(listItem, i);

        listMapInfo->addItem(listItem);
    }

    // Layout
    QVBoxLayout* layoutColMapPicker = new QVBoxLayout;
    layoutColMapPicker->addWidget(listMapInfo);

    QGroupBox* groupMapPicker = new QGroupBox(tr("Map List"), this);
    groupMapPicker->setContentsMargins(0, 8, 0, 0);
    groupMapPicker->setLayout(layoutColMapPicker);

    QHBoxLayout* layoutMain = new QHBoxLayout(this);
    layoutMain->addWidget(groupMapPicker);

    setLayout(layoutMain);
}

void PickerMapInfo::clickMapList(QListWidgetItem* mapItem) {
    emit selectedMapInfo(getListItemData(mapItem));
}

void PickerMapInfo::loadNecData(Nec::DataManager* newNecData) {
    necData = newNecData;
}

void PickerMapInfo::updateNecData() {
    // Reset MapInfo List
    for (int i = 0, ii = Nec::BigInfo::LENGTH; i < ii; ++i) {
        QListWidgetItem* listItem = listMapInfo->item(i);

        if (necData->bigInfo->mapInfoExists(i)) {
            listItem->setHidden(false);

            listItem->setText(
                QString::number(i + 1) +
                QString(" : ") +
                QString::fromStdString(
                    necData->bigInfo->at(i).mapName
                )
            );

            // setListItemData(listItem, i);
        } else {
            listItem->setHidden(true);
        }
    }
}

int PickerMapInfo::getListItemData(QListWidgetItem* listItem) {
    return listItem->data(Qt::UserRole).toInt();
}

void PickerMapInfo::setListItemData(QListWidgetItem* listItem, const int i) {
    listItem->setData(Qt::UserRole, QVariant(i));
}

} // namespace App
