#include "disciplinaturma.h"

QString DisciplinaTurma::getDisciplina() const
{
    return disciplina;
}


QString DisciplinaTurma::getTurma() const
{
    return turma;
}

void DisciplinaTurma::setDisciplinaTurma(QString &disciplinaTurma)
{
    QString disciplina = "";
    for(int i=0; i<=6; i++)
    {
        disciplina += disciplinaTurma[i];
    }
    qDebug() << "Codigo : " << disciplina;
    this->disciplina = disciplina;
    this->turma = disciplinaTurma;
}


































