#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QPixmap>
#include <iostream>

class Circle : public QWidget
{

};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    app.exec();
}

#include <main.moc>
