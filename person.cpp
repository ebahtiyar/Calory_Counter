#include "person.h"

void Person::setWeigth(double weigth)
{
    if (m_weigth != weigth)
    {
        m_weigth = weigth;
        emit weigthChanged();
    }
}
