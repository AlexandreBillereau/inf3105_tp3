#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <iostream>
#include "MatriceAdjacent.h"

class Univers
{
    unsigned int N; 	// Nombre de ligne et nombre de colonnes
    unsigned int C; 	// Nombre de couleur

    // TODO : Complétez avec les attributs nécessaires pour représenter l'univers
    std::vector<std::vector<int>> univer;
    MatriceAdjacent matriceAdjacent;

public:

    Univers() {

    }

    ~Univers() {

    }

    void plusCourtChemin(unsigned int x_depart, unsigned int y_depart, unsigned int couleur_depart, unsigned int x_destination, unsigned int y_destination) {
      std::cerr << "TODO : calculer le plus court chemin depuis (" << x_depart << ", " << y_depart << ") avec la couleur " << couleur_depart << " vers (" << x_destination << ", " << y_destination << ")" << std::endl;
      // TODO...
    }

    friend std::istream& operator >> (std::istream& is, Univers& recette);
};


std::istream& operator >> (std::istream& is, Univers& univers) {

  is >> univers.N; 		// Nombre de ligne et de colonnes
  is >> univers.C; 		// Nombre de couleurs

  assert(univers.N > 0);
  assert(univers.C > 0);

  for(unsigned int y = 0; y<univers.N; y++) {
    univers.univer.emplace_back();
    for(unsigned int x = 0; x<univers.N; x++) {
      unsigned int couleur;
      is >> couleur;
      univers.univer[y].push_back(couleur);
    }
  }

  MatriceAdjacent matriceAdj(univers.univer);
  univers.matriceAdjacent = matriceAdj;

  return is;
}


int main(int argc, char const *argv[])
{
  if(argc != 7) {
    std::cerr << "Utilisation : " << argv[0] << " x_depart y_depart couleur_depart x_destination y_destination" << std::endl;
    return -1;
  }
  std::cout << argv[1] << std::endl;
  std::ifstream entree(argv[1]);

  Univers univers;
  entree >> univers;

  unsigned int x_depart = atoi(argv[2]);
  unsigned int y_depart = atoi(argv[3]);
  unsigned int couleur_depart = atoi(argv[4]);
  unsigned int x_destination = atoi(argv[5]);
  unsigned int y_destination = atoi(argv[6]);

  univers.plusCourtChemin( x_depart, y_depart, couleur_depart, x_destination, y_destination );

  return 0;
}