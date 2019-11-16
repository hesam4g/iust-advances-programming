#ifndef DANESHKADE_H
#define DANESHKADE_H
#include<QString>

class Daneshkade
{
protected:
    QString name,goruheAmuzeshi,tarikheTasis,address;

public:
    Daneshkade();
    void setName(QString a);
    void setGoruheAmuzesgi(QString a);
    void setTarikheTasis(QString a);
    void setAddress(QString a);
};

#endif // DANESHKADE_H
