#ifndef NECMAPEDIT_PICKERMAPINFO_H
#define NECMAPEDIT_PICKERMAPINFO_H

// Dependencies

#include <QWidget>
#include <QBoxLayout>
#include <QListWidget>
#include <QGroupBox>
#include <QLabel>
#include "necdatamanager.h"

#include <QDebug>

// Class

class PickerMapInfo : public QWidget {
    Q_OBJECT

public:

    explicit PickerMapInfo   (QWidget * parent = 0);

    // Methods
    void     loadNecData     (Nec::DataManager *);
    void     updateNecData   ();

public slots:

    void     clickMapList         (QListWidgetItem *);

signals:

    void     selectedMapInfo   (int);

private:

    // Methods
    int      getListItemData (QListWidgetItem *);
    void     setListItemData (QListWidgetItem *, const int);

    // Children
    QListWidget      * listMapInfo;

    // Nec Data
    Nec::DataManager * necData;

};

#endif // NECMAPEDIT_PICKERMAPINFO_H
