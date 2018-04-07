#ifndef VERTEX_H
#define VERTEX_H

#include <QObject>

class Vertex
{
private:
    int _number;
    QString _data;
public:
    Vertex() {}
    Vertex(int *number, QString *data)
    {
        _number = *number;
        _data = *data;
    }

    QString getData()
    {
        return _data;
    }

    int getNumber()
    {
        return _number;
    }

    void setData(QString *data)
    {
        _data = *data;
    }

    void setNumber(int *number)
    {
        _number = *number;
    }
};

#endif // VERTEX_H
