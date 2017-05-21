#ifndef SEGMENT_H
#define SEGMENT_H
#include "program.h"

#include <QListWidgetItem>

class Segment
{
public:
    //Segment() : program(NULL) {}
    Segment(Program *prog, int start, int end);

    QString getText();
    int getPosition();
    int getLength();

    int setPosition(int pos);
    int setLength(int len);

private:
    Program *program; //TODO: remove this
    QStringRef ref;
};

Q_DECLARE_METATYPE(Segment*)



#endif // SEGMENT_H
