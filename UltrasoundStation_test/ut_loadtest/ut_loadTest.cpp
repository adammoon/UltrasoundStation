#include "SignRequest.h"
#include "LoadReqProcessServer.h"

#include <QtTest/QtTest>

class QUt_LoadTest:public QObject{
    Q_OBJECT
private slots:
    void test();
};
void QUt_LoadTest::test(){
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}
QTEST_MAIN(QUt_LoadTest)
#include "qut_loadtest.moc"
