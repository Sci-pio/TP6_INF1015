#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    caisse_ = new Model::CaisseEnregistreuse();
    ui->setupUi(this);
    miseEnPlaceMainWindow();
    miseEnPlacePrix();

    QObject::connect(caisse_, &Model::CaisseEnregistreuse::nouvelleInformation,
                     this, &MainWindow::rafraichirVue);

}

MainWindow::~MainWindow()
{
    delete caisse_;
}

void MainWindow::miseEnPlaceMainWindow()
{
    setWindowTitle("Caisse Enregristreuse INF1015:");
    afficherListeArticle();
}

void MainWindow::miseEnPlacePrix()
{
    double avTaxes = caisse_->avoirTotalPreTaxes();
    double taxes = 1; //REMPLACER LE 1 PAR FONCTION LAMDDA

    ui->totalAvantTaxes->setText(QString::number(avTaxes, 'f',2));
    ui->totalDesTaxes->setText(QString::number(taxes, 'f',2));
    ui->totalApayer->setText(QString::number(taxes * avTaxes, 'f',2));
}
void MainWindow::afficherListeArticle()
{
    ui->listArticle->clear();
    std::vector<Model::Article*> articles = caisse_->avoirListeArticle();

    for (auto elem: articles) {
        std::string affichage = elem->description + "\t" + std::to_string(elem->prix);

        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(affichage),ui->listArticle);
        item->setData(Qt::UserRole, QVariant::fromValue<Model::Article*>(elem));
    }

    ui->enleverBtn->setDisabled(articles.empty());
}
void MainWindow::rafraichirVue()
{
    afficherListeArticle();
    miseEnPlacePrix();
}

void MainWindow::on_validerBtn_clicked()
{
    Model::Article* article = new Model::Article;
    article->description = ui->LineEditDescription->text().toStdString();
    article->prix = ui->LineEditPrix->text().toDouble();
    article->taxable = ui->checkBoxTaxe->isChecked();

    caisse_->ajouterArticle(article);
}


void MainWindow::on_reinitialiserBtn_clicked()
{

}


void MainWindow::on_enleverBtn_clicked()
{
    std::vector<Model::Article*> aEnlever;

    for (QListWidgetItem *item : ui->listArticle->selectedItems()) {
        aEnlever.push_back(item->data(Qt::UserRole).value<Model::Article*>());
    }

    for(Model::Article* a: aEnlever){
        caisse_->retirerArticle(a);
    }
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


