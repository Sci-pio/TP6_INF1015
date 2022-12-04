// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 4 decembre 2022
// Cours: INF1015
// Nom de la classe: mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>
#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include "CaisseEnregistreuse.h"
#include <cmath>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void miseEnPlaceMainWindow();
    void miseEnPlacePrix();
    void afficherListeArticle();

    Ui::MainWindow *ui;
    Model::CaisseEnregistreuse* caisse_;

public slots:
    void rafraichirVue();

private slots:
    void on_validerBtn_clicked();
    void on_reinitialiserBtn_clicked();
    void on_enleverBtn_clicked();
};

#endif
