//
// Created by noel on 28/11/20.
//

#ifndef PRACTICA5_GRID_H
#define PRACTICA5_GRID_H
#include <tuple>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <Eigen/Dense>
#include <ostream>

#define TAM 50

struct Nodo{
    bool flag;
    QGraphicsRectItem *paint_cell = nullptr;
    QGraphicsTextItem *text_cell = nullptr;
    int cx, cy; // Coordenadas en el mundo
    int i, j; // Coordenadas en la matriz
    int valor;
};

class Grid {
    Nodo matrix[TAM][TAM];
    int width;
    int tile;

    bool is_in_limits(int i, int j);

public:
    Grid();
    void set_occupied(int x, int y);
    bool get_occupied(int x, int y);
    void set_value(int i, int j, int valor);
    int get_value(int x, int y);
    std::tuple<int, int> transform(int x, int y);
    void create_graphic_items(QGraphicsScene &scene, QGraphicsView *view);
    void compute_navigation_function(Eigen::Vector2f T);
    std::vector<Nodo> neighboors( Nodo v, int dist);
    void reset_cell_distances();

};


#endif //PRACTICA5_GRID_H
