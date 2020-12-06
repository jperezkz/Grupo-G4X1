//
// Created by noel on 28/11/20.
//

#ifndef PRACTICA5_GRID_H
#define PRACTICA5_GRID_H
#include <tuple>
#include <iostream>
#include <ostream>

#define TAM 100

struct Nodo{
    bool flag;
    int valor;
};

class Grid {
    Nodo matrix[TAM][TAM];
    int width = 5000;
    int tile = 50;

public:
    Grid();
    void set_occupied(int x, int y);
    bool get_occupied(int x, int y);
    void set_value(int x, int y, int valor);
    int get_value(int x, int y);
    std::tuple<int, int> transform(int x, int y);

};


#endif //PRACTICA5_GRID_H
