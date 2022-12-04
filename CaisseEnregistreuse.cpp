#include "CaisseEnregistreuse.h"
#include "Exception.h"

Model::CaisseEnregistreuse::~CaisseEnregistreuse()
{
    while (!articleConteneur_.empty()) {
        delete articleConteneur_.back();
        articleConteneur_.pop_back();
    }
}

// voir ch.17 p.24
void Model::CaisseEnregistreuse:: ajouterArticle(Article* article)
{
    if (article->description!="" && article->prix!=0)
    {
        articleConteneur_.push_back(article);
        totalPreTaxes_ += article->prix;
        //if (article->taxable==true) {totalTaxes_ += article->prix*0.14975;} // solution temporaire en attendant la lambda
        emit nouvelleInformation();
    }
    else{
        if (article->description=="") {throw Exception::ExceptionDescriptionVide("La description de l'article est vide");}
        else {throw Exception::ExceptionPrixNul("Le prix de l'article est nul");}
    }
}
void Model::CaisseEnregistreuse:: retirerArticle(Article* article)
{
    auto it = find(articleConteneur_.begin(), articleConteneur_.end(), article);

    if(it!=articleConteneur_.end()){
        articleConteneur_.erase(it);
        totalPreTaxes_ -= article->prix;
        //if (article->taxable==true) {totalTaxes_ -= article->prix*0.14975;} // solution temporaire en attendant la lambda
        emit nouvelleInformation();
    }
}

std::vector<Model::Article*> Model::CaisseEnregistreuse::avoirListeArticle() const
{
    return articleConteneur_;
}

double Model::CaisseEnregistreuse::avoirTotalTaxes() const
{
    return std::transform_reduce(articleConteneur_.cbegin(), articleConteneur_.cend(), 0.0, std::plus<double>(),
                                 [](Article* a){return a->taxable? a->prix * 0.14975: 0.0;});
}

//std::function<double()> FonctionLambdaTaxe = [&](){
//    return std::reduce(articleConteneur_.begin(), articleConteneur_.end(),1);
//  } ;
//

