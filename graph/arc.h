#ifndef ARC_H
#define ARC_H

#include <QObject>

class Arc
{
private:
    int _from;
    int _to;
    double _weight;
public:
    Arc() {}
    Arc(int *from, int *to, double *weight)
    {
        _from = *from;
        _to = *to;
        _weight = *weight;
    }

    double getWeight()
    {
        return _weight;
    }

    void setWeight(double *weight)
    {
        _weight = *weight;
    }

    int getFrom()
    {
        return _from;
    }

    int getTo()
    {
        return _to;
    }
};

#endif // ARC_H
