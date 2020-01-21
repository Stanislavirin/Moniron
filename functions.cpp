#include "functions.h"



//Получаем Хэш без служебных символов
QString GetModifiedHash(QString* input_Qstring)
{
    QString stringInHash,hashResult;
    QByteArray bytearray;
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha512);

    bytearray=input_Qstring->toUtf8();
    hash->addData(bytearray);
    hashResult = hash->result();

    hashResult = hashResult.replace("/","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("\\","W",Qt::CaseSensitive);


    hashResult = hashResult.replace("<","W",Qt::CaseSensitive);
    hashResult = hashResult.replace(">","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("&","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("'","W",Qt::CaseSensitive);
    hashResult = hashResult.replace('"',"W",Qt::CaseSensitive);
  //  QChar f='"';
  // qDebug() << f << " " << f.unicode();
  //  f = 0x0022;
  //  qDebug() << f << " " << f.unicode();



    hashResult = hashResult.replace(" ","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("©","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("®","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("™","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("?","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("Ј","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("„","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("“","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("«","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("»","W",Qt::CaseSensitive);
    hashResult = hashResult.replace(">","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("<","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("≥","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("≤","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("≈","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("≠","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("≈","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("≡","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("§","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("&","W",Qt::CaseSensitive);
    hashResult = hashResult.replace("∞","W",Qt::CaseSensitive);
    //qDebug() << hashResult;
    return hashResult;
}
