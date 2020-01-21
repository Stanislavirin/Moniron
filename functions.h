#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QtDebug>
#include <QtXml>
#include <QtCore>

#include <QMessageBox>
#include <QCryptographicHash>
#include <QHash>

//Получаем Хэш без служебных символов
QString GetModifiedHash(QString* input_Qstring);


#endif // FUNCTIONS_H
