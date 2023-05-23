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

QStringList aluno::getTurma() const
{
    return turma;
}

void aluno::setTurma(const QString &newTurma)
{
    this->turma.push_back(newTurma);
}

QStringList aluno::getDisciplina() const
{
    return disciplina;
}

void aluno::setDisciplina(const QStringList &newDisciplina)
{
    this->disciplina.push_back(newDisciplina);
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
