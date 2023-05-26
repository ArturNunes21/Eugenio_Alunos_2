#include "Aluno.h"
#include <list>

namespace Artur{

QString Aluno::getMatricula() const
{
    return matricula;
}

void Aluno::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
}

std::list<Disciplinas *> Aluno::getDisciplinaTurma() const
{
    //Decidir se a função retorna o ponteiro para um objeto,
    //o ponteiro para todos os objetos, ou uma QString contendo disciplina e turma
    //de um objeto, ou de todos
}

void Aluno::setDisciplinaTurma(Disciplinas* newDisciplinaTurma) //Parametro é ponteiro para objeto da classe Disciplinas
{
    this->disciplinaTurma.push_back(newDisciplinaTurma);    //Insere ponteiro na lista do Aluno
}

QString Aluno::getCurso() const
{
    return curso;
}

void Aluno::setCurso(const QString &mat)
{
    QString curso="";
    for(int i=7;i<=9;i++){
        if(mat[i]!='0' || curso!=""){
            //Caso exista o numero 0 antes de outros, valor não é adicionado ao curso
            //Ex.: Mat="1999.2.028.1779", então Curso="28"
            //Ex.: Mat="2008.1.010.4514", então Curso="10"
            curso+=mat[i];
        }
    }
    this->curso=curso;  //Atribui numero do curso ao objeto Aluno
    return;
}

QString Aluno::getNome() const
{
    return nome;
}

void Aluno::setNome(const QString &newNome)
{
    nome = newNome;
}

}   //namespace
