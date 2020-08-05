#ifndef PELICULAS_H
#define PELICULAS_H
#include <iostream>
#include <stdio.h>
#include <string>
#include "Pelicula.h"
#include <sstream>
#include <fstream>

using namespace std;

// clase que guarda todas las películas como un arreglo de apuntadores
class Peliculas {
	public:
    Peliculas();
    void leerArchivo ();
    void str();
    void reporteConCalificacion(double);
    void reporteGenero(string);
    double calculaCalPromedio();
    
    void setPtrPelicula(Pelicula *ptr);
    Pelicula*  getPrtPelicula(string);

	private:
    Pelicula *arrPtrPeliculas[100];
    int iCant;

};

//Constructor
Peliculas::Peliculas()
{
    iCant=0;
    for (int iR=0; iR < 100 ; iR++)
    {
      arrPtrPeliculas[iR] = nullptr;
    }
}

//función que lee el archivo donde están guardadas las películas
void Peliculas::leerArchivo()
{
    
    fstream fin;
    fin.open("Peliculas.csv", ios::in);
    string row[6];
    string line, word;

    while (getline(fin, line)) 
    {
        //cout << line << endl;
        stringstream s(line);
        int iR = 0;
        while (getline(s, word, ',')) 
        {
            row[iR++]=word;
        }
        // Desplegar en pantalla
        arrPtrPeliculas[iCant]= new Pelicula();
        //cout << "iD: " << row[0] << " \n";
        //cout << "Titulo: " << row[1] << "\n";
        //cout << "Duracion: " << row[2] << "\n";
        //cout << "Calificacion: " << row[4] << "\n";
        //cout << "Genero: " << row[3] << "\n";
        //cout << "Oscares: " << row[5] << "\n";

        arrPtrPeliculas[iCant]->setID(row[0]);
        arrPtrPeliculas[iCant]->setTitulo(row[1]);
        arrPtrPeliculas[iCant]->setDuracion(stoi(row[2]));
        arrPtrPeliculas[iCant]->setCalificacionPromedio(stod(row[4]));
        arrPtrPeliculas[iCant]->setGenero(row[3]);
        arrPtrPeliculas[iCant]->setOscares(stoi(row[5]));
        iCant= iCant + 1;
    }
    fin.close();
}

//funcion que itera sobre el arreglo de películas y despliega en la pantalla las películas con la calificación que se ingresó
void Peliculas::reporteConCalificacion(double calificacionPromedio)
{
  for (int i = 0; i < iCant; i++)
  {
    if (arrPtrPeliculas[i]->getCalificacionPromedio() == calificacionPromedio)
    {
      cout << arrPtrPeliculas[i]->str() << endl;
    }
  }
}

//despliega todas las películas guardadas en el arreglo
void Peliculas::str()
{
  double dPromedio;
  cout<<"ID    Titulo     Duracion     Genero     Calificacion     Oscares\n";
  cout<<"------------------------------------------------------------------\n";
  //Ciclo que recorre el array de Peliculas
  for (int iR=0; iR<iCant; iR++)
  {
    cout<<arrPtrPeliculas[iR]->str()<<endl;
    dPromedio= dPromedio + arrPtrPeliculas[iR]->getCalificacionPromedio();
  }
  cout<<"Promedio total de peliculas: "<<dPromedio/iCant<<endl;
  
}

//funcion que itera sobre el arreglo de películas y despliega en la pantalla las películas con el género que que ingresó
void Peliculas::reporteGenero(string genero)
{
  for (int i = 0; i < iCant; i++)
  {
    if (arrPtrPeliculas[i]->getGenero() == genero)
    {
      cout << arrPtrPeliculas[i]->str() << endl;
    }
  }
}

//calcula el promedio de las calificaciones de todas las películas
double Peliculas::calculaCalPromedio()
{
  double prom = 0;
  for (int i = 0; i < iCant; i++)
  {
    prom = prom + arrPtrPeliculas[i]->calPromedio();
  }
  prom = prom/iCant;
  return prom;
}

//agrega una película al arreglo de apuntadores donde están todas las películas guardadas
void Peliculas::setPtrPelicula(Pelicula *ptr)
{
  arrPtrPeliculas[iCant]=ptr;
  iCant = iCant + 1;
}


Pelicula* Peliculas::getPrtPelicula(string iDd)
{
  Pelicula *peli = nullptr;
  for (int iR = 0; iR >= 0 && iR <= iCant; iR++)
  {
    if (arrPtrPeliculas[iR]->getID() == iDd){
      return arrPtrPeliculas[iR];
      break;
    }
  }
  cout << "Id incorrecto!";
  return peli;
}
  


#endif // PELICULAS_H
