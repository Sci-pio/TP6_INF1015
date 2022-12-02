#include "CaisseEnregistreuse.h"

CaisseEnregistreuse::CaisseEnregistreuse()
{

}
CaisseEnregistreuse::~CaisseEnregistreuse()
{
    while (!articleConteneur_.empty()) {
        delete articleConteneur_.back();
        articleConteneur_.pop_back();
    }
}
void CaisseEnregistreuse:: ajouterArticle(Article* article)
{
    articleConteneur_.push_back(article);
    totalPreTaxes_ += article->prix;
    emit articleAjoute(article);
    emit totalPreTaxesMisAJour(totalPreTaxes_);
}
void CaisseEnregistreuse:: retirerArticle(Article* article)
{
    auto it = find(articleConteneur_.begin(), articleConteneur_.end(), article);

    if(it!=articleConteneur_.end()){
        Article* a = *it;
        articleConteneur_.erase(it);
        emit articleRetire(a);
    }
}


