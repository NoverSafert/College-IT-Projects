#ifndef EPISODIO_H
#define EPISODIO_H
#include <iostream> 
#include <string>
using namespace std;

//Clase episodio
class Episodio
{
  public :
    Episodio();
    Episodio(string, int, double);
    void setTitulo(string);
    string getTitulo();
    void setTemporada(int);
    int getTemporada();
    void setCalificacion(double);
    double getCalificacion();
    string str();

    double operator + (double dPuntuacion){
    return dPuntuacion + calificacion;
    }
    
  private:
    string titulo;
    int temporada;
    double calificacion;

};

//Constructor
Episodio::Episodio()
{
  titulo = " ";
  temporada = 0;
  calificacion = 0.0;
}

//Constructor con parámetros
Episodio::Episodio(string tit, int temp, double cal)
{
    titulo = tit;
    temporada = temp;
    calificacion = cal;
}

//Recibe el nuevo titulo del episodio
void Episodio::setTitulo(string tit)
{
  titulo = tit;
}

//Retorna el titulo del episodio
string Episodio::getTitulo()
{
  return titulo;
}

//Recibe la nueva temporada
void Episodio::setTemporada(int temp)
{
  temporada = temp;
}

//Retorna la nueva temporada
int Episodio::getTemporada()
{
  return temporada;
}

//Recibe la nueva calificacion del episodio
void Episodio::setCalificacion(double cal)
{
  calificacion = cal;
}

//Retorna la calificacion del episodio
double Episodio::getCalificacion()
{
  return calificacion;
}

//Metodo string 
string Episodio::str()
{
  string str;
  str = "Episodio: " + titulo + ", " + to_string(temporada) + ", " + to_string(calificacion) + ", "; 
  return str;
}

#endif // EPISODIO_H