#ifndef SCANERCLASS2_H
#define SCANERCLASS2_H

#include <QObject>

class ScanerClass2 : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    bool m_running;

public:
    explicit ScanerClass2(QObject *parent = nullptr);
    bool running() const;

signals:
    void finished();
    void runningChanged(bool running);

public slots:
    void run();
    void setrunning(bool running);

//private:
//    void ScanerStart();
//    void ScanerInit();
//    void ScanerRollback();
//    void ScanerStop();


};

#endif // SCANERCLASS2_H
