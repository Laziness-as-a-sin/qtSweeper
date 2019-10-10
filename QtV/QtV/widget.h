#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paint1();
    QGraphicsScene *scene;
    int frames, w, h;
    int tecFrame = 0;
    ifstream fin;
    QTimer *timer;
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
