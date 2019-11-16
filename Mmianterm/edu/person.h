#ifndef PERSON_H
#define PERSON_H
#include<QString>

class person
{
protected:
    QString name,Email;
public:
    person();
    void setName(QString a);
    void setEmail(QString a);
};

#endif // PERSON_H
