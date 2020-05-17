/* 
Programa realizado por José Enrique Damián Velázquez A00827513
con el propósito de tener un programa para que pueda leer datos de 
diversos archivos modificarlos y desplegar en la pantalla dichos datos
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Tiempo.h"
#include "Tripulacion.h"
#include "Vuelo.h"

//Función que lee los archivos de Vuelo.txt, Tiempo.txt y Tripulacion.txt para 
//cargarlos en sus respectivos objetos.
void cargaVuelo(Vuelo vuelo[10], Tiempo infoTiempo[10], Tripulacion infoTripulacion[10], int &cantTripulacion, int &cantV){

    string org, des, nom, puesto;
    int idd, cap, dur, hor, minutos, i, j, k ;

    ifstream archEnt1;
    ifstream archEnt2;
    ifstream archEnt3;

    archEnt1.open("Tiempo.txt");
    i = 0;
    while(archEnt1 >> dur >> hor >> minutos){
        infoTiempo[i].setDuracion(dur);
        infoTiempo[i].setHoraDeSalida(hor);
        infoTiempo[i].setMinu(minutos);
        i++;
    }
    archEnt1.close();

    archEnt2.open("Tripulacion.txt");
    j = 0;
    while(archEnt2 >> nom >> puesto){
        infoTripulacion[j].setNombre(nom);
        infoTripulacion[j].setPuesto(puesto);
        j++;
    }
    cantTripulacion = j;
    archEnt2.close();

    archEnt3.open("Vuelos.txt");
    k = 0;
    while(archEnt3 >> org >> des >> idd >> cap){
        vuelo[k].setOrigen(org);
        vuelo[k].setDestino(des);
        vuelo[k].setId(idd);
        vuelo[k].setCap(cap);
        vuelo[k].setTiempo(infoTiempo[k]);
        vuelo[k].setTripulacion(infoTripulacion[k]);
        k++;
    }
    cantV = k;
    archEnt3.close();
}

//Función para mostrar los datos del objetos vuelo en la consola.
void muestraVuelos(Vuelo vuelo[10], int cantVuelos){
    Tiempo hora;
    Tripulacion trip;
    cout << "Origen Destino   Id  Capacidad  Hora de Salida  Duración Tripulación\n"; 
    for(int i = 0; i < cantVuelos; i++){
        cout << vuelo[i].getOrigen() << "     " ;
        cout << vuelo[i].getDestino() << "  ";
        cout << vuelo[i].getId() << "       ";
        cout << vuelo[i].getCap() << "          ";
        cout << vuelo[i].getTiempo().getHoraDeSalida() << ":" << vuelo[i].getTiempo().getMinu() << "    ";
        cout << vuelo[i].getTiempo().getDuracion() << " horas    ";
        cout << vuelo[i].getTripulacion().getNombre() << " " << vuelo[i].getTripulacion().getPuesto() << "\n";
    }
}

//Función muestra en la consola los datos del objeto de Tripulación.
void muestraTripulacion(Tripulacion trip[10], int cantTrip){
    cout << "Nombre  Puesto\n";
    for (int i = 0; i < cantTrip; i++){
        cout << trip[i].getNombre() << " " << trip[i].getPuesto() << "\n";
    }
}

//Esta función agrega valores al objeto vuelos.
void darAltaVuelo(Vuelo vuelo[10], int &cant){
    string org, des;
    int idd, cap, dur, hor, minutos;
    cout << "Ingrese las siglas del lugar de origen.\n";
    cin >> org;
    vuelo[cant].setOrigen(org);
    cout << "Ingrese las siglas del lugar de destino. \n";
    cin >> des;
    vuelo[cant].setDestino(des);
    cout << "Ingrese el Id del vuelo.\n";
    cin >> idd;
    vuelo[cant].setId(idd);
    cout << "Ingrese la capacidad máxima del vuelo.\n";
    cin >> cap;
    vuelo[cant].setCap(cap);
    cout << "Ingrese la hora de salida.\n";
    cin >> hor;
    cout << "Ingrese los minutos.\n";
    cin >> minutos;
    cout << "Ingrese la duración del vuelo.\n";
    cin >> dur;
    Tiempo time;
    time.setDuracion(dur);
    time.setHoraDeSalida(hor);
    time.setMinu(minutos);
    vuelo[cant].setTiempo(time);
    cant++;
}

//Función para agregar valores al objeto tripulación.
void darAltaTrip(Tripulacion Trip[10], Vuelo vuelo[10], int &cant){
    string nom, puesto;
    cout << "Ingrese el nombre\n";
    cin >> nom;
    Trip[cant].setNombre(nom);
    cout << "Ingrese el puesto\n";
    cin >> puesto;
    Trip[cant].setPuesto(puesto);
    vuelo[cant].setTripulacion(Trip[cant]);
    cant++;
}

int main(){
    int cantVuelos, cantTrip, opcion;
    Vuelo vuelos[10];
    Tiempo infoTiempo[10];
    Tripulacion infoTripulacion[10];
    cargaVuelo(vuelos, infoTiempo, infoTripulacion, cantTrip, cantVuelos);
    do
    {
        cout << "Escriba el número de la opción que quiera hacer.\n";
        cout << "Ver vuelos disponibles. = 1 \n" ;
        cout << "Ver tripulación = 2 \n";
        cout << "Dar de alta un vuelo. = 3 \n" ;
        cout << "Dar de alta a más tripulación = 4 \n";
        cout << "Salir = 5 \n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            muestraVuelos(vuelos, cantVuelos);
            break;

        case 2:
            muestraTripulacion(infoTripulacion, cantTrip);
            break;
        
        case 3:
            darAltaVuelo(vuelos, cantVuelos);
            break;

        case 4:
            darAltaTrip(infoTripulacion, vuelos, cantTrip);
            break;

        default:
            break;
        }
    } while ( opcion != 5);
    
    return 0;
}