
#ifndef Tiempo_h
#define Tiempo_h

class Tiempo{
public:
        Tiempo();
        Tiempo(int dur, int hor, int minutos);
        void setHoraDeSalida(int hor);
        int getHoraDeSalida();
        void setMinu(int minutos);
        int getMinu();
        void setDuracion(int dur);
        int getDuracion();

private:
        int duracion;
        int hora;
        int minu;
};

Tiempo::Tiempo(){
    duracion = 0;
    hora = 0;
    minu = 0;
}

Tiempo::Tiempo(int dur, int hor, int minutos){
    duracion = dur;
    hora = hor;
    minu = minutos;
}

void Tiempo::setHoraDeSalida(int hor){
    hora = hor;
}

int Tiempo::getHoraDeSalida(){
    return hora;
}

void Tiempo::setMinu(int minutos){
    minu = minutos;
}

int Tiempo::getMinu(){
    return minu;
}

void Tiempo::setDuracion(int dur){
    duracion = dur;
}

int Tiempo::getDuracion(){
    return duracion;
}
#endif /* Tiempo_h */