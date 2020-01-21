#ifndef SCANERCLASS_H
#define SCANERCLASS_H

#include <QObject>

class ScanerClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    bool m_running;

public:
    explicit ScanerClass(QObject *parent = nullptr);
    bool running() const;

signals:
    void runningChanged(bool running);
    void finished();

public slots:
    void setRunning(bool running);
    void run();
    void ScanerInit();
    void ScanerStart();
    void ScanerRollback();
    void ScanerStop();

private:



};

#endif // SCANERCLASS_H
