//
// Created by noel on 28/11/20.
//

#include "Grid.h"

Grid::Grid(){
    for (int i=0;i<TAM;i++){
        for (int j=0;j<TAM;j++){
            matrix[i][j].flag = false;
            matrix[i][j].valor = 0;
        }
    }
}

void Grid::set_occupied(int x, int y){
    auto [i, j] = transform(x, y);
    if(i<0 or i>=TAM or j<0 or j>=TAM)
    {
        std::cout << "Indice fuera de rango" << std::endl;
        return;
    }
    matrix[i][j].flag = true;
}

bool Grid::get_occupied(int x, int y){
    auto [i, j] = transform(x, y);
    if(i<0 or i>=TAM or j<0 or j>=TAM)
    {
        std::cout << "Indice fuera de rango" << std::endl;
        return false;
    }
    return matrix[i][j].flag;
}

void Grid::set_value(int x, int y, int valor) {
    auto [i, j] = transform(x, y);
    if(i<0 or i>=TAM or j<0 or j>=TAM)
    {
        std::cout << "Indice fuera de rango" << std::endl;
        return false;
    }
    matrix[i][j].valor = valor;
}

int Grid::get_value(int x, int y) {
    auto [i, j] = transform(x, y);
    if(i<0 or i>=TAM or j<0 or j>=TAM)
    {
        std::cout << "Indice fuera de rango" << std::endl;
        return false;
    }
    return matrix[i][j].valor;
}

std::tuple<int, int> Grid::transform(int x, int y){
    int i = x/tile + (width/tile)/2;
    int k = y/tile + (width/tile)/2;

    return std::make_tuple(i, k);
}