#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QVector>
#include <vertex.h>
#include <arc.h>

class Graph
{
private:
    QVector<Vertex> _vertices;
    QVector<Arc> _arcs;
public:
    Graph() {}

    void addVertex(QString data)
    {
        int *number = new int(_vertices.size());
        Vertex *vertex = new Vertex(number, &data);
        _vertices.push_back(*vertex);
    }

    void deleteVertex(int *number)
    {
        //будет ли свопадать индекс вектора и индекс графа?
        for (int i = 0; i < _vertices.size(); i ++)
        {
            if (_vertices[i].getNumber() == *number)
            {
                for (int j = 0; j < _arcs.size(); j ++)
                {
                    if (_arcs[j].getFrom() == _vertices[i].getNumber() || _arcs[j].getTo() == _vertices[i].getNumber())
                    {
                        _arcs.remove(j);
                    }
                }
                //удалить еще и все ребра, которые связаны с этим узлом
                _vertices.remove(i);
                //перестроить номера в узлах
            }
        }
    }

    void setVertexData(int number, QString data)
    {
        //проверить на наличие
        _vertices[number].setData(&data);
    }

    void addArc(int *from, int *to, double *weight)
    {
        Arc *arc = new Arc(from, to, weight);
        _arcs.push_back(*arc);
    }

    void deleteArc(int *from, int *to)
    {
        for (int i = 0; i < _arcs.size(); i ++)
        {
            if (_arcs[i].getFrom() == *from && _arcs[i].getTo() == *to)
            {
                _arcs.remove(i);
            }
        }
    }

    QVector<Vertex> getVertices()
    {
        return _vertices;
    }

    QVector<Arc> getArcs()
    {
        return _arcs;
    }

};

#endif // GRAPH_H
