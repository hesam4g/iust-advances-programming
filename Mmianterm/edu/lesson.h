#ifndef LESSON_H
#define LESSON_H
#include<QString>
#include<QDate>
#include<QList>

class Lesson
{
protected:
    QString name,ostad,pishNiaz,hamNiaz;
    QDate tarikheEEmtehan;
    int tedadeVahed,zarfiat;

public:
    Lesson();
    void setName(QString a);
    void setTedadeVahed(int a);
    void setOstad(QString a);
    void setPishNiaz(QString a);
    void setHamNiaz(QString a);
    void setZarfiat(int a);
    void setTarkheEmtehan(QDate a);
};


#endif // LESSON_H
