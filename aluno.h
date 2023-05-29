#ifndef ALUNO_H
#define ALUNO_H
#include "disciplinaturma.h"
#include <QString>
#include <QStringList>
#include <list>


class Aluno
{
private:
    QString matricula;
    int curso;
    QString nome;
    std::list<DisciplinaTurma*>disciplinaTurma;

public:

    Aluno(const QString linhaQt);

    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);

    QString getNome() const;
    void setNome(const QString &newNome);

    int getCurso() const;
    void setCurso(const QString &matricla);

    //std::list<DisciplinaTurma *> getDisciplinaTurma() const;
    QString getDisciplinaTurma(int) const;
    //void setDisciplinaTurma(DisciplinaTurma* newDisciplinaTurma);
    void setDisciplinaTurma(QString disciplinas);

    int getDisciplinaCursoTamanho();

    bool verificaCurso(int);
    bool verificaDisciplinaTurma(QString);
    bool verificaDisciplina(QString);
    bool verificaAluno(QString);

    QString getTodasDisciplinas();
};

#endif // ALUNO_H
