#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "janela2.h"
#include "aluno.h"
#include "disciplinaturma.h"
#include "filtro.h"
#include <QMainWindow>
#include <list>
#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>
#include <iterator>
#include <QDebug>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_2_clicked();

    void on_btn_disciplina_clicked();

    void on_btn_turma_clicked();

    void on_btn_curso_clicked();

    void on_btn_mostrar_turmas_clicked();

    void on_btn_abrir_janela_clicked();

private:
    Ui::MainWindow *ui;

    std::list<Aluno*>listaAlunos;

    QString saida = "";

};
#endif // MAINWINDOW_H
