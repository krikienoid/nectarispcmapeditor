#ifndef APP_LEVELINFOEDITOR_H
#define APP_LEVELINFOEDITOR_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/levelinfo.h"
#include "nec/levelname.h"

namespace App {

class LevelInfoEditor : public QWidget {
    Q_OBJECT

public:
    explicit                    LevelInfoEditor(QWidget* parent = nullptr);

    void                        setTargetData(Nec::LevelInfo*);
    void                        updateState();

public slots:
    void                        editLevelName();

signals:
    void                        editedLevelName(const QString&);
    void                        signaledUpdate();

private:
    QLineEdit*                  levelNameEdit;

    Nec::LevelInfo*             targetLevelInfo;
};

} // namespace App

#endif // APP_LEVELINFOEDITOR_H
