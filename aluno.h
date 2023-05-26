#ifndef ALUNO_H
#define ALUNO_H

#include "disciplinas.h"
#include <QString>
#include <list>

namespace Artur{

class Aluno
{
private:
    QString nome;
    QString matricula;
    QString curso;
    std::list<Disciplinas*> disciplinaTurma;  //possui codigo da disciplina e a turma
public:
    QString getNome() const;
    void setNome(const QString &newNome);
    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);
    std::list<Disciplinas *> getDisciplinaTurma() const;
    void setDisciplinaTurma(Disciplinas* newDisciplinaTurma);
    QString getCurso() const;
    void setCurso(const QString &newCurso);
};

}   //namespace
#endif // ALUNO_H
