//Situacion Problema
//Plataforma: Wazowski Streaming Service (WSS)
/*Integrantes:
José Enrique Damián Velázquez A00827513 Grupo 2
Fernando Aguilar Acosta  A00827677 Grupo 2
*/

#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Peliculas.h"
#include "Video.h"
#include "Series.h"
#include "Serie.h"

using namespace std;

//Ingresa los datos de una Pelicula nueva al arreglo de peliculas que se tiene
void leerDatosPelicula(Pelicula &datosPelicula)
{
  int iOscares;
  string sID;
  string sTitulo;
  int iDuracion;
  string sGenero;
  double dCalificacion;

  cout<<"***** Ingresa los datos de la película *****\n";
  cout << "Ingresa el ID: ";
  cin >> sID;
  cin.ignore();
  datosPelicula.setID(sID);

  cout<<"Ingresa el Titulo: ";
  getline(cin, sTitulo);
  datosPelicula.setTitulo(sTitulo);

  cout<<"Ingresa la Duracion(min): ";
  cin >> iDuracion;
  datosPelicula.setDuracion(iDuracion);

  cout<<"Ingresa el Genero: ";
  cin >> sGenero;
  datosPelicula.setGenero(sGenero);

  cout<<"Ingresa la calificacion: ";
  cin >> dCalificacion;
  datosPelicula.setCalificacionPromedio(dCalificacion);

  cout<<"Ingresa la cantidad de Oscares: ";
  cin >> iOscares;
  datosPelicula.setOscares(iOscares);
  cin.ignore();
}


//Función que da de Alta un episodio de una serie en específico
void leerDatosEpisodio(Episodio &datosEpisodio)
{
  string sTitulo;
  int iTemporada;
  double dCalificacion;

  cout<<"Ingresa el Titulo del episodio: ";
  //cin >> sTitulo;
  getline(cin, sTitulo);
  datosEpisodio.setTitulo(sTitulo);

  cout<<"Ingresa la temporada a la que pertenece: ";
  cin >> iTemporada;
  datosEpisodio.setTemporada(iTemporada);

  cout<<"Ingresa la calificacion: ";
  cin >> dCalificacion;
  datosEpisodio.setCalificacion(dCalificacion);

}

//Función que lee los datos de la serie para agregar una nueva serie
void leerDatosSerie(Serie &datosSerie)
{
  int iCant;
  string sID;
  string sTitulo;
  int iDuracion;
  string sGenero;
  double dCalificacion;

  cout<<"***** Ingresa los datos de la serie *****\n";
  cout << "Ingresa el ID: ";
  cin >> sID;
  cin.ignore();
  datosSerie.setID(sID);

  cout<<"Ingresa el nombre de la serie: ";
  getline(cin, sTitulo);
  datosSerie.setTitulo(sTitulo);

  cout<<"Ingresa la Duracion(min): ";
  cin >> iDuracion;
  datosSerie.setDuracion(iDuracion);

  cout<<"Ingresa el Genero: ";
  cin >> sGenero;
  datosSerie.setGenero(sGenero);

  cout<<"Ingresa la calificacion: ";
  cin >> dCalificacion;
  datosSerie.setCalificacionPromedio(dCalificacion);

  cout<<"Ingresa la cantidad de episodios: ";
  cin >> iCant;
  datosSerie.setCantidadEpisodios(iCant);
  cin.ignore();
}


//Funcion para elegir opcion del menu
int menuPeliculas()
{
  int iOpcion;
  cout<< "\n"<<
  "\n-------------Peliculas--------------" <<
  "\n1. Leer informacion desde archivo" <<
  "\n2. Dar de alta una pelicula" <<
  "\n3. Reporte de peliculas" <<
  "\n4. Reporte de Peliculas por calificacion" <<
  "\n5. Reporte de Peliculas por genero" <<
  "\n6. Incrementar Oscares"<<
  "\n"<<
  "\n---------------Serie----------------" <<
  "\n7. Leer informacion desde archivo" <<
  "\n8. Reporte de Series" <<
  "\n9. Reporte de Serie por calificacion" <<
  "\n10. Reporte de Serie por genero" <<
  "\n11. Calcular la calificacion de series en base a sus episodios" <<
  "\n"<<
  "\n--------------Episodio-----------------" <<
  "\n12. Dar alta un episodio a una serie" <<
  "\n13. Mostrar capitulos de una serie " <<
  "\n14. Mostrar capitulos de una serie con calificacion" <<
  "\n0. Salir" <<
  "\n"<<
  "\n Teclea la opcion a elegir: ";
  cin >> iOpcion;
  return iOpcion;
}

int main() 
{
  //se inicializan todas las variables que se ocuparan en el programa
  Peliculas peliculas;
  Pelicula *ptrPelicula;

  int iOpcion;
  int iOscar;

  double dCal;

  string sGenero, sId;

  Series series;
  Serie *ptrSerie;
  Serie serie1;
  Episodio *ptrEpisodio;

  //Logo
  cout << "========================================\n"<<
          ": *            *    ******     *****   :\n"<<
          ":  *          *    *      *   *     *  :\n"<<
          ":  *    **    *   *           *        :\n"<<
          ":   *  *  *  *     *           *****   :\n"<<
          ":   * *    * *      *****           *  :\n"<<
          ":    *      *            *    *     *  :\n"<<
          ":                         *    *****   :\n"<<
          ":                 *      *             :\n"<<
          ":                  ******              :\n"<<
          ":   Wazowski     Streaming   Service   :\n"<<
          "========================================\n"<<
          "                           by Jose y Fer\n";
  //Se manda llamar a la función menuPeliculas
  iOpcion = menuPeliculas(); 

  peliculas.leerArchivo();
  series.leerArchivo();
  // se crea un ciclo donde se realizan las acciones que se seleccionaron en el menu
  while (iOpcion !=0) 
  {
    cout << "A00827513 - Jose Enrique Damian Velazquez\n";
    switch (iOpcion)
    {
      case 1:
          //lee los datos de las películas desde un archivo y despliega el primer dato guardado
          peliculas.leerArchivo();
          //cout << peliculas.getPelicula("100").str() << endl;
          break;
      case 2:
          //Da de alta una película agregandola al final del arreglo
          ptrPelicula= new Pelicula();
          leerDatosPelicula(*ptrPelicula);
          peliculas.setPtrPelicula(ptrPelicula);
          break;
      case 3:
          // despliega todas las películas que hay guardadas
          peliculas.str();
          //cout << "Promedio total (funcion calculaCalPromedio)" << peliculas.calculaCalPromedio();
          break;
      case 4:
          //se muestran todas las películas con una cierta calificación
          cout << "Ingresa la calificacion: ";
          cin >> dCal;
          peliculas.reporteConCalificacion(dCal);
          break;
      case 5:
          // Se muestran todas las películas que sean de cierto genero
          cout << "Ingresa el Genero: ";
          cin >> sGenero;
          peliculas.reporteGenero(sGenero);
          break;
      case 6:
          // Agrega oscares a una película dada el id de la película 
          cout << "Ingrese el id de la película: ";
          cin >> sId;
          cout << "Ingrese la cantidad de Oscares: ";
          cin >> iOscar;
          // se obtiene la película con el id, se modifican los oscares y se despliega
          ptrPelicula = peliculas.getPrtPelicula(sId);
          ptrPelicula->setOscares(iOscar);
          cout << peliculas.getPrtPelicula(sId)->str() << endl;
          break;
      case 7:
          // Lee los datos de un achivo para registrarlos como series
          series.leerArchivo();
          break;
      case 8:
          //Despliega todas las series con sus episodios
          series.str();
          break;
      case 9:
          //muestra las series con cierta calificación dada
          cout << "Ingresa la calificacion: ";
          cin >> dCal;
          series.reporteConCalificacion(dCal);
          break;
      case 10:
          //muestra todas las series que tengan el mismo género que se ingresó
          cout << "Ingresa el Genero: ";
          cin >> sGenero;
          series.reporteGenero(sGenero);
          break;
      case 11:
          //Manda una funcion a llamar para calificar episodios en base a sus episodios
          series.calcularPromedioXSerie();
          break;   
      case 12:
          //agrega episodios a una serie con el id que se proporcione *****mismo problema que la 6*****
          cout << "Ingrese el id de la serie que quiera añadir episodio: ";
          cin >> sId;
          cin.ignore();
          ptrEpisodio= new Episodio();
          leerDatosEpisodio(*ptrEpisodio);

          ptrSerie = series.getPtrSerie(sId);
          ptrSerie->altaEpisodio(ptrEpisodio);
          break; 
      case 13:
          //muestra los capitulos de la serie que contenga el mismo id
          cout << "Ingresa el ID de la serie: ";
          cin >> sId;
          series.mostrarEps(sId);
          break;
      case 14:
          //muestra los episodios que tengan la misma calificación de la serie con el mismo id 
          cout << "Ingresa el ID de la serie: ";
          cin >> sId;
          cout << "Ingresa la calificacion que busca: ";
          cin >> dCal;
          series.consultaEpsConCalificacion(sId, dCal);
          break;
      default:
          // en caso de que se proporcione cualquier número que no esté dentro de las opciones se despliega el siguente mensaje
          cout << "Opcion Incorrecta!!\n";
          break;
    }
    iOpcion = menuPeliculas();
  }
  return 0;
}
