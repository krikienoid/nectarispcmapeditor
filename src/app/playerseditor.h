#ifndef APP_PLAYERSEDITOR_H
#define APP_PLAYERSEDITOR_H

#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QList>
#include <QSignalMapper>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/levelinfo.h"
#include "nec/playerattitude.h"
#include "nec/playerrole.h"

namespace App {

class PlayersEditor : public QWidget {
    Q_OBJECT

public:
    explicit                    PlayersEditor(QWidget* parent = nullptr);

    void                        setTargetData(Nec::LevelInfo*);
    void                        updateState();

public slots:
    void                        editPlayerRole(int);
    void                        editPlayerAttitude(int);

private:
    static constexpr int playerCount =
        static_cast<int>(Nec::LevelInfo::playerCount);

    QComboBox*                  createPlayerRoleComboBox();
    QComboBox*                  createPlayerAttitudeComboBox();
    void                        initPlayerRoleComboBoxes();
    void                        initPlayerAttitudeComboBoxes();

    QGroupBox*                  playerRoleGroupBox;
    QGroupBox*                  playerAttitudeGroupBox;
    QList<QComboBox*>           playerRoleComboBoxes;
    QList<QComboBox*>           playerAttitudeComboBoxes;

    Nec::LevelInfo*             targetLevelInfo;
};

} // namespace App

#endif // APP_PLAYERSEDITOR_H
