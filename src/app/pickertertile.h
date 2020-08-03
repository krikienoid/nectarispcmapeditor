#ifndef NECMAPEDIT_PICKERTERTILE_H
#define NECMAPEDIT_PICKERTERTILE_H

// Dependencies

#include <QWidget>
#include <QComboBox>
#include <QListWidget>
#include <QFile>
#include <QList>
#include <QIcon>
#include <QByteArray>
#include "pixmaptertiles.h"
#include "tertype.h"

// Class

class PickerTerTile : public QListWidget {
    Q_OBJECT

public:

    explicit PickerTerTile       (QWidget * parent = 0);

    // Methods
    void     updateTilesetRanges ();

    // Children
    QComboBox * dropdownTerTypes;

    // Data
    QByteArray  bytesTerBin;
    QList<bool> enabledTilesetRange;

signals:

    void selectedTerTile (int);

public slots:

    void selectTerTile (QListWidgetItem *);
    void selectTerTypeFilter (int);

private:

    // Enums
    enum DATA_ROLES {
       TILE_TYPE = Qt::UserRole + 10,
       TER_TYPE  = Qt::UserRole + 11,
       TER_NAME  = Qt::UserRole + 12
    };

    // Data
    int terTypeFilter;

};

#endif // NECMAPEDIT_PICKERTERTILE_H
