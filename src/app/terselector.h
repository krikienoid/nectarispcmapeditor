#ifndef APP_TERSELECTOR_H
#define APP_TERSELECTOR_H

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
#include "constants.h"
#include "tertilespixmap.h"

namespace App {

class TerSelector : public QListWidget {
    Q_OBJECT

public:
    explicit                    TerSelector(QWidget* parent = nullptr);

    void                        updateActiveTilesets();

    QComboBox*                  terFilterGroupComboBox;

    QByteArray                  terData;
    QList<bool>                 tilesetSelections;

public slots:
    void                        selectTer(QListWidgetItem*);
    void                        selectTerFilterGroup(int);

signals:
    void                        selectedTer(int);

private:
    enum DataRole {
        TerIndexDataRole        = Qt::UserRole + 10,
        TerTypeDataRole         = Qt::UserRole + 11,
        TerNameDataRole         = Qt::UserRole + 12
    };

    int                         selectedTerFilterGroup;
};

} // namespace App

#endif // APP_TERSELECTOR_H
