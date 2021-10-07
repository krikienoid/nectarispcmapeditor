#ifndef APP_MAINEDITOR_H
#define APP_MAINEDITOR_H

#include <QHBoxLayout>
#include <QSplitter>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "nec/filedata.h"
#include "nec/tertype.h"
#include "levelinfoeditor.h"
#include "levelinfoselector.h"
#include "levelmapeditor.h"
#include "playerseditor.h"

namespace App {

class MainEditor : public QWidget {
    Q_OBJECT

public:
    explicit                    MainEditor(QWidget* parent = nullptr);

    void                        setTargetData(Nec::FileData*);
    void                        updateState();
    void                        zoomMap(double, bool);

public slots:
    void                        selectLevelInfo(int);
    void                        signalUpdate();

    void                        zoomMapFull();
    void                        zoomMapIn();
    void                        zoomMapOut();
    void                        toggleMapGrid(bool);

private:
    void                        loadSelectedLevelData(int);

    LevelInfoEditor*            levelInfoEditor;
    LevelInfoSelector*          levelInfoSelector;
    LevelMapEditor*             levelMapEditor;
    PlayersEditor*              playersEditor;

    Nec::FileData*              targetFileData;
};

} // namespace App

#endif // APP_MAINEDITOR_H
