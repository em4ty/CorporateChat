#include <QTest>
#include "../ClientChat/message.h"

class TestMessage : public QObject
{
    Q_OBJECT
private slots:
    void testSerialization()
    {
        ChatMessage original;
        original.type = MsgType::TextMessage;
        original.from = "alice";
        original.to = "bob";
        original.content = "Hello!";
        
        QJsonObject json = original.toJson();
        ChatMessage restored = ChatMessage::fromJson(json);
        
        QCOMPARE(restored.type, original.type);
        QCOMPARE(restored.from, original.from);
        QCOMPARE(restored.to, original.to);
        QCOMPARE(restored.content, original.content);
    }
};

QTEST_MAIN(TestMessage)
#include "test_message.moc"