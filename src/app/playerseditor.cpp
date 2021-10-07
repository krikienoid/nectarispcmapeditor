#include "playerseditor.h"

namespace App {

PlayersEditor::PlayersEditor(QWidget* const parent) : QWidget(parent) {
    // Init
    initPlayerRoleComboBoxes();
    initPlayerAttitudeComboBoxes();

    // Layout
    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(playerRoleGroupBox);
    layoutMain->addWidget(playerAttitudeGroupBox);

    setLayout(layoutMain);
}

void PlayersEditor::editPlayerRole(const int i) {
    targetLevelInfo->playerRole[static_cast<std::size_t>(i)] =
        Nec::PlayerRole(static_cast<std::size_t>(
            playerRoleComboBoxes[i]->currentIndex()
        )).toByte();
}

void PlayersEditor::editPlayerAttitude(const int i) {
    targetLevelInfo->playerAttitude[static_cast<std::size_t>(i)] =
        Nec::PlayerAttitude(static_cast<std::size_t>(
            playerAttitudeComboBoxes[i]->currentIndex()
        )).toByte();
}

void PlayersEditor::setTargetData(Nec::LevelInfo* const levelInfo) {
    targetLevelInfo = levelInfo;
}

void PlayersEditor::updateState() {
    for (int i = 0, ii = playerAttitudeComboBoxes.size(); i < ii; ++i) {
        playerAttitudeComboBoxes[i]->setCurrentIndex(static_cast<int>(
            Nec::PlayerAttitude(
                targetLevelInfo->playerAttitude[static_cast<std::size_t>(i)].value()
            ).getIndex()
        ));
    }

    for (int i = 0, ii = playerRoleComboBoxes.size(); i < ii; ++i) {
        playerRoleComboBoxes[i]->setCurrentIndex(static_cast<int>(
            Nec::PlayerRole(
                targetLevelInfo->playerRole[static_cast<std::size_t>(i)].value()
            ).getIndex()
        ));
    }
}

QComboBox* PlayersEditor::createPlayerRoleComboBox() {
    const auto comboBox = new QComboBox(this);

    for (const auto& item : Nec::PlayerRole::DATA) {
        comboBox->addItem(QString::fromStdString(item.name));
    }

    return comboBox;
}

QComboBox* PlayersEditor::createPlayerAttitudeComboBox() {
    const auto comboBox = new QComboBox(this);

    for (const auto& item : Nec::PlayerAttitude::DATA) {
        comboBox->addItem(QString::fromStdString(item.name));
    }

    return comboBox;
}

void PlayersEditor::initPlayerRoleComboBoxes() {
    // Player Roles
    const auto layout = new QGridLayout();
    layout->setAlignment(Qt::AlignTop);

    // ComboBoxes
    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0; i < playerCount; ++i) {
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

    // Layout
    playerRoleGroupBox = new QGroupBox(tr("Player Role"), this);
    playerRoleGroupBox->setLayout(layout);
}

void PlayersEditor::initPlayerAttitudeComboBoxes() {
    // Player Attitudes
    const auto layout = new QGridLayout();
    layout->setAlignment(Qt::AlignTop);

    // Labels
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

    // ComboBoxes
    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0, k = 0; i < playerCount; ++i) {
        for (int j = 0; j < playerCount; ++j, ++k) {
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

            signalMapper->setMapping(comboBox, k);
            playerAttitudeComboBoxes.append(comboBox);
        }
    }

    connect(
        signalMapper, SIGNAL(mapped(int)),
        this,         SLOT(editPlayerAttitude(int))
    );

    // Layout
    playerAttitudeGroupBox = new QGroupBox(tr("Player Stance"), this);
    playerAttitudeGroupBox->setLayout(layout);
}

} // namespace App
