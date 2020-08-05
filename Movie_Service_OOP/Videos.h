#ifndef VIDEOS_H
#define VIDEOS_H
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

//Clase videos, guarda un arreglo de apuntadores de la clase video
class Videos 
{
  public:
    Videos();
    string str();
    void reporteCalificacion(int);
    void reporteGenero(string);
    double calculaCalPromedio();
    void alta();
    void calificar(string, double);//titulo , calificacion
  private:
    Video *videos[];

};


#endif //VIDEOS_H