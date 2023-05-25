#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aluno.h"
#include "disciplinas.h"
#include <vector>
#include <fstream>

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
Artur::disciplinas pDisciplinas;

void MainWindow::on_btn_obter_dados_clicked()
{
    std::ifstream arqRead;  //Arquivo apenas para leitura
    std::string linha;      //Variável string para armazenar cada linha do arquivo
    QString disciplinaQs;
    std::list<aluno*> vetorPonteiros;   //Lista de ponteiros para cada objeto aluno criado
    arqRead.open("C:/Users/artur/QT Creator Projects/Eugenio_Alunos/ArquivoAlunosDisciplinas2023.csv");
    if (arqRead.is_open()){
        while (std::getline(arqRead, linha)){   //Armazena cada linha do arquivo em uma variável do tipo string
            pAluno=new aluno;   //Cria um novo objeto da classe aluno
            QString linhaQt=QString::fromStdString(linha);  //Passa a linha de string para QString, afim de realizar mais operações
            QStringList lista=linhaQt.split(';');   //Cria uma lista contendo as 3 colunas do arquivo

            //Atribuição de nome e matricula
            pAluno.setMatricula(lista[0]);  //Primeira coluna
            pAluno.setNome(lista[1]);       //Segunda coluna

            //Atribui disciplinas com a turma para o objeto
            QStringList listaTurmas=lista[3].split(' ');    //Separa cada disciplina em uma lista de QString
            for(auto it=listaTurmas.begin(); it!=listaTurmas.end(); it++){
                pDisciplinas=new disciplinas;
                disciplinaQs=*it; //Atribui o valor apontado pelo iterator a uma QString
                pDisciplinas.setTurmaDisciplina(disciplinaQs);    //Atribui disciplina e turma para o objeto
                pAluno.setDisciplinaTurma(*pDisciplina);  //Ponteiro para nova disciplina/turma é atribuido a lista de disciplinas do objeto Aluno
            }
        }
    }
}

