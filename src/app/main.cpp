#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
    // Setup
    // Q_INIT_RESOURCE(application);
    QApplication app(argc, argv);
    app.setOrganizationName("QtProject");
    app.setApplicationName("Nectaris PC DOS Map Editor");

    // Initialize
    App::MainWindow mainWin;
    mainWin.setWindowTitle("Nectaris PC DOS Map Editor");
    mainWin.show();

    // Execute
    return app.exec();
}
