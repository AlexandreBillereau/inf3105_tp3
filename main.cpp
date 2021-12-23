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
#include <bits/stdc++.h>
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

    // Djikstra implementation.
    void plusCourtChemin(unsigned int x_depart, unsigned int y_depart, unsigned int couleur_depart, unsigned int x_destination, unsigned int y_destination) {


      int nbSommet = N * N;
      int dist[nbSommet];
      bool step[nbSommet];
      int parent[nbSommet];

      for (int i(0); i < nbSommet; ++i) {
        parent[0] = -1;
        dist[i] = INT_MAX;
        step[i] = false;
      }

      int src = posSommet(x_depart, y_depart);

      dist[src] = 0;

      for (int count = 0; count < nbSommet - 1; count++) {
        int couleur = couleur_depart;
        int min = distanceMinimal(dist, step);
        step[min] = true;


        for (int i(0); i < nbSommet; i++) {

          if (!step[i] && matriceAdjacent[min][i] && dist[min] + matriceAdjacent[min][i] < dist[i] && matriceAdjacent[min].estCouleur(matriceAdjacent[i].getCouleur())) {
            parent[i] = min;
            dist[i] = dist[min] + matriceAdjacent[min][i];
          }
          else if (!step[i] && matriceAdjacent[min][i] && dist[min] + matriceAdjacent[min][i] < dist[i] && !matriceAdjacent[min].estCouleur(matriceAdjacent[i].getCouleur())) {
            parent[i] = min;
            dist[i] = dist[min] + matriceAdjacent[min][i] + 2;
            couleur = matriceAdjacent[min].getCouleur();
          }
        }
      }

      printSolution(dist, nbSommet, parent, src, posSommet(x_destination, y_destination));

    }

    int distanceMinimal(int dist[], bool step[]){
      int min = INT_MAX;
      int min_index;

      for (int i(0); i < N*N ; ++i) {
        if (step[i] == false && dist[i] <= min){
          min = dist[i], min_index = i;
        }
      }
      return min_index;
    }

    int posSommet(int pos_x, int pos_y) const{
      return (int)N * pos_y + pos_x;
    }

    void printPath(int parent[], int j)
    {
      if (parent[j] == - 1)
        return;

      printPath(parent, parent[j]);

      printf("%d ", j);
    }

    int printSolution(int dist[], int n, int parent[], int depart, int arriver)
    {
      int src = depart;
      printf("Sommet\t Distance\tChemin");

        printf("\n%d -> %d \t\t %d\t\t%d ",
               src, arriver, dist[arriver], src);
        printPath(parent, arriver);

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