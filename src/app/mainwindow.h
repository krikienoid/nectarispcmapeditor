#ifndef NECMAPEDIT_MAINWINDOW_H
#define NECMAPEDIT_MAINWINDOW_H

// Dependencies

#include <QMainWindow>
#include <QtWidgets>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include "editormain.h"
#include "datamanager.h"

#include <QDebug>

// Qt Stuff

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

// Class

class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    MainWindow  ();
    ~MainWindow ();

private slots:

    void open           ();
    bool save           ();
    bool saveAs         ();

private:

    // Methods
    void createActions  ();
    void createMenus    ();
    void createToolBars ();

    void setCurrentFile (const QString& fileName);
    void loadFile       (const QString& fileName);
    bool saveFile       (const QString& fileName);

    // Filename
    QString currentFile;

    // Window UI
    QMenu    * menuFile;
    QMenu    * menuEdit;
    QMenu    * menuView;
    QMenu    * menuWindow;
    QMenu    * menuHelp;
    QToolBar * toolBarFile;
    QToolBar * toolBarWindow;
    QAction  * actOpen;
    QAction  * actSave;
    QAction  * actSaveAs;
    QAction  * actExit;
    QAction  * actZoomMapFull;
    QAction  * actZoomMapIn;
    QAction  * actZoomMapOut;
    QAction  * actToggleMapGrid;

    // Children
    EditorMain       * editorMain;

    // Nec Data
    Nec::DataManager * necData;

};

#endif // NECMAPEDIT_MAINWINDOW_H
