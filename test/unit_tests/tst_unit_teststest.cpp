#include <QString>
#include <QtTest>
#include </home/tproo/Documents/projects/gits/graph/test/arc.h>
#include </home/tproo/Documents/projects/gits/graph/test/graph.h>
#include </home/tproo/Documents/projects/gits/graph/test/vertex.h>

class Unit_testsTest : public QObject
{
    Q_OBJECT
private:
    int from;
    int to;
    double weight;
    int number;
    QString data;
public:
    Unit_testsTest();



private Q_SLOTS:
    void testAddVertex1();
    void testAddArc1();
    void testDeleteVertex1();
    void testDeleteArc1();
    void testSetDataVertex();
    void testGetVertices();
    void testGetArcs();
};

Unit_testsTest::Unit_testsTest()
{
    from = 0;
    to = 1;
    weight = 12.2;
    number = 0;
    data = "1";
}

void Unit_testsTest::testAddVertex1()
{
    Graph graph;
    graph.addVertex(data);
    Vertex vertex(&number, &data);
    QVector<Vertex> vertices;
    vertices.push_back(vertex);
    QVERIFY((graph.getVertices()[0].getData() == vertices[0].getData()) &&
            (graph.getVertices()[0].getNumber() == vertices[0].getNumber()));
}

void Unit_testsTest::testAddArc1()
{
    Graph graph;
    graph.addVertex(data);
    graph.addVertex(data);
    graph.addArc(&from, &to, &weight);
    Arc arc(&from, &to, &weight);
    QVERIFY(arc.getFrom() == graph.getArcs()[0].getFrom());
}

void Unit_testsTest::testDeleteVertex1()
{
    Graph graph;
    graph.addVertex(data);
    graph.addVertex(data);
    int tempSize = graph.getVertices().size();
    graph.deleteVertex(&number);
    QVERIFY(tempSize == 2 && graph.getVertices().size() == 1);
}

void Unit_testsTest::testDeleteArc1()
{
    Graph graph;
    graph.addVertex(data);
    graph.addVertex(data);
    graph.addArc(&from, &to, &weight);
    int tempSize = graph.getArcs().size();
    graph.deleteArc(&from, &to);
    QVERIFY(tempSize == 1 && graph.getArcs().size() != 0);
}

void Unit_testsTest::testSetDataVertex()
{
    Graph graph;
    graph.addVertex(data);
    QString newData = "changed";
    Vertex vertex(&number, &newData);
    QVector<Vertex> vertices;
    vertices.push_back(vertex);
    bool temp = graph.getVertices()[0].getData() == data;
    graph.setVertexData(number, newData);
    QVERIFY(temp && (graph.getVertices()[0].getData() == newData));
}

void Unit_testsTest::testGetVertices()
{
    Graph graph;
    graph.addVertex(data);
    graph.addVertex(data);
    graph.addVertex(data);
    int num = 0;
    Vertex vertex1(&num, &data);
    num = 1;
    Vertex vertex2(&num, &data);
    num = 2;
    Vertex vertex3(&num, &data);
    QVector<Vertex> vertices;
    vertices.push_back(vertex1);
    vertices.push_back(vertex2);
    vertices.push_back(vertex3);
    QVERIFY(vertices == graph.getVertices());
}

void Unit_testsTest::testGetArcs()
{
    Graph graph;
    int a = 0, b = 0;
    double c = 0;
    graph.addArc(&a, &b, &c);
    graph.addArc(&a, &b, &c);
    graph.addArc(&a, &b, &c);

    Arc arc1(&a, &b, &c);
    Arc arc2(&a, &b, &c);
    Arc arc3(&a, &b, &c);
    QVector<Arc> arcs;
    arcs.push_back(arc1);
    arcs.push_back(arc2);
    arcs.push_back(arc3);

    QVERIFY(arcs == graph.getArcs());
}

QTEST_APPLESS_MAIN(Unit_testsTest)

#include "tst_unit_teststest.moc"
