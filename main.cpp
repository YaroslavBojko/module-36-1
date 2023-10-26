#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QPixmap>
#include <iostream>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>

class Circle : public QWidget
{
    Q_OBJECT
public:
    Circle() = default;
    Circle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;
    void setGreen();
    void setYellow();
    void setRed();

private:
    QPixmap mCurrentCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
};

Circle::Circle(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mGreenCircle = QPixmap ("C:\\Users\\yaros\\CLionProjects\\module 36.1\\GreenCircle.png");
    mYellowCircle = QPixmap ("C:\\Users\\yaros\\CLionProjects\\module 36.1\\YellowCircle.png");
    mRedCircle = QPixmap ("C:\\Users\\yaros\\CLionProjects\\module 36.1\\RedCircle.png");

    mCurrentCircle = mGreenCircle;
    setGeometry(mCurrentCircle.rect());
}

void Circle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCircle);
}

QSize Circle::minimumSizeHint() const
{
    return QSize(100,100);
}

void Circle::setGreen()
{
    mCurrentCircle = mGreenCircle;
    update();
}

void Circle::setYellow()
{
    mCurrentCircle = mYellowCircle;
    update();
}

void Circle::setRed()
{
    mCurrentCircle = mRedCircle;
    update();
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    auto* window = new QWidget;
    window->setFixedSize(240,290);

    auto* circle = new Circle(window);
    circle->setFixedSize(200,200);
    circle->move(20,10);

    auto* slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->resize(200, 50);
    slider->move(20,230);
    slider->setParent(window);

    auto* layout = new QVBoxLayout(window);
    layout->addWidget(window);
    window->show();

    QObject::connect(slider, &QSlider::valueChanged, [slider,circle](int value)
    {
        if(value <= 33) circle->setGreen();
        else if(value > 33 && value <= 66) circle->setYellow();
        else circle->setRed();
        circle->update();
    });

    return app.exec();
}

#include <main.moc>
