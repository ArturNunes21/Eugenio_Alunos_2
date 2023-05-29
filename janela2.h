#ifndef JANELA2_H
#define JANELA2_H

#include <QDialog>

namespace Ui {
class Janela2;
}

class Janela2 : public QDialog
{
    Q_OBJECT

public:
    explicit Janela2(QWidget *parent = nullptr);
    void setLabel(QString);
    QString getLineEdit();
    bool botaoFoiClicado() const;
    void atualizarEstadoBotao();
    ~Janela2();

private slots:
    void on_pushButton_clicked();

    void on_btn_ordenar_clicked();

private:
    Ui::Janela2 *ui;
    bool m_botaoClicado;
};

#endif // JANELA2_H
