#include "mainwindow.h"

namespace App {

QString getFileExtension(const QString&);

MainWindow::MainWindow() {
    fileData   = new Nec::FileData();
    mainEditor = new MainEditor();

    mainEditor->setTargetData(fileData);

    setCentralWidget(mainEditor);

    initActions();
    initMenus();
    initToolBars();
}

MainWindow::~MainWindow() {
    delete fileData;
    delete mainEditor;
}

void MainWindow::initActions() {
    // Open file
    openAction = new QAction(tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    // Save file
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the file to disk"));

    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    // Save file as copy
    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setShortcuts(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the file to a new location"));

    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    // Exit Application
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));

    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    // Zoom
    zoomMapFullAction = new QAction(tr("Actual Size"), this);
    zoomMapInAction   = new QAction(tr("Zoom In"),     this);
    zoomMapOutAction  = new QAction(tr("Zoom Out"),    this);
    zoomMapFullAction->setShortcut(tr("Ctrl+0"));
    zoomMapInAction->setShortcut(tr("Ctrl++"));
    zoomMapOutAction->setShortcut(tr("Ctrl+-"));

    connect(
        zoomMapFullAction, SIGNAL(triggered()),
        mainEditor,        SLOT(zoomMapFull())
    );

    connect(
        zoomMapInAction,   SIGNAL(triggered()),
        mainEditor,        SLOT(zoomMapIn())
    );

    connect(
        zoomMapOutAction,  SIGNAL(triggered()),
        mainEditor,        SLOT(zoomMapOut())
    );

    // Show/Hide Grid
    toggleMapGridAction = new QAction(tr("Show Map Grid"), this);
    toggleMapGridAction->setCheckable(true);

    connect(
        toggleMapGridAction, SIGNAL(triggered(bool)),
        mainEditor,          SLOT(toggleMapGrid(bool))
    );
}

void MainWindow::initMenus() {
    // File
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    // View
    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(zoomMapFullAction);
    viewMenu->addAction(zoomMapInAction);
    viewMenu->addAction(zoomMapOutAction);
    viewMenu->addSeparator();
    viewMenu->addAction(toggleMapGridAction);

    // Window
    windowMenu = menuBar()->addMenu(tr("&Window"));
}

void MainWindow::initToolBars() {
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);
}

void MainWindow::open() {
    // if (maybeSave()) {
        const QString filePath = QFileDialog::getOpenFileName(this);

        loadFile(filePath);
    // }
}

bool MainWindow::save() {
    if (targetFilePath.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(targetFilePath);
    }
}

bool MainWindow::saveAs() {
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.exec();

    const QStringList files = dialog.selectedFiles();

    if (files.isEmpty()) {
        return false;
    }

    return saveFile(files[0]);
}

void MainWindow::setTargetFilePath(const QString& filePath) {
    targetFilePath = filePath;
    // textEdit->document()->setModified(false);
    // setWindowModified(false);
    QString displayedFilename = targetFilePath;

    if (targetFilePath.isEmpty()) {
        displayedFilename = "biginfo.bin";
    }

    setWindowFilePath(displayedFilename);
}

void MainWindow::loadFile(const QString& filePath) {
    #ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
    #endif

    // Check file extension
    const QString fileType = getFileExtension(filePath);

    if (fileType != "bin") {
        QMessageBox::warning(
            this,
            tr("Nectaris PC Map Editor"),
            tr("cannot open file %1.").arg(filePath)
        );
    } else {
        // Load data from file
        delete fileData;

        fileData = new Nec::FileData();
        fileData->read(filePath.toStdString());

        mainEditor->setTargetData(fileData);

        // Finished loading
        setTargetFilePath(filePath);
        statusBar()->showMessage(tr("File loaded"), 2000);
    }

    #ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
    #endif
}

bool MainWindow::saveFile(const QString& filePath) {
    QFile file(filePath);

    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(
            this,
            tr("Nectaris PC Map Editor"),
            tr("Cannot write file %1:\n%2.")
                .arg(filePath, file.errorString())
        );

        return false;
    }

    #ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
    #endif

    // Write data to file
    fileData->write(filePath.toStdString());

    #ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
    #endif

    // Finished Saving
    setTargetFilePath(filePath);
    statusBar()->showMessage(tr("File saved"), 2000);

    return true;
}

QString getFileExtension(const QString& filePath) {
    const auto pos = filePath.lastIndexOf(QChar('.'));

    if (pos != -1 && pos + 1 < filePath.size()) {
        return filePath.mid(pos + 1);
    }

    return QString("");
}

} // namespace App
