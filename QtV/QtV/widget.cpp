#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    string path = "C:/Users/Pavel/Desktop/lab/file5_1160_786.json";
    fin.open(path);
    fin.seekg(11,ios_base::cur); // первый сдвиг в потоке
    fin >> frames;
    fin.seekg(11,ios_base::cur); // сдвиг к значению высоты
    fin >> w;
    fin.seekg(12,ios_base::cur); // сдвиг к значению ширины
    fin >> h;
    fin.seekg(11,ios_base::cur); // сдвиг к началу матрицы пикселей
    cout << frames << " " << w << " " << h << endl;

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Widget::paint1);
    timer->start(30);
    paint1();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paint1() {
    //scene->clear();
    QImage image = QImage(w+1, h+1, QImage::Format_RGB32);
    tecFrame++;
    qDebug() << tecFrame;
    if(tecFrame == frames)
    {
       delete timer;
    }

    int r, g, b;
    fin.seekg(2,ios_base::cur);
    for(int i=0; i<w; i++)
        {
         //cout << "in" << endl;
            for(int j=0; j<h; j++)
            {
                fin >> r;
                fin.seekg(2,ios_base::cur);
                fin >> g;
                fin.seekg(2,ios_base::cur);
                fin >> b;
                fin.seekg(4,ios_base::cur);
                //qDebug() << r << " " << g << " " << b << " " << w << " " << h;
                image.setPixel(i, j, qRgb(r,g,b));
            }
        }
    //QImage image = QImage("C:/Users/Pavel/Desktop/bmp1.bmp");
    scene->addPixmap(QPixmap::fromImage(image));
    //scene->update();

};
