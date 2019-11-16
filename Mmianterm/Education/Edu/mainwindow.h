#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTextEdit>

#include <QtGui/QMainWindow>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    QTextEdit *_text ;

    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void profileClick();
    void akhzClick();
    void lessonsClick();
    void marksClick();
    void khooroojClick();



};


#endif // MAINWINDOW_H
