#include "filtro.h"

QString Filtro::filtrarPorCurso(
        const std::list<Aluno*> &listaAlunos, int curso)

{
    QString saida="";
    for(auto aluno = listaAlunos.begin() ; aluno!=listaAlunos.end(); aluno++ ){
        if((*aluno)->verificaCurso(curso))
        {
            saida += (*aluno)->getMatricula() + " " + (*aluno)->getNome();
        }
    }
    return saida;
}

QString Filtro::filtrarPorDisciplinaTurma(
        const std::list<Aluno*> &listaAlunos, QString disciplinaTurma)
{
    QString saida="";
    for(auto aluno = listaAlunos.begin() ; aluno!=listaAlunos.end(); aluno++ ){
        if((*aluno)->verificaDisciplinaTurma(disciplinaTurma))
        {
            saida += (*aluno)->getMatricula() + " " + (*aluno)->getNome();
        }
    }
    return saida;
}

QString Filtro::filtrarPorDisciplina(
        const std::list<Aluno*> &listaAlunos, QString disciplina)
{
    {
        {
        QString saida="";
        for(auto aluno = listaAlunos.begin() ; aluno!=listaAlunos.end(); aluno++ ){
            if((*aluno)->verificaDisciplina(disciplina))
            {
                saida += (*aluno)->getMatricula() + " " + (*aluno)->getNome();
            }
        }
        return saida;
        }
    }
}

QString Filtro::filtrarAluno(
        const std::list<Aluno*> &listaAlunos, QString matricula)
{
    QString saida="";
    for(auto aluno = listaAlunos.begin() ; aluno!=listaAlunos.end(); aluno++ ){
        if((*aluno)->verificaAluno(matricula)){
            saida= (*aluno)->getTodasDisciplinas();
            return saida;
            //imprimi um dinosauro legal
        }
    }
    throw QString ("Matrícula não encontrada.");
}

//static QString Filtro::filtrarPorTurma(
//        const std::list<Aluno *> &listaAlunos, QString)
//{
//    for(auto aluno = listaAlunos.begin() ; aluno!=listaAlunos.end(); aluno++ ){
//        if()
//    }
//}












