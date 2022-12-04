// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 4 decembre 2022
// Cours: INF1015
// Nom de la classe: Exception.h

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>
using namespace std;

namespace Exception
{
    class ExceptionEntreeValeur: public std::logic_error
    {
    public:
        using logic_error::logic_error;
    };

    class ExceptionDescriptionVide : public ExceptionEntreeValeur
    {
    public:
        using ExceptionEntreeValeur::ExceptionEntreeValeur;
    };

    class ExceptionPrixNul: public ExceptionEntreeValeur
    {
    public:
        using ExceptionEntreeValeur::ExceptionEntreeValeur;
    };
}

#endif
