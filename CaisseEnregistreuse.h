#ifndef CAISSEENREGISTREUSE_H
#define CAISSEENREGISTREUSE_H
#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Model { class CaisseEnregistreuse; struct Article; }
QT_END_NAMESPACE

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
    //double totalTaxes = [](*this) {return totalPreTaxes_ * 0.14975;};

public slots:

signals:
    void articleAjoute(Article* article);
    void articleRetire(Article* article);
    void totalPreTaxesMisAJour(double totalPreTaxes);

private:
   std::vector<Article*> articleConteneur_;
   double totalPreTaxes_;
   double totalTaxesTemp_ = 0; // jarrive pas a implementer comme ils veulent avec fonction lambda
};

#endif // CAISSEENREGISTREUSE_H
