
#ifndef Tripulacion_h
#define Tripulacion_h

class Tripulacion{
public:
        Tripulacion();
        Tripulacion(string nom, string puest);
        void setNombre(string nom);
        string getNombre();
        void setPuesto(string puest);
        string getPuesto();

private:
        string nombre;
        string puesto;
};

Tripulacion::Tripulacion(){
    nombre = "";
    puesto = "";
}

Tripulacion::Tripulacion(string nom, string puest){
    nombre = nom;
    puesto = puest;
}

void Tripulacion::setNombre(string nom){
    nombre = nom;
}
string Tripulacion::getNombre(){
    return nombre;
}
void Tripulacion::setPuesto(string puest){
    puesto = puest;
}
string Tripulacion::getPuesto(){
    return puesto;
}

#endif /* Tripulacion_h */