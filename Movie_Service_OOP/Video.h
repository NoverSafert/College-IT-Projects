#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>
using namespace std;


//Clase video, guarda un arreglo con los datos de id, titulo, duración, genero y calificacionPromedio
//contiene los métodos de acceso set y get de los datos del arreglo
class Video
{
	public:
	Video();
	Video(string, string, int, string, double);

	string getID();
  string getTitulo();
  int getDuracion();
  string getGenero();
  double getCalificacionPromedio();

	void setID(string);
  void setTitulo(string);
  void setDuracion(int);
  void setGenero(string);
  void setCalificacionPromedio(double);

  double calPromedio(); 
  string mostrar();


	protected:
  //Peliculas *arrPtrPeliculas[100];
  string iD;
  string titulo;
  int duracion;
  string genero;
  double calificacionPromedio;
};

//Constructor
Video::Video()
{
    iD = "54321D";
    titulo = "Shrek 2";
    duracion = 120;
    genero = "Comedia";
    calificacionPromedio = 3.5;
}

//Constructor con parametros
Video::Video(string iiD, string tit, int dur, string gen, double calp)
{
    iD = iiD;
    titulo = tit;
    duracion = dur;
    genero = gen;
    calificacionPromedio = calp;
}

//modifica el id
void Video::setID(string iiD) 
{
  iD = iiD;
}

//metodo string
string Video::getID()
{
  return iD;
}

//metodo que modifica el titulo
void Video::setTitulo(string tit)
{
    titulo = tit;
}

//metodo que regresa el titulo
string Video::getTitulo()
{
    return titulo;
}

//metodo que modifica la duracion
void Video::setDuracion(int dur)
{
    duracion = dur;
}

//metodo que regresa la duracion
int Video::getDuracion()
{
    return duracion;
}

//metodo que modifica la calificacion promedio con la que envian en el parametro
void Video::setCalificacionPromedio(double calp)
{
    calificacionPromedio = calp;
}

//metodo que retorna la calificacion promedio
double Video::getCalificacionPromedio()
{
    return calificacionPromedio;
}

//metodo que modifica el genero
void Video::setGenero(string gen)
{
    genero = gen;
}

//metodo que retorna el genero
string Video::getGenero()
{
    return genero;
}

#endif // VIDEO_H