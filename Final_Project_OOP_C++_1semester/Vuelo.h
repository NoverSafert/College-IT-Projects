#ifndef Vuelo_h
#define Vuelo_h

class Vuelo{
public:
        Vuelo();
        Vuelo(string org, string des, int idd, int cap, Tiempo tiem, Tripulacion trip);
        void setOrigen(string org);
        string getOrigen();
        void setDestino(string des);
        string getDestino();
        void setId(int idd);
        int getId();
        void setCap(int cap);
        int getCap();
        void setTiempo(Tiempo tiem);
        Tiempo getTiempo();
        void setTripulacion(Tripulacion trip);
        Tripulacion getTripulacion();

private:
        string origen;
        string destino;
        int id;
        Tiempo tiempo;
        int capacidad;
        Tripulacion tripulacion;
};

Vuelo::Vuelo(){
    Tripulacion tripula ("", "");
    Tiempo time(0,0,0);
    origen = "";
    destino = "";
    id = 0;
    tiempo = time;
    capacidad = 0;
    tripulacion = tripula;
}

Vuelo::Vuelo(string org, string des, int idd, int cap, Tiempo tiem, Tripulacion trip){
    origen = org;
    destino = des;
    id = idd;
    tiempo = tiem;
    capacidad = cap;
    tripulacion = trip;
}

void Vuelo::setOrigen(string org){
    origen = org;
}

string Vuelo::getOrigen(){
    return origen;
}

void Vuelo::setDestino(string des){
    destino = des;
}

string Vuelo::getDestino(){
    return destino;
}

void Vuelo::setId(int idd){
    id = idd;
}

int Vuelo::getId(){
    return id;
}

void Vuelo::setCap(int cap){
    capacidad = cap;
}

int Vuelo::getCap(){
    return capacidad;
}

void Vuelo::setTiempo(Tiempo tiem){
    tiempo = tiem;
}

Tiempo Vuelo::getTiempo(){
    return tiempo;
}

void Vuelo::setTripulacion(Tripulacion trip){
    tripulacion = trip;
}

Tripulacion Vuelo::getTripulacion(){
    return tripulacion;
}

 #endif /* Vuelo_h */