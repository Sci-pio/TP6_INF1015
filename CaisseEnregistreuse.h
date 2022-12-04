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
    double avoirTotalTaxes(){return totalTaxes_;}

private:
    std::vector<Article*> articleConteneur_;
    double totalPreTaxes_;
    double totalTaxes_; // IMPLEMENTER LAMBDA

signals:
    void nouvelleInformation();
};

}
#endif
