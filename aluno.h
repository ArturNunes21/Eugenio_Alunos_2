#ifndef ALUNO_H
#define ALUNO_H
#include <QString>
#include <list>

namespace Artur{

class aluno
{
public:
    QString nome;
    QString matricula;
    list<QString> turma;  //possui cccodigo da disciplina e a turma
    list<QString> disciplina; //apenas codigo da disciplina

    QString getNome() const;
    void setNome(const QString &newNome);
    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);
    QStringList getTurma() const;
    void setTurma(const QString newTurma);
    QStringList getDisciplina() const;
    void setDisciplina(const QStringList &newDisciplina);
};

}   //namespace
#endif // ALUNO_H
