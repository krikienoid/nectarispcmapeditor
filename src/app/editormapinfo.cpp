#include "editormapinfo.h"

namespace App {

// Constructors

EditorMapInfo::EditorMapInfo (QWidget * parent) : QWidget(parent) {

    // Map Name Text Input
    editMapName = new QLineEdit(this);
    editMapName->setMaxLength(Nec::MapName::LENGTH);
    connect(
        editMapName, SIGNAL(editingFinished()),
        this,        SLOT(enterMapName())
    );

    // Separator
    QFrame * line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    // Layout
    QVBoxLayout * layoutMain = new QVBoxLayout;
    layoutMain->addWidget(new QLabel("Map:", this));
    layoutMain->addWidget(editMapName);
    layoutMain->addWidget(line);
    setLayout(layoutMain);

}

// Public Slots

void EditorMapInfo::enterMapName () {
    necMapInfo->mapName = editMapName->text().toStdString();
    emit signaledUpdate();
}

// Public Methods

void EditorMapInfo::loadNecData (Nec::MapInfo * mapInfo) {
    necMapInfo = mapInfo;
}

void EditorMapInfo::updateNecData () {
    editMapName->setText(QString::fromStdString(necMapInfo->mapName));
}

} // namespace App
