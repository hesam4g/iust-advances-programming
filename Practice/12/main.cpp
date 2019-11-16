#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;

class CDummy {
public:
static int n;
CDummy () { n++; };
~CDummy () { n--; };
};

int CDummy::n=100;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    CDummy a;
    CDummy * c = new CDummy;
    cout << a.n << endl;
    delete c;
    cout << CDummy::n << endl;
    return app.exec();
}
