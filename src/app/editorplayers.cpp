#include "editorplayers.h"

namespace App {

EditorPlayers::EditorPlayers(QWidget* parent) : QWidget(parent) {
    // Init
    createPlayerRoleComboBoxes();
    createPlayerStanceComboBoxes();

    // Layout
    QVBoxLayout* layoutMain = new QVBoxLayout;
    layoutMain->addWidget(groupPlayerRole);
    layoutMain->addWidget(groupPlayerStance);

    setLayout(layoutMain);
}

void EditorPlayers::changePlayerRole(int i) {
    necMapInfo->playerRole[i] =
        Nec::PlayerRole(combosPlayerRole[i]->currentIndex()).toByte();
}

void EditorPlayers::changePlayerStance(int i) {
    necMapInfo->playerStance[i] =
        Nec::PlayerStance(combosPlayerStance[i]->currentIndex()).toByte();
}

void EditorPlayers::loadNecData(Nec::MapInfo* mapInfo) {
    necMapInfo = mapInfo;
}

void EditorPlayers::updateNecData() {
    for (int i = 0, ii = combosPlayerStance.size(); i < ii; ++i) {
        combosPlayerStance[i]->setCurrentIndex(
            Nec::PlayerStance(necMapInfo->playerStance[i]).getIndex()
        );
    }

    for (int i = 0, ii = combosPlayerRole.size(); i < ii; ++i) {
        combosPlayerRole[i]->setCurrentIndex(
            Nec::PlayerRole(necMapInfo->playerRole[i]).getIndex()
        );
    }
}

QComboBox* EditorPlayers::createPlayerRoleComboBox() {
    QComboBox* newComboBox = new QComboBox(this);

    for (int i = 0, ii = Nec::PlayerRole::DATA.size(); i < ii; ++i) {
        newComboBox->addItem(
            QString::fromStdString(Nec::PlayerRole::DATA[i].name)
        );
    }

    return newComboBox;
}

QComboBox* EditorPlayers::createPlayerStanceComboBox() {
    QComboBox* newComboBox = new QComboBox(this);

    for (int i = 0, ii = Nec::PlayerStance::DATA.size(); i < ii; ++i) {
        newComboBox->addItem(
            QString::fromStdString(Nec::PlayerStance::DATA[i].name)
        );
    }

    return newComboBox;
}

void EditorPlayers::createPlayerRoleComboBoxes() {
    // Player Roles
    QGridLayout* layoutGridPlayerRoles = new QGridLayout;
    layoutGridPlayerRoles->setAlignment(Qt::AlignTop);

    // ComboBoxes
    QSignalMapper* signalMapper = new QSignalMapper(this);

    for (int i = 0; i < PLAYERS_COUNT; ++i) {
        QComboBox* newComboBoxPlayerRole = createPlayerRoleComboBox();

        layoutGridPlayerRoles->addWidget(
            new QLabel("P" + QString::number(i + 1)),
            0,
            i + 1
        );

        layoutGridPlayerRoles->addWidget(newComboBoxPlayerRole, 1, i + 1);

        connect(
            newComboBoxPlayerRole, SIGNAL(currentIndexChanged(int)),
            signalMapper,          SLOT(map())
        );

        signalMapper->setMapping(newComboBoxPlayerRole, i);
        combosPlayerRole.append(newComboBoxPlayerRole);
    }

    connect(
        signalMapper, SIGNAL(mapped(int)),
        this,         SLOT(changePlayerRole(int))
    );

    // Layout
    groupPlayerRole = new QGroupBox(tr("Player Role"), this);
    groupPlayerRole->setLayout(layoutGridPlayerRoles);
}

void EditorPlayers::createPlayerStanceComboBoxes() {
    // Player Stances
    QGridLayout* layoutGridPlayerStances = new QGridLayout;
    layoutGridPlayerStances->setAlignment(Qt::AlignTop);

    // Labels
    for (int i = 0; i < PLAYERS_COUNT; ++i) {
        layoutGridPlayerStances->addWidget(
            new QLabel("P" + QString::number(i + 1)),
            0,
            i + 1
        );

        layoutGridPlayerStances->addWidget(
            new QLabel("P" + QString::number(i + 1)),
            i + 1,
            0
        );
    }

    // ComboBoxes
    QSignalMapper* signalMapper = new QSignalMapper(this);

    for (int i = 0, k = 0; i < PLAYERS_COUNT; ++i) {
        for (int j = 0; j < PLAYERS_COUNT; ++j, ++k) {
            QComboBox* newComboBoxPlayerStance =
                createPlayerStanceComboBox();

            layoutGridPlayerStances->addWidget(
                newComboBoxPlayerStance,
                i + 1,
                j + 1
            );

            connect(
                newComboBoxPlayerStance, SIGNAL(currentIndexChanged(int)),
                signalMapper,            SLOT(map())
            );

            signalMapper->setMapping(newComboBoxPlayerStance, k);
            combosPlayerStance.append(newComboBoxPlayerStance);
        }
    }

    connect(
        signalMapper, SIGNAL(mapped(int)),
        this,         SLOT(changePlayerStance(int))
    );

    // Layout
    groupPlayerStance = new QGroupBox(tr("Player Stance"), this);
    groupPlayerStance->setLayout(layoutGridPlayerStances);
}

} // namespace App
