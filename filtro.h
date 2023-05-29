#ifndef FILTRO_H
#define FILTRO_H

#include <QString>

#include "aluno.h"
#include "disciplinaturma.h"

class Filtro
{
public:
    static QString filtrarPorCurso(const std::list<Aluno*> &, int);
    static QString filtrarPorDisciplina(const std::list<Aluno*> &, QString);
    static QString filtrarPorTurma(const std::list<Aluno*> &, QString);
    static QString filtrarPorDisciplinaTurma(const std::list<Aluno*> &, QString);
    static QString filtrarAluno(const std::list<Aluno*> &, QString);

};

#endif // FILTRO_H
