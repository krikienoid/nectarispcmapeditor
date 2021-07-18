#include "editorplayers.h"

namespace App {

EditorPlayers::EditorPlayers(QWidget* const parent) : QWidget(parent) {
    // Init
    createPlayerRoleComboBoxes();
    createPlayerStanceComboBoxes();

    // Layout
    const auto layoutMain = new QVBoxLayout();
    layoutMain->addWidget(groupPlayerRole);
    layoutMain->addWidget(groupPlayerStance);

    setLayout(layoutMain);
}

void EditorPlayers::changePlayerRole(const int i) {
    necMapInfo->playerRole[static_cast<std::size_t>(i)] =
        Nec::PlayerRole(static_cast<std::size_t>(
            combosPlayerRole[i]->currentIndex()
        )).toByte();
}

void EditorPlayers::changePlayerStance(const int i) {
    necMapInfo->playerStance[static_cast<std::size_t>(i)] =
        Nec::PlayerStance(static_cast<std::size_t>(
            combosPlayerStance[i]->currentIndex()
        )).toByte();
}

void EditorPlayers::loadNecData(Nec::MapInfo* const mapInfo) {
    necMapInfo = mapInfo;
}

void EditorPlayers::updateNecData() {
    for (int i = 0, ii = combosPlayerStance.size(); i < ii; ++i) {
        combosPlayerStance[i]->setCurrentIndex(static_cast<int>(
            Nec::PlayerStance(
                necMapInfo->playerStance[static_cast<std::size_t>(i)].value()
            ).getIndex()
        ));
    }

    for (int i = 0, ii = combosPlayerRole.size(); i < ii; ++i) {
        combosPlayerRole[i]->setCurrentIndex(static_cast<int>(
            Nec::PlayerRole(
                necMapInfo->playerRole[static_cast<std::size_t>(i)].value()
            ).getIndex()
        ));
    }
}

QComboBox* EditorPlayers::createPlayerRoleComboBox() {
    const auto newComboBox = new QComboBox(this);

    for (const auto& item : Nec::PlayerRole::DATA) {
        newComboBox->addItem(QString::fromStdString(item.name));
    }

    return newComboBox;
}

QComboBox* EditorPlayers::createPlayerStanceComboBox() {
    const auto newComboBox = new QComboBox(this);

    for (const auto& item : Nec::PlayerStance::DATA) {
        newComboBox->addItem(QString::fromStdString(item.name));
    }

    return newComboBox;
}

void EditorPlayers::createPlayerRoleComboBoxes() {
    // Player Roles
    const auto layoutGridPlayerRoles = new QGridLayout();
    layoutGridPlayerRoles->setAlignment(Qt::AlignTop);

    // ComboBoxes
    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0; i < PLAYER_COUNT; ++i) {
        const auto newComboBoxPlayerRole = createPlayerRoleComboBox();

        layoutGridPlayerRoles->addWidget(
            new QLabel(QString("P") + QString::number(i + 1)),
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
    const auto layoutGridPlayerStances = new QGridLayout();
    layoutGridPlayerStances->setAlignment(Qt::AlignTop);

    // Labels
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        layoutGridPlayerStances->addWidget(
            new QLabel(QString("P") + QString::number(i + 1)),
            0,
            i + 1
        );

        layoutGridPlayerStances->addWidget(
            new QLabel(QString("P") + QString::number(i + 1)),
            i + 1,
            0
        );
    }

    // ComboBoxes
    const auto signalMapper = new QSignalMapper(this);

    for (int i = 0, k = 0; i < PLAYER_COUNT; ++i) {
        for (int j = 0; j < PLAYER_COUNT; ++j, ++k) {
            const auto newComboBoxPlayerStance = createPlayerStanceComboBox();

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
