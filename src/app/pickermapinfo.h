#ifndef NECMAPEDIT_PICKERMAPINFO_H
#define NECMAPEDIT_PICKERMAPINFO_H

// Dependencies

#include <QGroupBox>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QVBoxLayout>
#include <QVariant>
#include <QWidget>

#include "nec/biginfo.h"
#include "nec/datamanager.h"

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
