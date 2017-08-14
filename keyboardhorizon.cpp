#include "keyboardhorizon.h"
#include "ui_keyboardhorizon.h"
#include <QPushButton>
#include <QDebug>

KeyboardHorizon::KeyboardHorizon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyboardHorizon)
{
    ui->setupUi(this);

    QPushButton *buttons[] = {
                                ui->btn0,
                                ui->btn1,
                                ui->btn2,
                                ui->btn3,
                                ui->btn4,
                                ui->btn5,
                                ui->btn6,
                                ui->btn7,
                                ui->btn8,
                                ui->btn9,
                                ui->btnConfirm,
                                ui->btnDel,
                                ui->btnBack
                             };

    for (int i = 0; i < (sizeof buttons / sizeof (QPushButton *)); i ++)
    {
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(myKeyPressEvent()));
    }
}

KeyboardHorizon::~KeyboardHorizon()
{
    delete ui;
}

void KeyboardHorizon::myKeyPressEvent()
{
    QString key = ((QPushButton *)this->sender())->text();

    emit this->myKeyPress(key);
}

void KeyboardHorizon::setConfirmState(bool lock)
{
    ui->btnConfirm->setEnabled(lock);
}

void KeyboardHorizon::setBackState(bool lock)
{
    ui->btnBack->setEnabled(lock);
}

void KeyboardHorizon::hideButtonConfirm()
{
    int x = ui->btnConfirm->x(),
        y = ui->btnConfirm->y(),
        width = ui->btnConfirm->width(),
        height = ui->btnConfirm->height();

    ui->btnConfirm->hide();
    ui->btnDel->setGeometry(x, y, width, height);
}

void KeyboardHorizon::setButtonConfirmState(bool state)
{
    ui->btnConfirm->setEnabled(state);
}
