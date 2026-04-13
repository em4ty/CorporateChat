#include <QTest>
#include <QTcpSocket>

class TestNetwork : public QObject
{
    Q_OBJECT
private slots:
    void testSocketCreation() {
        QTcpSocket socket;
        QVERIFY(socket.state() == QAbstractSocket::UnconnectedState);
    }
    
    void testHostAddress() {
        QString host = "127.0.0.1";
        QVERIFY(!host.isEmpty());
    }
    
    void testPortRange() {
        int port = 12345;
        QVERIFY(port > 0 && port < 65536);
    }
};

QTEST_MAIN(TestNetwork)
#include "test_network.moc"
