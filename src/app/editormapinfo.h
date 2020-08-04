#ifndef NECMAPEDIT_EDITORMAPINFO_H
#define NECMAPEDIT_EDITORMAPINFO_H

// Dependencies

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/mapinfo.h"
#include "nec/mapname.h"

// Class

class EditorMapInfo : public QWidget {
    Q_OBJECT

public:

    explicit EditorMapInfo  (QWidget * parent = 0);

    // Methods
    void     loadNecData    (Nec::MapInfo *);
    void     updateNecData  ();

public slots:

    void     enterMapName ();

signals:

    void     enteredMapName   (const QString&);
    void     signaledUpdate   ();

private:

    // Children
    QLineEdit    * editMapName;

    // Nec Data
    Nec::MapInfo * necMapInfo;

};

#endif // NECMAPEDIT_EDITORMAPINFO_H
