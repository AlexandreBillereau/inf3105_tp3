//
// Created by alexandre on 21-12-22.
//
#include <vector>

#ifndef TP3_MATRICEADJACENT_H
#define TP3_MATRICEADJACENT_H


class MatriceAdjacent {

    class Sommet {
    private:
        unsigned int couleur;
        bool visiter;
    public:
        Sommet(int couleur);
        Sommet();
        std::vector<int> arretes;
        int operator[](int i){ return arretes[i];}
        bool estCouleur(unsigned int c){return c == couleur;}
        void setcouleur(unsigned int c){ couleur = c;}
        int getCouleur(){return couleur;}
    };

private:
    std::vector<Sommet> matriceAdjacent;

public:
    MatriceAdjacent();
    MatriceAdjacent(std::vector<std::vector<int>>);
    void initMatrice(int N);
    void creerSommet(unsigned int y, unsigned int x, int Currentcouleur);
    Sommet operator [](int i){return matriceAdjacent[i];}

};


#endif //TP3_MATRICEADJACENT_H
