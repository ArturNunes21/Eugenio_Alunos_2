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
    QString curso;
    std::list<disciplinas*> disciplinaTurma;  //possui codigo da disciplina e a turma
private:
    QString getNome() const;
    void setNome(const QString &newNome);
    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);
    std::list<disciplinas *> getDisciplinaTurma() const;
    void setDisciplinaTurma(const std::list<disciplinas *> &newDisciplinaTurma);
};

}   //namespace
#endif // ALUNO_H
