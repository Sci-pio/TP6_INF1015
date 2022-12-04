#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Exception.h"

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
    delete ui;
}

void MainWindow::miseEnPlaceMainWindow()
{
    setWindowTitle("Caisse Enregristreuse INF1015:");
    afficherListeArticle();
}

void MainWindow::miseEnPlacePrix()
{
    double avTaxes = caisse_->avoirTotalPreTaxes();
    double taxes = caisse_->avoirTotalTaxes();

    ui->totalAvantTaxes->setText(QString::number(avTaxes, 'f',2));
    ui->totalDesTaxes->setText(QString::number(taxes, 'f',2));
    ui->totalApayer->setText(QString::number(taxes + avTaxes, 'f',2));
}

void MainWindow::afficherListeArticle()
{
    ui->listArticle->clear();
    std::vector<Model::Article*> articles = caisse_->avoirListeArticle();

    for (auto elem: articles) {
        std::string affichage = elem->description + "\t" + QString::number(elem->prix, 'f',2).toStdString();
        if (elem->taxable == true) {affichage += "\t taxable";}

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

// voir ch.7 p.24
void MainWindow::on_validerBtn_clicked()
{
    try {
        Model::Article* article = new Model::Article;
        article->description = ui->LineEditDescription->text().toStdString();
        article->prix = ui->LineEditPrix->text().toDouble();
        article->taxable = ui->checkBoxTaxe->isChecked();
        caisse_->ajouterArticle(article);

    } catch (Exception::ExceptionEntreeValeur& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Erreur d'entrée de valeur", e.what());
    }
}


void MainWindow::on_reinitialiserBtn_clicked()
{
    for (Model::Article* a : caisse_->avoirListeArticle()){
        caisse_->retirerArticle(a);
    }

    ui->listArticle->clear();
    ui->LineEditDescription->clear();
    ui->LineEditPrix->clear();
    ui->checkBoxTaxe->setChecked(false);
    ui->totalAvantTaxes->setText(QString::number(0, 'f',2));
    ui->totalDesTaxes->setText(QString::number(0, 'f',2));
    ui->totalApayer->setText(QString::number(0, 'f',2));
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



