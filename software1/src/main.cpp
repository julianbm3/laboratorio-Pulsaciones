#include "lib_gr2.h"
#include "tty_lib2.h"
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc!=3){
        cout<<"Número de argumentos no válido, son dos argumentos"<<endl;
        return 0;
    }
    struct termios tty;
    int serial_port;
    int read_buf;
    int num_bytes;

    int n;
    int tiem_pre=(int)*argv[1]-48, tiem_ven=(int)*argv[2]-48;
    cout<<tiem_pre<<"\n"<<tiem_ven<<endl;

    config_tty("/dev/ttyS0",&tty,B9600,&serial_port);

    cout<<"Ingrese la cantidad de participantes"<<endl;
    cin>>n;

    Participante *p= new Participante[n];
    //Participante ParticS[1000];

    string nombre;

    int participant_id;

    for (int i=0; i < n; i++){
            cout<<"\nIngrese su nombre "<<(i+1)<<endl;
            cin>>nombre;

            cout<<"\nIngrese su id "<<(i+1)<<endl;
            cin>>participant_id;

            p[i].setParticipante(participant_id,nombre);
    }



    for (int i = 0;i < n;i++){
        
            cout<<"\nParticipante "<<(i+1)<<":\nNombre: "<<p[i].getParticipanteN()<<"\nCon el id: "<<p[i].getParticipanteP()<<endl;
            cout<<"start"<<endl;

            write(serial_port,"s",sizeof(char));
            sleep(tiem_pre);
            write(serial_port,"r",sizeof(char));
            sleep(tiem_ven);
            write(serial_port,"S",sizeof(char));
            num_bytes=read(serial_port, &read_buf, sizeof (char));
            cout<<"\n "<< read_buf<<endl;
            p[i].setPushed(num_bytes);

            cout<<"\nHizo: "<<p[i].getParticipanteV()<<" Pulsaciones\n\n***********************"<<endl;

    }
    int ant=p[0].getParticipanteV();
    int act;
    int ganador;

    for(int i=1;i < n; i++){
        act=p[i].getParticipanteV();
        if(act>ant){
            ganador=act;
        }
    }
    cout<<"!!GANADOR!!"<<endl;
    cout<<p[ganador].getParticipanteN()<<" con "<<p[ganador].getParticipanteV()<<" pulsaciones"<<endl;

    //system("pause");
    return 0;

}

