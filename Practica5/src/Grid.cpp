//
// Created by noel on 28/11/20.
//

#include "Grid.h"

Grid::Grid(){
    width = 5000;
    tile = 100;
    int x = -(width/2 - tile/2);
    int y = -(width/2 - tile/2);
    for (int i=0;i<TAM;i++){
        for (int j=0;j<TAM;j++){
            matrix[i][j].flag = false;
            matrix[i][j].valor = -1;
            matrix[i][j].paint_cell = new QGraphicsRectItem();
            matrix[i][j].text_cell = new QGraphicsTextItem();
            matrix[i][j].cx = x;
            matrix[i][j].cy = y;
            matrix[i][j].i = i;
            matrix[i][j].j = j;

            x += tile;
        }
        x = -(width/2 - tile/2);
        y += tile;
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

void Grid::set_value(int i, int j, int valor) {
    if(i<0 or i>=TAM or j<0 or j>=TAM)
    {
        std::cout << "Indice fuera de rango" << std::endl;
        return;
    }
    matrix[i][j].valor = valor;
    matrix[i][j].text_cell->setPlainText(QString::number(valor));
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
            matrix[i][j].paint_cell->setPos(matrix[i][j].cx, matrix[i][j].cy);
            matrix[i][j].text_cell = scene.addText("-1", font);
            matrix[i][j].text_cell->setPos(matrix[i][j].cx - tile/4, matrix[i][j].cy + tile/4);
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

void Grid::compute_navigation_function(Eigen::Vector2f T)
{
    //Obtenemos la i, j de la celda Target
    auto [i, j] = transform(T.x(), T.y());

// vector con los desplazamientos locales para acceder a los 8 vecinos.
    reset_cell_distances();
    int dist = 0;
    std::vector<Nodo> L1 = neighboors(matrix[i][j], dist);
    std::vector<Nodo> L2 = {};
    bool end = false;
    while( not end )
    {
        for(auto current_cell : L1)
        {
            auto selected = neighboors( current_cell, dist);
            L2.insert(L2.end(), selected.begin(), selected.end());
        }
        dist++;
        end = L2.empty();
        L1.swap(L2);
        L2.clear();
    }
}

std::vector<Nodo> Grid::neighboors(Nodo v, int dist)
{
    std::vector<std::tuple<int, int>> lista_coor_de_vecinos{ {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {-1,1} };

    std::vector<Nodo> lista;
    for(auto [k, l] : lista_coor_de_vecinos)
    {
        int i = v.i + k;        // OJO hay que añadir al struct Value las coordenadas de array
        int j = v.j + l;
        if(is_in_limits(i,j) and not matrix[i][j].flag  and matrix[i][j].valor == -1)
        {
            set_value(i, j, dist);
            lista.push_back(matrix[i][j]);
        }
    }
    return lista;
}



void Grid::reset_cell_distances()    {
    for (int i=0;i<TAM;i++){
        for (int j=0;j<TAM;j++){
            matrix[i][j].valor = -1;
            matrix[i][j].text_cell->setPlainText(QString::number(-1));
        }
    }
}

bool Grid::is_in_limits(int i, int j){
    return ((i>0 and i<TAM) and (j>0 and j<TAM));
}

