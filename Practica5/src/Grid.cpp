//
// Created by noel on 28/11/20.
//

#include "Grid.h"

Grid::Grid(){
    width = 5000;
    tile = 100;
    for (int i=0;i<TAM;i++){
        for (int j=0;j<TAM;j++){
            matrix[i][j].flag = false;
            matrix[i][j].valor = -1;
            matrix[i][j].paint_cell = new QGraphicsRectItem();
            matrix[i][j].text_cell = new QGraphicsTextItem();
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
        return;
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

void Grid::create_graphic_items(QGraphicsScene &scene, QGraphicsView *view)
{
    auto fondo = QColor("LightGreen"); fondo.setAlpha(40);
    QFont font("Bavaria");
    font.setPointSize(40);
    font.setWeight(QFont::TypeWriter);
    for (int i=0;i<TAM;i++) {
        for (int j = 0; j < TAM; j++) {
            matrix[i][j].paint_cell = scene.addRect(-tile / 2, -tile / 2, tile, tile, QPen(QColor("DarkGreen")),
                                                    QBrush(fondo));
            matrix[i][j].paint_cell->setPos((i - 50) * (TAM/2), (j - 50) * (TAM/2));
            matrix[i][j].text_cell = scene.addText("-1", font);
            matrix[i][j].text_cell->setPos(((i - 50) * (TAM/2)) - tile / 2, ((j - 50) * (TAM/2)) - tile / 2);
            // Get the current transform
            QTransform transform(matrix[i][j].text_cell->transform());
            qreal m11 = transform.m11();    // Horizontal scaling
            qreal m12 = transform.m12();    // Vertical shearing
            qreal m13 = transform.m13();    // Horizontal Projection
            qreal m21 = transform.m21();    // Horizontal shearing
            qreal m22 = transform.m22();    // vertical scaling
            qreal m23 = transform.m23();    // Vertical Projection
            qreal m31 = transform.m31();    // Horizontal Position (DX)
            qreal m32 = transform.m32();    // Vertical Position (DY)
            qreal m33 = transform.m33();    // Addtional Projection Factor
            // Vertical flip
            m22 = -m22;
            // Write back to the matrix
            transform.setMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);
            // Set the items transformation
            matrix[i][j].text_cell->setTransform(transform);
        }
    }
}

void Grid::reset_cell_distances()    {
    for (int i=0;i<TAM;i++){
        for (int j=0;j<TAM;j++){
            matrix[i][j].valor = -1;
        }
    }
}

