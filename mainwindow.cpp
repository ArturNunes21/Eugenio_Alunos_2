#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aluno.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Artur::aluno pAluno;

void MainWindow::on_btn_obter_dados_clicked()
{
    ifstream arqRead;
    string linha;
    QString disciplina="";
    vector<aluno*> vetorPonteiros;
    arqRead.open("C:/Users/artur/QT Creator Projects/Eugenio_Alunos/ArquivoAlunosDisciplinas2023.csv");
    if (arqRead.is_open()){
        while (std::getline(arqRead, linha)){
            pAluno=new aluno;
            QString linhaQt=QString::fromStdString(linha);
            QStringList lista=linhaQt.split(';');

            pAluno.setMatricula(lista[0]);
            pAluno.setNome(lista[1]);
            QStringList listaTurmas=lista[3].split(' ');
            for(int i=0; i<listaTurmas.size(); i++){
                QString turma=listaTurmas[i];
                pAluno.setTurma(turma);  //a turma deve ser inserida na lista de turmad do Aluno
            }
            for(int i=0; i<listaTurmas,size(); i++){
                QString aux=listaTurmas[i];
                for(int i=9; i<aux.size(); i++){
                    disciplina+=aux[i];
                }
                pAluno.setDisciplina(disciplina);
            }
            vetorPonteiros.pushback(pAluno);
            disciplina="";
        }
    }
}

