#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QPixmap>
#include <iostream>
#include <QPaintEvent>
#include <QPainter>

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

public slots:
    void setValue(int value);

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
    mGreenCircle = QPixmap ("GreenCircle.png");
    mYellowCircle = QPixmap ("YellowCircle.png");
    mRedCircle = QPixmap ("RedCircle.png");

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

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    app.exec();
}

#include <main.moc>
