#include "aluno.h"

Aluno::Aluno(const QString linhaQt){
    QStringList lista=linhaQt.split(';');

    if(lista.size()!=3)
        throw QString ("Formato inválido.");
    matricula=lista[0];
    nome=lista[1];

    try{
        setCurso(lista[0]);
        setDisciplinaTurma(lista[2]);
    }
    catch(QString &erro){
        throw erro;
    }


//    objetoAluno->setMatricula(lista[0]);
//    objetoAluno->setCurso(lista[0]);
//    objetoAluno->setNome(lista[1]);
//    QDebug>>lista[1]>>"\n";

//    QStringList listaTurmas=lista[3].split(' ');

//    for(auto it=listaTurmas.begin(); it!=listaTurmas.end(); it++)
//    {
//        DisciplinaTurma* objetoDisciplina = new DisciplinaTurma;
//        disciplinaQs=*it;
//        objetoDisciplina->setDisciplinaTurma(disciplinaQs);
//        objetoAluno->setDisciplinaTurma(objetoDisciplina);
//    }
}

QString Aluno::getNome() const
{
    return nome;
}

void Aluno::setNome(const QString &newNome)
{
    nome = newNome;
}

int Aluno::getCurso() const
{
    return curso;
}

void Aluno::setCurso(const QString &matricula)
{
    QStringList curso=matricula.split('.');

    if(curso.size()!=4)
        throw QString ("Matricula inválida.");

    this->curso=curso[2].toInt();

//    QString curso = "";
//    for(int i = 7; i<=9; i++)
//    {
//        if(matricula[i] != '0' || curso != "")
//        {
//            curso += matricula[i];
//        }
//    }
//    this->curso = curso;
}

//bool Aluno::verificarDisciplina(QString disciplinaRef, QString turmaRef){
//    for(auto it=disciplinaTurma.begin(); it!=disciplinaTurma.end(); it++){
//        QString disciplina=(*it)->getDisciplina();
//        QString turma=(*it)->getTurma();
//        if(disciplina==disciplinaRef && turma==turmaRef){
//            return true;    //O aluno possui a Disciplina
//        }
//    }
//    return false;   //O aluno não possui esta disciplina
//}

int Aluno::getDisciplinaCursoTamanho(){
    return disciplinaTurma.size();
}

//void Aluno::setDisciplinaTurma(DisciplinaTurma* newDisciplinaTurma)
//{
//    disciplinaTurma.push_back(newDisciplinaTurma);
//}

//void Aluno::setDisciplinaTurma(QString disciplinas){
//    //Adiciona cada disciplina do aluno a uma lista
//    QStringList listaDisciplinas=disciplinas.split(' ');
//    for(int i=0; i<listaDisciplinas.size(); i++){
//        try{
//            DisciplinaTurma* objetoDisciplina = new DisciplinaTurma();
//            objetoDisciplina->setDisciplinaTurma(listaDisciplinas[i]);
//            disciplinaTurma.push_back(objetoDisciplina);
//        }
//        throw QString ("Erro ao adicionar disciplina a lista do objeto Aluno");
//    }
//}

void Aluno::setDisciplinaTurma(QString disciplinas) {
    //qDebug() << disciplinas;
    QStringList listaDisciplinas = disciplinas.split("  ");

    for (auto disciplina=listaDisciplinas.begin(); disciplina!=listaDisciplinas.end(); disciplina++) {
        try {
            DisciplinaTurma* objetoDisciplina = new DisciplinaTurma();
            //qDebug() << "Lista disciplinas : " << *disciplina;
            objetoDisciplina->setDisciplinaTurma(*disciplina);
            disciplinaTurma.push_back(objetoDisciplina);
        } catch (const QString& exception) {
            // Lidar com a exceção
            throw QString("Erro ao adicionar disciplina a lista do objeto Aluno: ") + exception;
        }
    }

//    for (int i = 0; i < listaDisciplinas.size(); i++) {
//        try {
//            DisciplinaTurma* objetoDisciplina = new DisciplinaTurma();
//            qDebug() << "Lista disciplinas[" << i << "]: " << listaDisciplinas[i];
//            objetoDisciplina->setDisciplinaTurma(listaDisciplinas[i]);
//            disciplinaTurma.push_back(objetoDisciplina);
//        } catch (const QString& exception) {
//            // Lidar com a exceção
//            throw QString("Erro ao adicionar disciplina a lista do objeto Aluno: ") + exception;
//        }
//    }
}


QString Aluno::getMatricula() const
{
    return matricula;
}

void Aluno::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
}

bool Aluno::verificaCurso(int curso)
{
    return this->curso == curso;
}

bool Aluno::verificaDisciplinaTurma(QString verificar)
{
    for(auto it=disciplinaTurma.begin(); it!=disciplinaTurma.end(); it++){
        if((*it)->getTurma()==verificar){
            return true;
        }
    }
    return false;
}

bool Aluno::verificaDisciplina(QString disciplina)
{
    for(auto it=disciplinaTurma.begin(); it!=disciplinaTurma.end(); it++){
        if(disciplina==(*it)->getDisciplina()){
            return true;
        }
    }
    return false;
}

bool Aluno::verificaAluno(QString matricula){
    return this->matricula==matricula;
}

QString Aluno::getTodasDisciplinas(){
    QString saida = "";
    for(auto it=disciplinaTurma.begin(); it!=disciplinaTurma.end(); it++){
        saida+=(*it)->getTurma() + " a";
    }
    return saida;
}












