#ifndef EMITTERCLASS_H
#define EMITTERCLASS_H

#include <QFrame>
#include <QObject>
class EmitterClass : public QObject
{
   Q_OBJECT

public:
    WId widgetID;
public slots:
   void ImageChangeFunction();
   void MechanicsErrorFunction();
   void WidSend();
signals:
   void ImageChangeSignal();
   void MechanicsErrorSignal();
   void WidSignal();
private:
};

#endif // EMITTERCLASS_H
