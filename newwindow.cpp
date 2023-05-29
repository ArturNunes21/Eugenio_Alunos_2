#include "newwindow.h"
#include <QLabel>
#include <QVBoxLayout>

NewWindow::NewWindow(QWidget *parent)
    : QDialog(parent)
{
    // Configurar o layout da nova janela
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Nova Janela", this);
    layout->addWidget(label);

    setLayout(layout);
}
