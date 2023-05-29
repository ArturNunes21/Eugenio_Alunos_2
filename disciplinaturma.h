#ifndef DISCIPLINATURMA_H
#define DISCIPLINATURMA_H
#include <QString>


class DisciplinaTurma
{
private:
    QString disciplina;
    QString turma;

public:   
    QString getDisciplina() const;

    QString getTurma() const;

    void setDisciplinaTurma(QString &disciplinaTurma);

};

#endif // DISCIPLINATURMA_H
