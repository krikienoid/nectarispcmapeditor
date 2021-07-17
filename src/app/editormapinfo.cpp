#include "editormapinfo.h"

namespace App {

EditorMapInfo::EditorMapInfo(QWidget* const parent) : QWidget(parent) {
    // Map Name Text Input
    editMapName = new QLineEdit(this);
    editMapName->setMaxLength(static_cast<int>(Nec::MapName::LENGTH));

    connect(
        editMapName, SIGNAL(editingFinished()),
        this,        SLOT(enterMapName())
    );

    // Separator
    const auto line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    // Layout
    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(new QLabel("Map:", this));
    layoutMain->addWidget(editMapName);
    layoutMain->addWidget(line);

    setLayout(layoutMain);
}

void EditorMapInfo::enterMapName() {
    necMapInfo->mapName = Nec::MapName(editMapName->text().toStdString());

    emit signaledUpdate();
}

void EditorMapInfo::loadNecData(Nec::MapInfo* const mapInfo) {
    necMapInfo = mapInfo;
}

void EditorMapInfo::updateNecData() {
    editMapName->setText(QString::fromStdString(necMapInfo->mapName));
}

} // namespace App
