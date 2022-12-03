#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>
#include <QListWidget>
#include <QLabel>
#include "CaisseEnregistreuse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(Model::CaisseEnregistreuse* caisse, QWidget* parent=0 );
    ~MainWindow();
public slots: // je les ai comment out pour que ca compile live mais on en aura besoin eventuellement
    //void articleAEteAjoute(Model::Article*);
    //void articleAEteRetire(Model::Article*);

private:
    // methodes de setup, voir d.33+, si on utilise UI::setupUI() je crois pas que cest necessaire
    void setup();
    void setMenu();
    void setUI();
    void chargerArticles();

    // stockage d'informations
    Model::CaisseEnregistreuse* caisse_;
    std::vector<Article*> articlesAjoutes_;
    bool caisseEstLocale_;

    // stockage d'elements graphiques
    Ui::MainWindow *ui; // ce truc vient avec la methode UI::setupUI() qui fait deja partie de QT, je crois que cest ca
    // qui permet dutiliser linterface graphique pour generer du code
    QLineEdit* descriptionArticle_;
    QLineEdit* prixArticle_;
    QPushButton* ajoutArticle_;
    QPushButton* retraitArticle_;
    QPushButton* reinitialisation_;
    QCheckBox* taxable_;
    QListWidget* listeArticles_;
    QLabel* totalPreTaxes;
    QLabel* totalTaxes;
    QLabel* grandTotal;
};


#endif // MAINWINDOW_H
