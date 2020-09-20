#ifndef APP_EDITORPLAYERS_H
#define APP_EDITORPLAYERS_H

#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QList>
#include <QSignalMapper>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/mapinfo.h"
#include "nec/playerrole.h"
#include "nec/playerstance.h"

namespace App {

class EditorPlayers : public QWidget {
    Q_OBJECT

public:
    explicit                    EditorPlayers(QWidget* parent = 0);

    void                        loadNecData(Nec::MapInfo*);
    void                        updateNecData();

signals:

public slots:
    void                        changePlayerRole(int);
    void                        changePlayerStance(int);

private:
    static const int            PLAYERS_COUNT = 4;

    QComboBox*                  createPlayerRoleComboBox();
    QComboBox*                  createPlayerStanceComboBox();
    void                        createPlayerRoleComboBoxes();
    void                        createPlayerStanceComboBoxes();

    QGroupBox*                  groupPlayerRole;
    QGroupBox*                  groupPlayerStance;
    QList<QComboBox*>           combosPlayerRole;
    QList<QComboBox*>           combosPlayerStance;

    Nec::MapInfo*               necMapInfo;
};

} // namespace App

#endif // APP_EDITORPLAYERS_H
