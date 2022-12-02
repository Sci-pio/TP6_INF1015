#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //caisse_ = new Model::CaisseEnregistreuse; // erreur "Allocation of incomplete type"
    ui->setupUi(this);
}

MainWindow:: MainWindow(Model::CaisseEnregistreuse* caisse, QWidget* parent) : QMainWindow(parent)
{
    caisse_ = caisse;
    caisseEstLocale_ = false;
    setup();
}

MainWindow::~MainWindow()
{
    if (caisseEstLocale_) {delete caisse_;}
    while (!articlesAjoutes_.empty()) {
        delete articlesAjoutes_.back();
        articlesAjoutes_.pop_back();
    }
    delete ui;
}

void MainWindow::setMenu()
{
    QAction* exit = new QAction(tr("E&xit"), this);
    exit -> setShortcuts(QKeySequence::Quit);
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exit);
}

void MainWindow::setup()
{
    setMenu();
}
