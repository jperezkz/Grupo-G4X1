//
// Created by noel on 28/11/20.
//

#ifndef PRACTICA5_GRID_H
#define PRACTICA5_GRID_H

#define TAM 5000

struct Nodo{
    bool flag;
    int valor;
};

template <typename ValueType>
class Grid {
    Nodo matrix[TAM][TAM];

public:
    Grid();
    void set_occupied(int x, int y);
    ValueType get_occupied(int x, int y);
    std::tuple<int, int> transform(int x, int y);

};


#endif //PRACTICA5_GRID_H
