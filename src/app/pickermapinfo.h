#ifndef APP_PICKERMAPINFO_H
#define APP_PICKERMAPINFO_H

#include <QBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QListWidget>
#include <QWidget>

#include "nec/datamanager.h"

namespace App {

class PickerMapInfo : public QWidget {
    Q_OBJECT

public:
    explicit                    PickerMapInfo(QWidget* parent = nullptr);

    void                        loadNecData(Nec::DataManager*);
    void                        updateNecData();

public slots:
    void                        clickMapList(QListWidgetItem*);

signals:
    void                        selectedMapInfo(int);

private:
    int                         getListItemData(QListWidgetItem*);
    void                        setListItemData(QListWidgetItem*, int);

    QListWidget*                listMapInfo;

    Nec::DataManager*           necData;
};

} // namespace App

#endif // APP_PICKERMAPINFO_H
