#ifndef NECMAPEDIT_EDITORPLAYERS_H
#define NECMAPEDIT_EDITORPLAYERS_H

// Dependencies

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QList>
#include <QSignalMapper>
#include <QComboBox>
#include "necdatamanager.h"
#include "necplayerstance.h"
#include "necplayerrole.h"

// Class

class EditorPlayers : public QWidget {
    Q_OBJECT

public:

    explicit EditorPlayers (QWidget * parent = 0);

    // Methods
    void     loadNecData    (Nec::MapInfo *);
    void     updateNecData  ();

signals:

public slots:

    void changePlayerRole   (int);
    void changePlayerStance (int);

private:

    // Static Data
    static const int PLAYERS_COUNT = 4;

    // Methods
    QComboBox * createPlayerRoleComboBox     ();
    QComboBox * createPlayerStanceComboBox   ();
    void        createPlayerRoleComboBoxes   ();
    void        createPlayerStanceComboBoxes ();

    // Children
    QGroupBox        * groupPlayerRole;
    QGroupBox        * groupPlayerStance;
    QList<QComboBox *> combosPlayerRole;
    QList<QComboBox *> combosPlayerStance;

    // Nec Data
    Nec::MapInfo * necMapInfo;

};

#endif // NECMAPEDIT_EDITORPLAYERS_H
