#ifndef APP_LEVELINFOSELECTOR_H
#define APP_LEVELINFOSELECTOR_H

#include <QGroupBox>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QVBoxLayout>
#include <QVariant>
#include <QWidget>

#include "nec/biginfo.h"
#include "nec/filedata.h"

namespace App {

class LevelInfoSelector : public QWidget {
    Q_OBJECT

public:
    explicit                    LevelInfoSelector(QWidget* parent = nullptr);

    void                        setTargetData(const Nec::FileData*);
    void                        updateState();

public slots:
    void                        clickList(QListWidgetItem*);

signals:
    void                        selectedLevelInfo(int);

private:
    enum DataRole {
        LevelInfoIndexDataRole  = Qt::UserRole + 1
    };

    int                         getItemData(QListWidgetItem*);
    void                        setItemData(QListWidgetItem*, int);

    QListWidget*                levelInfoList;

    const Nec::FileData*        targetFileData;
};

} // namespace App

#endif // APP_LEVELINFOSELECTOR_H
