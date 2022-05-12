#ifndef LIB_GR2_H
#define LIB_GR2_H


#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class Participante{
        private://Atributos
            int participant_id;
            string nombre;
            int veces_pushed;
        public: //Metodos
            Participante();
                void setParticipante(int,string);
                void setPushed(int);
                int getParticipanteP();
                string getParticipanteN();
                int getParticipanteV();
};

#endif