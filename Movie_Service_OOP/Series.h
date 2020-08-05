#ifndef SERIES_H
#define SERIES_H
#include <iostream>
#include <stdio.h>
#include <string>
#include "Serie.h"
#include "Episodio.h"
#include <sstream>
#include <fstream>
using namespace std;

class Series {
	public:
    Series();
    void leerArchivo();
    void str();
    void reporteConCalificacion(double);
    void reporteGenero(string);
    double calculaCalPromedio();
    void setPtrSerie(Serie *ptr);
    Serie* getPtrSerie(string);
    
    void mostrarEps(string);
    void consultaEpsConCalificacion(string iD, double dCal);
    void calcularPromedioXSerie();

	private:
    Serie *arrPtrSeries[100];
    int iCant;

};

//Constructor 
Series::Series(){
    iCant = 0;
    for (int iR=0; iR < 100 ; iR++){
      arrPtrSeries[iR] = nullptr;
    }
}

//Metodo para leer archivos
void Series::leerArchivo(){
  fstream fin;
  int iEpisodio=0;
  int arrIdserie[150];
  Episodio *arrPtrEpisodio[150];
  Episodio *arrPtrEpi[5];
  //abrimos archivo episodios
  fin.open("Episodios.csv", ios::in);
  string row[6];
  string line, word;
  while(getline(fin,line)){
    //cout<<iEpisodio<<" = "<<line<<endl;
    stringstream s(line);
    int iR= 0;
    while(getline(s,word,',')){
      //almacena la palabra en un arreglo despues de separar por comas
      row[iR++] = word;
    }
    //creamos instancia de episodio e imprimimos lineas de episodio
    arrPtrEpisodio[iEpisodio] = new Episodio();
    //cout<<"ID de la Serie: " << row[0] << "\n";
    //cout<<"Titulo: " << row[1] << "\n";
    //cout<<"Temporada: " << row[2] << "\n";
    //cout<<"Calificacion: " << row[3] << "\n";

    //metodos sets
    arrIdserie[iEpisodio] = stoi(row[0]);
    arrPtrEpisodio[iEpisodio]->setTitulo(row[1]);
    arrPtrEpisodio[iEpisodio]->setTemporada(stoi(row[2]));
    arrPtrEpisodio[iEpisodio]->setCalificacion(stod(row[3]));

    //cout << "***" << arrPtrEpisodio[iEpisodio]->str() <<endl;
    iEpisodio++;
  }
  //cerramos archivo Episodios
  fin.close();
  for(int iR=0; iR < iEpisodio; iR++){
    //cout << arrPtrEpisodio[iR]->str()<<endl;
  }
  /////////////////////////
  //Abrimos archivo series ahora
  fin.open("Series.csv", ios::in);
    iCant=0;
    while (getline(fin, line)) {
        stringstream s(line);
        int iR = 0;
        while (getline(s, word, ',')) {
            //almacena la palabra en un arreglo despues de separar por comas
            row[iR++]=word;
        }
        // Desplegar en pantalla lineas de series
        // arrPtrSeries[iCant]= new Serie();
        /*
        cout << "iD: " << row[0] << " \n";
        cout << "Titulo: " << row[1] << "\n";
        cout << "Duracion: " << row[2] << "\n";
        cout << "Calificacion: " << row[4] << "\n";
        cout << "Genero: " << row[3] << "\n";
        cout << "Episodios: " << row[5] << "\n";*/

        for (int iR=0; iR < 5; iR++){
          arrPtrEpi[iR] = nullptr;
        }
        
        //Metodos sets simplificados con una instancia nueva de serie
        arrPtrSeries[iCant] = new Serie(row[0],row[1],stoi(row[2]),row[3],stod(row[4]),stoi(row[5]), arrPtrEpi);

        //Ciclo de asociacion de series y episodios
        int iE=0;
        for (int iEpi=0; (iEpi < iEpisodio) & (iE < 5); iEpi++){
          if (arrIdserie[iEpi] == stoi(row[0])){
            arrPtrSeries[iCant]->setEpisodio(iE,arrPtrEpisodio[iEpi]);
            iE++;
          }
        }
        arrPtrSeries[iCant]->setCantidadEpisodios(iE);
        //actualizamos valor iCant
        iCant= iCant + 1;
    }  
  //cerramos archivo series
  fin.close();
}


//Metodo para buscar series con cierta calificacion
void Series::reporteConCalificacion(double calificacionPromedio){
  for (int i = 0; i < iCant; i++){
    if (arrPtrSeries[i]->getCalificacionPromedio() == calificacionPromedio){
      cout << arrPtrSeries[i]->str() << endl;
    }
  }
}

//Metodo string para despelegar series y episodios
void Series::str()
{
  double dPromedio;
  //cout<<"ID    Titulo     Duracion     Genero     Calificacion     Episodios\n";
  //cout<<"------------------------------------------------------------------\n";
  //Ciclo para series
  for (int iR=0; iR<iCant; iR++){
    //cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Serie : "<<arrPtrSeries[iR]->str()<<endl;
    //obtenemos valores para sumarlos para promedio final
    dPromedio= dPromedio + arrPtrSeries[iR]->getCalificacionPromedio();
    //cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    //Ciclo para episodios
    for (int iEpisodio=0; iEpisodio < arrPtrSeries[iR]->getCantidadEpisodios(); iEpisodio++){
        cout<< arrPtrSeries[iR]->getEpisodio(iEpisodio).str()<<endl;
  }
  }
  //Calculamos promedio final
  cout<<"Promedio total de series: "<<dPromedio/iCant<<endl;
}

//Metodo para buscar series de cierto genero
void Series::reporteGenero(string genero)
{
  for (int i = 0; i < iCant; i++)
  {
    if (arrPtrSeries[i]->getGenero() == genero)
    {
      cout << arrPtrSeries[i]->str() << endl;
    }
  }
}

//Metodo para calcular promedio
double Series::calculaCalPromedio()
{
  int prom = 0;

  return 7.77;
}

//Da de alta nueva serie
void Series::setPtrSerie(Serie *ptr)
{
  arrPtrSeries[iCant]=ptr;
  iCant = iCant + 1;
}

//Metodo de clase serie que retorna serie 
Serie* Series::getPtrSerie(string iSer)
{
  Serie *ser = nullptr;
  for (int iR = 0; iR >= 0 && iR <= iCant; iR++)
  {
    if (arrPtrSeries[iR]->getID() == iSer){
      return arrPtrSeries[iR];
      break;
    }
  }

  //regresa objeto serie predefinido
    cout << "Id incorrecto!";
    return ser;
  
}

//Mostrar Episodios de una serie
void Series::mostrarEps(string iDu){
  Serie consulta;
  for (int iR =0; iR < iCant; iR++){
    //Encontrar serie con id
    if (arrPtrSeries[iR]-> getID() == iDu){
      for (int iEpisodio=0; iEpisodio < arrPtrSeries[iR]->getCantidadEpisodios(); iEpisodio++){
        cout<< arrPtrSeries[iR]->getEpisodio(iEpisodio).str()<<endl;
      }
    }
  }
}

//Mostrar episodios de una serie de cierta calificacion
void Series::consultaEpsConCalificacion(string siD, double dCal){
  for (int iR = 0; iR < iCant; iR++){
    //Encontrar serie con id
    if (arrPtrSeries[iR]->getID() == siD){
        //Encontrar serie con calificacion 
        for (int iEpisodio=0; iEpisodio < arrPtrSeries[iR]->getCantidadEpisodios(); iEpisodio++){
          if(arrPtrSeries[iR]->getEpisodio(iEpisodio).getCalificacion() == dCal){
            cout<< arrPtrSeries[iR]->getEpisodio(iEpisodio).str()<<endl;
        }
      }
  }
}
}

//Calcular calificacion con episodios
void Series::calcularPromedioXSerie(){
  for (int i=0; i<iCant; i++){
    arrPtrSeries[i]->setCalificacionPromedio(arrPtrSeries[i]->calPromedio());
  }
}

#endif // SERIES_H