#ifndef APP_MAINWINDOW_H
#define APP_MAINWINDOW_H

#include <QAction>
#include <QApplication>
#include <QChar>
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

#include "nec/filedata.h"
#include "maineditor.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
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
    void                        initActions();
    void                        initMenus();
    void                        initToolBars();

    void                        setTargetFilePath(const QString&);
    void                        loadFile(const QString&);
    bool                        saveFile(const QString&);

    QString                     targetFilePath;

    QMenu*                      fileMenu;
    QMenu*                      editMenu;
    QMenu*                      viewMenu;
    QMenu*                      windowMenu;
    QMenu*                      helpMenu;
    QToolBar*                   fileToolBar;
    QToolBar*                   windowToolBar;
    QAction*                    openAction;
    QAction*                    saveAction;
    QAction*                    saveAsAction;
    QAction*                    exitAction;
    QAction*                    zoomMapFullAction;
    QAction*                    zoomMapInAction;
    QAction*                    zoomMapOutAction;
    QAction*                    toggleMapGridAction;

    MainEditor*                 mainEditor;

    Nec::FileData*              fileData;
};

} // namespace App

#endif // APP_MAINWINDOW_H
