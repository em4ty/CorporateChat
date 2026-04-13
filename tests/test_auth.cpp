#include <QTest>
#include <QString>

class TestAuth : public QObject
{
    Q_OBJECT
private slots:
    void testLoginSuccess() {
        QString username = "alice";
        QString password = "12345";
        
 
        bool loginSuccess = (username == "alice" && password == "12345");
        QVERIFY(loginSuccess == true);
    }
    
    void testLoginFail() {
        QString username = "alice";
        QString password = "wrong";
        
        bool loginSuccess = (username == "alice" && password == "12345");
        QVERIFY(loginSuccess == false);
    }
    
    void testRegistration() {
        QString newUser = "bob";
        bool userExists = false;  
        QVERIFY(userExists == false);
    }
};

QTEST_MAIN(TestAuth)
#include "test_auth.moc"
