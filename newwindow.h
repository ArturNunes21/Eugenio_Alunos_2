#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QDialog>

class NewWindow : public QDialog
{
    Q_OBJECT

public:
    NewWindow(QWidget *parent = nullptr);
};

#endif // NEWWINDOW_H
