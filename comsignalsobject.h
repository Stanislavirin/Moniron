#ifndef COMSIGNALSOBJECT_H
#define COMSIGNALSOBJECT_H
#include <QObject>

class ComSignalsObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

    bool m_running;
    QString m_message;
    int count;

public:
    explicit ComSignalsObject(QObject *parent = nullptr);
    bool running() const;
    QString message() const;

private:


signals:
    void finished();
    void runningChanged(bool running);
    void messageChanged(QString message);
    void ShowYesConnection();
    void ShowNoConnection();

public slots:
    void run();
    void setRunning(bool running);
    void setMessage(QString message);
    void Connect();
};

#endif // COMSIGNALSOBJECT_H
