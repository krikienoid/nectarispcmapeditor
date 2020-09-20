#include "mainwindow.h"

namespace App {

std::string getFileExtension(const std::string&);

MainWindow::MainWindow() {
    necData    = new Nec::DataManager;
    editorMain = new EditorMain;

    editorMain->loadNecData(necData);

    setCentralWidget(editorMain);

    createActions();
    createMenus();
    createToolBars();
}

MainWindow::~MainWindow() {
    delete necData;
    delete editorMain;
}

void MainWindow::createActions() {
    // Open file
    actOpen = new QAction(tr("&Open..."), this);
    actOpen->setShortcuts(QKeySequence::Open);
    actOpen->setStatusTip(tr("Open an existing file"));

    connect(actOpen, SIGNAL(triggered()), this, SLOT(open()));

    // Save file
    actSave = new QAction(tr("&Save"), this);
    actSave->setShortcuts(QKeySequence::Save);
    actSave->setStatusTip(tr("Save the file to disk"));

    connect(actSave, SIGNAL(triggered()), this, SLOT(save()));

    // Save file as copy
    actSaveAs = new QAction(tr("Save &As..."), this);
    actSaveAs->setShortcuts(QKeySequence::SaveAs);
    actSaveAs->setStatusTip(tr("Save the file to a new location"));

    connect(actSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));

    // Exit Application
    actExit = new QAction(tr("E&xit"), this);
    actExit->setShortcuts(QKeySequence::Quit);
    actExit->setStatusTip(tr("Exit the application"));

    connect(actExit, SIGNAL(triggered()), this, SLOT(close()));

    // Zoom
    actZoomMapFull = new QAction(tr("Actual Size"), this);
    actZoomMapIn   = new QAction(tr("Zoom In"),     this);
    actZoomMapOut  = new QAction(tr("Zoom Out"),    this);
    actZoomMapFull->setShortcut(tr("Ctrl+0"));
    actZoomMapIn->setShortcut(tr("Ctrl++"));
    actZoomMapOut->setShortcut(tr("Ctrl+-"));

    connect(
        actZoomMapFull, SIGNAL(triggered()),
        editorMain,     SLOT(zoomMapFull())
    );

    connect(
        actZoomMapIn,   SIGNAL(triggered()),
        editorMain,     SLOT(zoomMapIn())
    );

    connect(
        actZoomMapOut,  SIGNAL(triggered()),
        editorMain,     SLOT(zoomMapOut())
    );

    // Show/Hide Grid
    actToggleMapGrid = new QAction(tr("Show Map Grid"), this);
    actToggleMapGrid->setCheckable(true);

    connect(
        actToggleMapGrid, SIGNAL(triggered(bool)),
        editorMain,       SLOT(toggleMapGrid(bool))
    );
}

void MainWindow::createMenus() {
    // File
    menuFile = menuBar()->addMenu(tr("&File"));
    menuFile->addAction(actOpen);
    menuFile->addAction(actSave);
    menuFile->addAction(actSaveAs);
    menuFile->addSeparator();
    menuFile->addAction(actExit);

    // View
    menuView = menuBar()->addMenu(tr("&View"));
    menuView->addAction(actZoomMapFull);
    menuView->addAction(actZoomMapIn);
    menuView->addAction(actZoomMapOut);
    menuView->addSeparator();
    menuView->addAction(actToggleMapGrid);

    // Window
    menuWindow = menuBar()->addMenu(tr("&Window"));
}

void MainWindow::createToolBars() {
    toolBarFile = addToolBar(tr("File"));
    toolBarFile->addAction(actOpen);
    toolBarFile->addAction(actSave);
}

void MainWindow::open() {
    // if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);

        loadFile(fileName);
    // }
}

bool MainWindow::save() {
    if (currentFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(currentFile);
    }
}

bool MainWindow::saveAs() {
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.exec();

    QStringList files = dialog.selectedFiles();

    if (files.isEmpty()) {
        return false;
    }

    return saveFile(files.at(0));
}

void MainWindow::setCurrentFile(const QString& fileName) {
    currentFile = fileName;
    // textEdit->document()->setModified(false);
    // setWindowModified(false);
    QString shownName = currentFile;

    if (currentFile.isEmpty()) {
        shownName = "biginfo.bin";
    }

    setWindowFilePath(shownName);
}

void MainWindow::loadFile(const QString& fileName) {
    #ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
    #endif

    // Check file extension
    std::string fileType = getFileExtension(fileName.toStdString());

    if (fileType != "bin") {
        QMessageBox::warning(
            this,
            tr("Nectaris PC Map Editor"),
            tr("cannot open file %1.").arg(fileName)
        );
    } else {
        // Load data from file
        delete necData;

        necData = new Nec::DataManager;
        necData->read(fileName.toStdString());

        editorMain->loadNecData(necData);

        // Finished loading
        setCurrentFile(fileName);
        statusBar()->showMessage(tr("File loaded"), 2000);
    }

    #ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
    #endif
}

bool MainWindow::saveFile(const QString& fileName) {
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(
            this,
            tr("Nectaris PC Map Editor"),
            tr("Cannot write file %1:\n%2.")
                .arg(fileName)
                .arg(file.errorString())
        );

        return false;
    }

    #ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
    #endif

    // Write data to file
    necData->write(fileName.toStdString());

    #ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
    #endif

    // Finished Saving
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);

    return true;
}

std::string getFileExtension(const std::string& fileName) {
    if (fileName.find_last_of(".") != std::string::npos) {
        return fileName.substr(fileName.find_last_of(".") + 1);
    }

    return "";
}

} // namespace App
