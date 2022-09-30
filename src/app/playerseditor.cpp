#include "playerseditor.h"

namespace App {

PlayersEditor::PlayersEditor(QWidget* const parent) : QWidget(parent) {
    initPlayerRoleComboBoxes();
    initPlayerAttitudeComboBoxes();

    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(playerRoleGroupBox);
    layoutMain->addWidget(playerAttitudeGroupBox);

    setLayout(layoutMain);
}

void PlayersEditor::editPlayerRole(const int i) {
    const auto comboBox = playerRoleComboBoxes[i];

    targetLevelInfo->playerRoles[static_cast<std::size_t>(i)].setValue(
        comboBox->itemData(comboBox->currentIndex()).toInt()
    );
}

void PlayersEditor::editPlayerAttitude(const int i) {
    const auto comboBox = playerAttitudeComboBoxes[i];

    targetLevelInfo->playerAttitudes[static_cast<std::size_t>(i)].setValue(
        comboBox->itemData(comboBox->currentIndex()).toInt()
    );
}

void PlayersEditor::setTargetData(Nec::LevelInfo* const levelInfo) {
    targetLevelInfo = levelInfo;
}

void PlayersEditor::updateState() {
    for (int i = 0, ii = playerAttitudeComboBoxes.size(); i < ii; ++i) {
        const auto comboBox = playerAttitudeComboBoxes[i];

        comboBox->setCurrentIndex(comboBox->findData(QVariant(static_cast<int>(
            targetLevelInfo->playerAttitudes[static_cast<std::size_t>(i)].getValue()
        ))));
    }

    for (int i = 0, ii = playerRoleComboBoxes.size(); i < ii; ++i) {
        const auto comboBox = playerRoleComboBoxes[i];

        comboBox->setCurrentIndex(comboBox->findData(QVariant(static_cast<int>(
            targetLevelInfo->playerRoles[static_cast<std::size_t>(i)].getValue()
        ))));
    }
}

QComboBox* PlayersEditor::createPlayerRoleComboBox() {
    const auto comboBox = new QComboBox(this);

    for (const auto& item : Nec::PlayerRole::data) {
        comboBox->addItem(
            QString::fromStdString(item.name),
            QVariant(static_cast<int>(item.value.getValue()))
        );
    }

    return comboBox;
}

QComboBox* PlayersEditor::createPlayerAttitudeComboBox() {
    const auto comboBox = new QComboBox(this);

    for (const auto& item : Nec::PlayerAttitude::data) {
        comboBox->addItem(
            QString::fromStdString(item.name),
            QVariant(static_cast<int>(item.value.getValue()))
        );
    }

    return comboBox;
}

void PlayersEditor::initPlayerRoleComboBoxes() {
    const auto layout = new QGridLayout();
    layout->setAlignment(Qt::AlignTop);

    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0; i < static_cast<int>(Nec::LevelInfo::playerCount); ++i) {
        const auto comboBox = createPlayerRoleComboBox();

        layout->addWidget(
            new QLabel(QString("P") + QString::number(i + 1)),
            0,
            i + 1
        );

        layout->addWidget(comboBox, 1, i + 1);

        connect(
            comboBox,     SIGNAL(currentIndexChanged(int)),
            signalMapper, SLOT(map())
        );

        signalMapper->setMapping(comboBox, i);
        playerRoleComboBoxes.append(comboBox);
    }

    connect(
        signalMapper, SIGNAL(mapped(int)),
        this,         SLOT(editPlayerRole(int))
    );

    playerRoleGroupBox = new QGroupBox(tr("Player roles"), this);
    playerRoleGroupBox->setLayout(layout);
}

void PlayersEditor::initPlayerAttitudeComboBoxes() {
    constexpr int playerCount = static_cast<int>(Nec::LevelInfo::playerCount);

    const auto layout = new QGridLayout();
    layout->setAlignment(Qt::AlignTop);

    for (int i = 0; i < playerCount; ++i) {
        layout->addWidget(
            new QLabel(QString("P") + QString::number(i + 1)),
            0,
            i + 1
        );

        layout->addWidget(
            new QLabel(QString("P") + QString::number(i + 1)),
            i + 1,
            0
        );
    }

    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0; i < playerCount; ++i) {
        for (int j = 0; j < playerCount; ++j) {
            const auto comboBox = createPlayerAttitudeComboBox();

            layout->addWidget(
                comboBox,
                i + 1,
                j + 1
            );

            connect(
                comboBox,     SIGNAL(currentIndexChanged(int)),
                signalMapper, SLOT(map())
            );

            signalMapper->setMapping(comboBox, i * playerCount + j);
            playerAttitudeComboBoxes.append(comboBox);
        }
    }

    connect(
        signalMapper, SIGNAL(mapped(int)),
        this,         SLOT(editPlayerAttitude(int))
    );

    playerAttitudeGroupBox = new QGroupBox(tr("Player attitudes"), this);
    playerAttitudeGroupBox->setLayout(layout);
}

} // namespace App
