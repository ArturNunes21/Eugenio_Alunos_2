#include "janela2.h"
#include "ui_janela2.h"

Janela2::Janela2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela2)
{
    ui->setupUi(this);
    m_botaoClicado = false;
    QObject::connect(ui->btn_ordenar, &QPushButton::clicked, this, &Janela2::atualizarEstadoBotao);

}

Janela2::~Janela2()
{
    delete ui;
}

void Janela2::on_btn_ordenar_clicked()
{

}

void Janela2::setLabel(QString texto){
    ui->label->setText(texto);
}

QString Janela2::getLineEdit(){
    return ui->lineEdit_janela2->text();
}

bool Janela2::botaoFoiClicado() const
{
    return m_botaoClicado;
}

void Janela2::atualizarEstadoBotao()
{
    m_botaoClicado = true;
}

























