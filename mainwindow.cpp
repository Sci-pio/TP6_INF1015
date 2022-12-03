#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    caisse_ = new Model::CaisseEnregistreuse();
    ui->setupUi(this);

    QObject::connect(caisse_, &Model::CaisseEnregistreuse::nouvelleInformation,
                     this, &MainWindow::rafraichirVue);
}

MainWindow::~MainWindow()
{
    delete caisse_;
}

void MainWindow::rafraichirVue()
{
     ui->console->appendPlainText("RAFRAICHIR");
}

void MainWindow::on_validerBtn_clicked()
{
    Model::Article* article = new Model::Article;
    article->description = ui->LineEditDescription->text().toStdString();
    article->prix = ui->LineEditPrix->text().toDouble();
    article->taxable = ui->checkBoxTaxe->isChecked();

    caisse_->ajouterArticle(article);
    ui->console->appendPlainText(QString::number(article->prix));
}


void MainWindow::on_reinitialiserBtn_clicked()
{

}


void MainWindow::on_enleverBtn_clicked()
{

}

//MainWindow:: MainWindow(Model::CaisseEnregistreuse* caisse, QWidget* parent) : QMainWindow(parent)
//{
//    caisse_ = caisse;
//    caisseEstLocale_ = false;
//    setup();
//}

//MainWindow::~MainWindow()
//{
//    if (caisseEstLocale_) {delete caisse_;}
//    while (!articlesAjoutes_.empty()) {
//        delete articlesAjoutes_.back();
//        articlesAjoutes_.pop_back();
//    }
//    delete ui;
//}


//void MainWindow::setMenu()
//{
//
//    QAction* exit = new QAction(tr("E&xit"), this);
//    exit -> setShortcuts(QKeySequence::Quit);
//    connect(exit, SIGNAL(triggered()), this, SLOT(close()));
//
//    QMenu* fileMenu = menuBar()->addMenu(tr("&Caisse Enregistreuse"));
//    fileMenu->addAction(exit);
//}
//
//void MainWindow::setUI()
//{
//    listeArticles_ = new QListWidget(this);
//    //connect(listeArticles_, SIGNAL(), this, SLOT() )
//
//}
// non utilisee si on utilise UI::setupUI();
//void MainWindow::setup()
//{
//    setMenu();
//    setUI();
//}


