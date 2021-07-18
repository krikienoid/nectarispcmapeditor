#ifndef APP_PICKERTERTILE_H
#define APP_PICKERTERTILE_H

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

class PickerTerTile : public QListWidget {
    Q_OBJECT

public:
    explicit                    PickerTerTile(QWidget* parent = nullptr);

    void                        updateTilesetRanges();

    QComboBox*                  dropdownTerTypes;

    QByteArray                  bytesTerBin;
    QList<bool>                 enabledTilesetRange;

public slots:
    void                        selectTerTile(QListWidgetItem*);
    void                        selectTerTypeFilter(int);

signals:
    void                        selectedTerTile(int);

private:
    enum class DATA_ROLES {
        TILE_TYPE = Qt::UserRole + 10,
        TER_TYPE  = Qt::UserRole + 11,
        TER_NAME  = Qt::UserRole + 12
    };

    int                         terTypeFilter;
};

} // namespace App

#endif // APP_PICKERTERTILE_H