#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
#include <string>
using namespace std;
#include "Video.h"

//clase película derivada de video, datos adiciones que agrega son los oscares
class Pelicula : public Video 
{
	public:
	  Pelicula();
    Pelicula(string, string, int, string, double, int);
    string str();
    double calPromedio();
    void setOscares(int);
    int getOscares();

	protected:
    int iOscares;

};

Pelicula::Pelicula() : Video()
{
  iOscares = 0;
}

Pelicula::Pelicula(string id, string tit, int dur, string gen, double cal, int osc) : Video(id,tit,dur,gen,cal)
{
  iOscares = osc;
}

//despliega una película
string Pelicula::str()
{
  string str;
  str = iD + ", " + titulo + ", " + to_string(duracion) + ", " + genero + ", " + to_string(calificacionPromedio)+ ", "+ to_string(iOscares);
  return str;
}

//Funcion que regresa la calificacion promedio
double Pelicula::calPromedio()
{
  return calificacionPromedio;
}

//modifica la cantidad de oscares que tiene una pelicula
void Pelicula::setOscares(int osc)
{
  iOscares = osc;
  calificacionPromedio =  osc * 0.5;
}

//regresa la cantidad de oscares que hay un una película
int Pelicula::getOscares()
{
  return iOscares;
}
#endif // PELICULA_H