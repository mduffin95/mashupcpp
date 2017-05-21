#ifndef PROGRAM_H
#define PROGRAM_H
#include <QTextStream>

class Program
{
public:
    Program(QString subFile, QString videoFile);

    //TODO: Some sort of reference to video file

    QString getText();
    QStringRef getStringRef(int start, int len);
private:
    QString text;
    //QVector<QTime> _timeStamps;
};

#endif // PROGRAM_H
