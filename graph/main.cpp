#include <QCoreApplication>
#include <iostream>
#include <graph.h>
#include <vertex.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Graph graph;
    graph.addVertex("1");
    graph.addVertex("2");
    graph.addVertex("3");
    graph.setVertexData(2, "A");
    graph.setVertexData(1, "15");
//    graph.setVertexData(2, "A");

    QVector<Vertex> vertices = graph.getVertices();

    for (int i = 0; i < vertices.size(); i ++)
    {
        std::cout << vertices[i].getNumber() << " : " << vertices[i].getData().toStdString() << std::endl;
    }


    return a.exec();
}
