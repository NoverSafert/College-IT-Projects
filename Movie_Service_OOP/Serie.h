#ifndef SERIE_H
#define SERIE_H
#include <iostream>
#include <string>
#include "Video.h"
#include "Episodio.h"
using namespace std;

//Clase serie
class Serie : public Video 
{
	public:
	  Serie();
    Serie(string, string, int, string, double, int, Episodio *epi[]);
    string str();
    double calPromedio();
    void setEpisodio(int, Episodio *ptr);
    Episodio getEpisodio(int);
    void setCantidadEpisodios(int);
    int getCantidadEpisodios();
    void altaEpisodio(Episodio *ptrEpi);

	protected:
    int iCant;
    Episodio *episodios[5];

};

//Constructor
Serie::Serie() : Video()
{
  for (int iR = 0; iR < 5; iR++){
    episodios[iR] = nullptr;
  }
  iCant = 0;
}

//Constructor con parametros
Serie::Serie(string id, string tit, int dur, string gen, double cal, int numCap, Episodio *epi[]) : Video(id,tit,dur,gen,cal)
{
  iCant = numCap;
  episodios[iCant] =  epi[iCant];
}

//Metodo string
string Serie::str()
{
  string str;
  str = iD + ", " + titulo + ", " + to_string(duracion) + ", " + genero + ", " + to_string(calificacionPromedio)+ ", "+ to_string(iCant);
  return str;
}

//Metodo que calcula promedio de serie
double Serie::calPromedio() 
{
  double dAcum = 0;
  for (int iR = 0; iR < iCant; iR++)
  {
    //dAcum = dAcum + episodios[iR]->getCalificacion();
    dAcum = *episodios[iR] + dAcum;
  }
  if(iCant > 0)
  {
    return dAcum / iCant;
  }
  return -1;
}

//Metodo que recibe un nuevo episodio
void Serie::setEpisodio(int iE, Episodio *ptr)//checar
{
  iCant = iE;
  episodios[iCant] = ptr; //puse el asterisco y quito error
}

//Metodo que retorna el episodio 
Episodio Serie::getEpisodio(int iEp)  //Checar
{
  Episodio episod;
  if ( iEp >= 0 && iEp <= iCant)
    return (*episodios[iEp]);
  
  else
    return episod;
  
}

//Metodo que cambia la cantidad de episodios
void Serie::setCantidadEpisodios(int numCap )
{
  iCant = numCap;
}

//Metodo que regresa la cantidad de episodios
int Serie::getCantidadEpisodios()
{
  return iCant;
}

//Metodo que permite dar de alta un nuevo episodio
void Serie::altaEpisodio(Episodio *ptrEpisodio){
  episodios[iCant]=ptrEpisodio;
  iCant ++;
}

#endif // SERIE_H