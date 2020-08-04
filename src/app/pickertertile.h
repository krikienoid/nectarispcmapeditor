#ifndef APP_PICKERTERTILE_H
#define APP_PICKERTERTILE_H

// Dependencies

#include <QByteArray>
#include <QComboBox>
#include <QFile>
#include <QIcon>
#include <QIODevice>
#include <QList>
#include <QListView>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSize>
#include <QString>
#include <QVariant>
#include <QWidget>

#include "nec/tertype.h"
#include "pixmaptertiles.h"

namespace App {

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

} // namespace App

#endif // APP_PICKERTERTILE_H
