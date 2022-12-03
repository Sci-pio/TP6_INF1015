#ifndef CAISSEENREGISTREUSE_H
#define CAISSEENREGISTREUSE_H
#include <QMainWindow>
#include <QBoxLayout>
#include <vector>

namespace Model {

struct Article{
    std::string description;
    double prix;
    bool taxable;

    // pour l'iteration sur vecteur de Articles (yavait des erreurs sinon)
    bool operator==(const Article& a) const
    {
        if ((description == a.description) && (prix == a.prix) && (taxable == a.taxable)) {return true;}
        return false;
    }
};

class CaisseEnregistreuse: public QObject
{
    Q_OBJECT

public:
    CaisseEnregistreuse() = default;
    ~CaisseEnregistreuse();

    void ajouterArticle(Article* article);
    void retirerArticle(Article* article);

    std::vector<Article*> avoirListeArticle() const;
    double avoirTotalPreTaxes(){return totalPreTaxes_;};
    //double totalTaxes = [](*this) {return totalPreTaxes_ * 0.14975;};

private:
    std::vector<Article*> articleConteneur_;
    double totalPreTaxes_;
    double totalTaxesTemp_ = 0; // jarrive pas a implementer comme ils veulent avec fonction lambda

signals:
    void nouvelleInformation();
    //void articleRetire(Model::Article* article);
    //void totalPreTaxesMisAJour(double totalPreTaxes);
    //void articleAjoute(Model::Article* article);


};

}
#endif // CAISSEENREGISTREUSE_H
