#ifndef ScanerClass_H
#define ScanerClass_H

#include <QObject>

#include "scaner_new_test.h"


class ScanerClass : public QObject
{
    Q_OBJECT
public:
    explicit ScanerClass(QObject *parent = nullptr);

signals:

public slots:

private:
    void Scaner_start();

};

#endif // STARTCOMMANND_H
