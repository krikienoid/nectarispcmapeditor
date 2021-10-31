#include "levelinfoselector.h"

namespace App {

LevelInfoSelector::LevelInfoSelector(QWidget* const parent) : QWidget(parent) {
    // List Widget
    levelInfoList = new QListWidget(this);

    connect(
        levelInfoList, SIGNAL(itemClicked(QListWidgetItem*)),
        this,          SLOT(clickList(QListWidgetItem*))
    );

    // Build LevelInfo List
    for (
        int i = 0, ii = static_cast<int>(Nec::BigInfo::levelCount);
        i < ii;
        ++i
    ) {
        const auto levelInfoItem = new QListWidgetItem(levelInfoList);

        setItemData(levelInfoItem, i);

        levelInfoList->addItem(levelInfoItem);
    }

    // Layout
    const auto layoutCol = new QVBoxLayout();
    layoutCol->addWidget(levelInfoList);

    const auto listGroupBox = new QGroupBox(tr("Levels"), this);
    listGroupBox->setContentsMargins(0, 8, 0, 0);
    listGroupBox->setLayout(layoutCol);

    const auto layoutMain = new QHBoxLayout(this);
    layoutMain->addWidget(listGroupBox);

    setLayout(layoutMain);
}

void LevelInfoSelector::clickList(QListWidgetItem* const levelInfoItem) {
    emit selectedLevelInfo(getItemData(levelInfoItem));
}

void LevelInfoSelector::setTargetData(const Nec::FileData* const fileData) {
    targetFileData = fileData;
}

void LevelInfoSelector::updateState() {
    // Reset LevelInfo List
    for (std::size_t i = 0, ii = Nec::BigInfo::levelCount; i < ii; ++i) {
        const int value = static_cast<int>(i);
        const auto levelInfoItem = levelInfoList->item(value);

        if (targetFileData->bigInfo->levelInfoExists(i)) {
            levelInfoItem->setHidden(false);

            levelInfoItem->setText(
                QString::number(value + 1) +
                QString(" : ") +
                QString::fromStdString(
                    targetFileData->bigInfo->items[i].levelName.toString()
                )
            );

            // setItemData(levelInfoItem, value);
        } else {
            levelInfoItem->setHidden(true);
        }
    }
}

int LevelInfoSelector::getItemData(QListWidgetItem* const levelInfoItem) {
    return levelInfoItem->data(LevelInfoIndexDataRole).toInt();
}

void LevelInfoSelector::setItemData(
    QListWidgetItem* const levelInfoItem,
    const int i
) {
    levelInfoItem->setData(LevelInfoIndexDataRole, QVariant(i));
}

} // namespace App
