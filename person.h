#ifndef PERSON_H
#define PERSON_H

#include <QObject>
class Person : public QObject
{
    Q_OBJECT
public:
    double weigth()const {return m_weigth;}
    void setWeigth(double weigth);

signals:
    void weigthChanged();

private:
    double m_weigth = 0;
};

#endif // PERSON_H
