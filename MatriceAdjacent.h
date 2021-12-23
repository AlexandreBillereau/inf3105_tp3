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
        void ajouter(int c);
        std::vector<int> arretes;
    };

private:
    std::vector<Sommet> matriceAdjacent;

public:
    MatriceAdjacent();
    MatriceAdjacent(std::vector<std::vector<int>>);
    void initMatrice(int N);
    void creerSommet(unsigned int y, unsigned int x, int Currentcouleur, int nextCouleur );
    void calculerMatriceAdjacent();

};


#endif //TP3_MATRICEADJACENT_H
