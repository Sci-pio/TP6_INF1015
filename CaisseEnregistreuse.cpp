#include "CaisseEnregistreuse.h"

Model::CaisseEnregistreuse::~CaisseEnregistreuse()
{
    while (!articleConteneur_.empty()) {
        delete articleConteneur_.back();
        articleConteneur_.pop_back();
    }
}
void Model::CaisseEnregistreuse:: ajouterArticle(Article* article)
{
    articleConteneur_.push_back(article);
    totalPreTaxes_ += article->prix;

    emit nouvelleInformation();
}
void Model::CaisseEnregistreuse:: retirerArticle(Article* article)
{
    auto it = find(articleConteneur_.begin(), articleConteneur_.end(), article);

    if(it!=articleConteneur_.end()){
        articleConteneur_.erase(it);
        totalPreTaxes_ -= article->prix;
        emit nouvelleInformation();
    }
}

std::vector<Model::Article*> Model::CaisseEnregistreuse::avoirListeArticle() const
{
    return articleConteneur_;
}

