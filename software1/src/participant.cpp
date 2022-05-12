
#include "lib_gr2.h"

Participante::Participante(){
}

//Esctablecemos valores a los atributos
void Participante::setParticipante(int _participant_id,string _nombre){
        participant_id = _participant_id;
        nombre = _nombre;
}
void Participante::setPushed(int _veces_pushed){
    veces_pushed = _veces_pushed;
}


int Participante::getParticipanteP(){
        return participant_id;
}

string Participante::getParticipanteN(){
        return nombre;
}
int Participante::getParticipanteV(){
        return veces_pushed;
}