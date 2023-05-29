#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QString enderecoArquivo = QFileDialog::getOpenFileName(this,"Selecione o arquivo", QDir::homePath(), "Todos os arquivos(*.*)");
    std::fstream arquivoRead;
    std::string linha;
    //QString disciplinaQs;
    arquivoRead.open(enderecoArquivo.toStdString().c_str());
    if(arquivoRead.is_open()){
        Aluno* objetoAluno;
        while(std::getline(arquivoRead,linha))
{
            QString linhaQt=QString::fromStdString(linha);
            try{
                objetoAluno = new Aluno(linhaQt);
            }
            catch(QString &erro){
                QMessageBox::critical(this,"ERRO", erro);
            }


//            QStringList lista=linhaQt.split(';');

//            if(lista.size()!=3)
//                throw QString ("Formato inválido.");
//            objetoAluno->setMatricula(lista[0]);
//            objetoAluno->setCurso(lista[0]);
//            objetoAluno->setNome(lista[1]);
//            QDebug>>lista[1]>>"\n";

//            QStringList listaTurmas=lista[3].split(' ');

//            for(auto it=listaTurmas.begin(); it!=listaTurmas.end(); it++)
//            {
//                DisciplinaTurma* objetoDisciplina = new DisciplinaTurma;
//                disciplinaQs=*it;
//                objetoDisciplina->setDisciplinaTurma(disciplinaQs);
//                objetoAluno->setDisciplinaTurma(objetoDisciplina);
//            }
            listaAlunos.push_back(objetoAluno);
        }
    }
    else{
        QMessageBox::critical(this,"ERRO", "Não foi possível abrir o arquivo.");
    }
}

void MainWindow::on_btn_disciplina_clicked()
{
    QString disciplina=ui->lineEdit->text();
    ui->textEdit->setText(Filtro::filtrarPorDisciplina(listaAlunos, disciplina));
}


void MainWindow::on_btn_turma_clicked()
{
    QString turma=ui->lineEdit->text();
    ui->textEdit->setText(Filtro::filtrarPorDisciplinaTurma(listaAlunos, turma));
}


void MainWindow::on_btn_curso_clicked()
{
    int curso=ui->lineEdit->text().toInt();
    ui->textEdit->setText(Filtro::filtrarPorCurso(listaAlunos, curso));
}


void MainWindow::on_btn_mostrar_turmas_clicked()
{
    QString matricula=ui->lineEdit->text();
    if(matricula=="Dinossauro"){
        //Colocar imagem legal
    }
    try{
        ui->textEdit->setText(Filtro::filtrarAluno(listaAlunos, matricula));
    }
    catch(QString &erro){
        QMessageBox::critical(this,"ERRO","Matrícula não listada.");
    }
}

void MainWindow::on_btn_abrir_janela_clicked()
{
    Janela2 form2;  //classe = Janela2, objeto = form 2
    QString selectedItem = ui->comboBox->currentText(); //Verifica valor da comboBox
    QString res;    //QString contendo todos os dados a serem mostrados
    bool continuarCodigo = false;
    form2.exec();   //Abre a segunda janela
    if(selectedItem=="Ordenar por curso"){
        form2.setLabel("Digite código do curso:");   //Atualiza label da segunda janela
        //Espera botão ser clicado para executar as proximas linhas

        int curso=form2.getLineEdit().toInt();  //Retorna uma QString contendo o valor, que é convertida para int
        res=(Filtro::filtrarPorCurso(listaAlunos, curso));  //Armazena valor a ser mostrado
        form2.close();
        ui->textEdit->setText(res);
        return;
    }
    if(selectedItem=="Ordenar por disciplina"){
        form2.setLabel("Digite código da disciplina:");   //Atualiza label da segunda janela
        QEventLoop loop;  // Cria um objeto QEventLoop
                QObject::connect(&form2, &Janela2::botaoClicado, &loop, &QEventLoop::quit);  // Conecta o sinal botaoClicado ao slot quit do QEventLoop

                while (true) {
                    loop.exec();  // Aguarda até que um evento seja processado

                    // Verifica se o botão foi clicado na segunda janela
                    if (form2.botaoFoiClicado()) {
                        int curso = form2.getLineEdit().toInt();  // Retorna uma QString contendo o valor, que é convertida para int
                        res = Filtro::filtrarPorCurso(listaAlunos, curso);  // Armazena valor a ser mostrado
                        form2.close();
                        ui->textEdit->setText(res);
                        return;
    }
    if(selectedItem=="Ordenar por turma"){
        form2.setLabel("Digite código e turma:");   //Atualiza label da segunda janela
        QString turma=form2.getLineEdit();  //Retorna uma QString contendo o valor
        res=(Filtro::filtrarPorDisciplinaTurma(listaAlunos, turma));  //Armazena valor a ser mostrado
        form2.close();
        ui->textEdit->setText(res);
        return;
    }
    if(selectedItem=="Mostrar turmas de um aluno"){
        form2.setLabel("Digite a matrícula do aluno:");   //Atualiza label da segunda janela
        QString matricula=form2.getLineEdit();  //Retorna uma QString contendo o valor
        res=(Filtro::filtrarAluno(listaAlunos, matricula));  //Armazena valor a ser mostrado
        form2.close();
        ui->textEdit->setText(res);
        return;
    }

}

