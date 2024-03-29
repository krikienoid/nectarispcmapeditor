#include "levelinfoeditor.h"

namespace App {

LevelInfoEditor::LevelInfoEditor(QWidget* const parent) : QWidget(parent) {
    levelNameEdit = new QLineEdit(this);
    levelNameEdit->setMaxLength(static_cast<int>(Nec::LevelName::length));

    connect(
        levelNameEdit, SIGNAL(editingFinished()),
        this,          SLOT(editLevelName())
    );

    const auto line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(new QLabel(tr("Level:"), this));
    layoutMain->addWidget(levelNameEdit);
    layoutMain->addWidget(line);

    setLayout(layoutMain);
}

void LevelInfoEditor::editLevelName() {
    targetLevelInfo->levelName.setValue(levelNameEdit->text().toStdString());

    emit signaledUpdate();
}

void LevelInfoEditor::setTargetData(Nec::LevelInfo* const levelInfo) {
    targetLevelInfo = levelInfo;
}

void LevelInfoEditor::updateState() {
    levelNameEdit->setText(
        QString::fromStdString(targetLevelInfo->levelName.getValue())
    );
}

} // namespace App
