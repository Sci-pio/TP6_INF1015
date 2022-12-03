#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>
#include <QApplication>
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
    ~MainWindow();
    //MainWindow(Model::CaisseEnregistreuse* caisse, QWidget* parent=0 ); Leo: dans qu'elle situation ont en a besoin?

private:
    void setUpListe();

    Ui::MainWindow *ui;
    Model::CaisseEnregistreuse* caisse_;

public slots: // je les ai comment out pour que ca compile live mais on en aura besoin eventuellement
    void rafraichirVue();
    //void articleAEteAjoute(Model::Article*);
    //void articleAEteRetire(Model::Article*);

private slots:
    void on_validerBtn_clicked();
    void on_reinitialiserBtn_clicked();
    void on_enleverBtn_clicked();

    // methodes de setup, voir d.33+, si on utilise UI::setupUI() je crois pas que cest necessaire
    //void setMenu();
    //void setUI();
    //void chargerArticles();

    // stockage d'informations
    //bool caisseEstLocale_;

    //QLineEdit* descriptionArticle_;
    //QLineEdit* prixArticle_;
    //QPushButton* ajoutArticle_;
    //QPushButton* retraitArticle_;
    //QPushButton* reinitialisation_;
    //QCheckBox* taxable_;
    //QListWidget* listeArticles_;
    //QLabel* totalPreTaxes;
    //QLabel* totalTaxes;
    //QLabel* grandTotal;
};


#endif // MAINWINDOW_H
