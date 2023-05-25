#include "aluno.h"
#include <list>

namespace Artur{

QString aluno::getMatricula() const
{
    return matricula;
}

void aluno::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
}

std::list<disciplinas *> aluno::getDisciplinaTurma() const
{
    //Decidir se a função retorna o ponteiro para um objeto,
    //o ponteiro para todos os objetos, ou uma QString contendo disciplina e turma
    //de um objeto, ou de todos
}

void aluno::setDisciplinaTurma(const std::list<disciplinas *> &newDisciplinaTurma)
{
    this->disciplinaTurma.push_back(newDisciplinaTurma);
}

QString aluno::getNome() const
{
    return nome;
}

void aluno::setNome(const QString &newNome)
{
    nome = newNome;
}

}   //namespace
