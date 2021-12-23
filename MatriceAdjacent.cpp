//
// Created by alexandre on 21-12-22.
//

#include "MatriceAdjacent.h"

MatriceAdjacent::Sommet::Sommet() {}

MatriceAdjacent::Sommet::Sommet(int couleur) {
  couleur = couleur;
}

MatriceAdjacent::MatriceAdjacent() {}

MatriceAdjacent::MatriceAdjacent(std::vector<std::vector<int>> univer) {
  initMatrice(univer.size());
  int count = 0;
  for(int y(0); y < univer.size(); y++){
    for(int x(0); x < univer[y].size(); x++){
      if(y - 1 >= 0){
        creerSommet(count, count - univer.size(), univer[y][x]);
      }
      if(x + 1 <= univer[y].size() - 1){
        creerSommet(count, count + 1, univer[y][x]);
      }
      if(y + 1 <= univer.size() - 1){
        creerSommet(count, count + univer[y].size(), univer[y][x]);
      }
      if(x - 1 >= 0){
        creerSommet(count, count - 1, univer[y][x]);
      }
      count ++;
    }
  }

}

void MatriceAdjacent::initMatrice(int N) {
  for (int i = 0; i < N * N; ++i) {
    matriceAdjacent.emplace_back();
    for (int j = 0; j < (N*N); ++j) {
      matriceAdjacent[i].arretes.push_back(0);
    }
  }
}

void MatriceAdjacent::creerSommet(unsigned int y, unsigned int x, int currentcouleur){

    matriceAdjacent[y].arretes[x] = 1;
    matriceAdjacent[y].setcouleur(currentcouleur);
}