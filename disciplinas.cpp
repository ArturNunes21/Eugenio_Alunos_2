#include "disciplinas.h"

namespace Artur{

void disciplinas::setTurmaDisciplina(QString valor){
    QString codigoDisciplina="";
    QString turma="";
    for(int i=0; i<valor.size(); i++){
        if(i<6)
            codigoDisciplina+=valor[i];
        else if(i>=8)
            turma+=;
    }
    this->codigoDisciplina=codigoDisciplina;    //Atribui codigo ao objeto
    this->turma=turma;                         //Atribui a turma ao objeto
}

}   //namespace
