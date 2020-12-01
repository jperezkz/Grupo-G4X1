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
    auto &[i, j] = transform(x, y);
    matrix[i][j].flag = true;
}

ValueType Grid::get_occupied(int x, int y){
    auto &[i, j] = transform(x, y);
    return matrix[i][j].flag;
}

std::tuple<int, int> Grid::transform(int x, int y){
    int i = (x/tile)P + (width/tile)/2;
    int j = (y/tile) + (width/tile)/2;

    return std::make_tuple(i, j);
}