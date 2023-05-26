#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aluno.h"
#include "disciplinas.h"
#include <vector>
#include <fstream>
#include <QFileDialog>

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

Artur::Aluno pAluno;
Artur::Disciplinas pDisciplinas;

void MainWindow::on_btn_obter_dados_clicked()
{
    QString enderecoArquivo=QFileDialog::getOpenFileName(this,"Selecione o arquivo",QDir::homePath(),"Todos os arquivos(*.*)");  //Arquivo apenas para leitura
    std::string linha;      //Variável string para armazenar cada linha do arquivo
    QString disciplinaQs;
    std::ifstream arquivoRead;  //Arquivo apenas para leitura
    std::list<Artur::Aluno*> vetorPonteiros;   //Lista de ponteiros para cada objeto aluno criado
    arquivoRead.open(enderecoArquivo.toStdString().c_str());
    if (arquivoRead.is_open()){
        while (std::getline(arquivoRead, linha)){   //Armazena cada linha do arquivo em uma variável do tipo string
            Artur::Aluno* pAluno=new Artur::Aluno();   //A variável 'pAluno', do tipo ponteiro de objeto para a classe aluno é criada
            QString linhaQt=QString::fromStdString(linha);  //Passa a linha de string para QString, afim de realizar mais operações
            QStringList lista=linhaQt.split(';');   //Cria uma lista contendo as 3 colunas do arquivo

            //Atribuição de nome e matricula
            pAluno->setMatricula(lista[0]);  //Primeira coluna
            pAluno->setNome(lista[1]);       //Segunda coluna

            //Atribui disciplinas com a turma para o objeto
            QStringList listaTurmas=lista[3].split(' ');    //Separa cada disciplina em uma lista de QString
            for(auto it=listaTurmas.begin(); it!=listaTurmas.end(); it++){
                Artur::Disciplinas* pDisciplinas=new Artur::Disciplinas;  //A variável 'pDisciplinas', do tipo ponteiro de objeto para a classe Disciplinas é criada
                disciplinaQs=*it; //Atribui o valor apontado pelo iterator a uma QString
                pDisciplinas->setTurmaDisciplina(disciplinaQs);    //Atribui disciplina e turma para o objeto
                pAluno->setDisciplinaTurma(pDisciplinas);  //Ponteiro para nova disciplina/turma é atribuido a lista de disciplinas do objeto Aluno
            }
        }
    }
}

