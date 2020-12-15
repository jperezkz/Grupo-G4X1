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
#include <ostream>

#define TAM 100

struct Nodo{
    bool flag;
    QGraphicsRectItem *paint_cell = nullptr;
    QGraphicsTextItem *text_cell = nullptr;
    int cx, cy;
    int valor;
};

class Grid {
    Nodo matrix[TAM][TAM];
    int width;
    int tile;

public:
    Grid();
    void set_occupied(int x, int y);
    bool get_occupied(int x, int y);
    void set_value(int x, int y, int valor);
    int get_value(int x, int y);
    std::tuple<int, int> transform(int x, int y);
    void create_graphic_items(QGraphicsScene &scene, QGraphicsView *view);
    void reset_cell_distances();

};


#endif //PRACTICA5_GRID_H
