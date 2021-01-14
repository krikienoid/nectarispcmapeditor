#ifndef APP_PICKERMAPINFO_H
#define APP_PICKERMAPINFO_H

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

namespace App {

class PickerMapInfo : public QWidget {
    Q_OBJECT

public:
    explicit                    PickerMapInfo(QWidget* parent = nullptr);

    void                        loadNecData(const Nec::DataManager*);
    void                        updateNecData();

public slots:
    void                        clickMapList(QListWidgetItem*);

signals:
    void                        selectedMapInfo(int);

private:
    int                         getListItemData(QListWidgetItem*);
    void                        setListItemData(QListWidgetItem*, int);

    QListWidget*                listMapInfo;

    const Nec::DataManager*     necData;
};

} // namespace App

#endif // APP_PICKERMAPINFO_H
