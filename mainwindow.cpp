#include "mainwindow.h"
#include "CaisseEnregistreuse.h"
#include "ui_mainwindow.h"
#include <QGuiApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    using namespace Model;
    //caisse_ = new Model::CaisseEnregistreuse(); // erreur "Allocation of incomplete type"
    caisseEstLocale_ = true;
    //setup(); // on ne va pas utiliser MainWindow::setup() si on utilise UI::setupUI(), a determiner
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

    QMenu* fileMenu = menuBar()->addMenu(tr("&Caisse Enregistreuse"));
    fileMenu->addAction(exit);
}

void MainWindow::setUI()
{
    listeArticles_ = new QListWidget(this);
    //connect(listeArticles_, SIGNAL(), this, SLOT() )

}
// non utilisee si on utilise UI::setupUI();
void MainWindow::setup()
{
    setMenu();
    setUI();
}
