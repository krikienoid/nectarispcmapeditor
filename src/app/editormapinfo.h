#ifndef APP_EDITORMAPINFO_H
#define APP_EDITORMAPINFO_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/mapinfo.h"
#include "nec/mapname.h"

namespace App {

class EditorMapInfo : public QWidget {
    Q_OBJECT

public:
    explicit                    EditorMapInfo(QWidget* parent = 0);

    void                        loadNecData(Nec::MapInfo*);
    void                        updateNecData();

public slots:
    void                        enterMapName();

signals:
    void                        enteredMapName(const QString&);
    void                        signaledUpdate();

private:
    QLineEdit*                  editMapName;

    Nec::MapInfo*               necMapInfo;
};

} // namespace App

#endif // APP_EDITORMAPINFO_H
