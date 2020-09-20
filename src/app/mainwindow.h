#ifndef APP_MAINWINDOW_H
#define APP_MAINWINDOW_H

#include <string>

#include <QAction>
#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <QKeySequence>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QToolBar>
#include <QtWidgets>

#include "nec/datamanager.h"
#include "editormain.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
QT_END_NAMESPACE

namespace App {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
                                MainWindow();
                                ~MainWindow();

private slots:
    void                        open();
    bool                        save();
    bool                        saveAs();

private:
    void                        createActions();
    void                        createMenus();
    void                        createToolBars();

    void                        setCurrentFile(const QString& fileName);
    void                        loadFile(const QString& fileName);
    bool                        saveFile(const QString& fileName);

    QString                     currentFile;

    QMenu*                      menuFile;
    QMenu*                      menuEdit;
    QMenu*                      menuView;
    QMenu*                      menuWindow;
    QMenu*                      menuHelp;
    QToolBar*                   toolBarFile;
    QToolBar*                   toolBarWindow;
    QAction*                    actOpen;
    QAction*                    actSave;
    QAction*                    actSaveAs;
    QAction*                    actExit;
    QAction*                    actZoomMapFull;
    QAction*                    actZoomMapIn;
    QAction*                    actZoomMapOut;
    QAction*                    actToggleMapGrid;

    EditorMain*                 editorMain;

    Nec::DataManager*           necData;
};

} // namespace App

#endif // APP_MAINWINDOW_H
