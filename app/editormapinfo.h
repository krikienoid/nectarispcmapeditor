#ifndef NECMAPEDIT_EDITORMAPINFO_H
#define NECMAPEDIT_EDITORMAPINFO_H

// Dependencies

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "necdatamanager.h"

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
