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

    QString serialize();
    void deserialize(QString encoding);

private:
    Program *program; //TODO: remove this
    QStringRef ref;
};

Q_DECLARE_METATYPE(Segment*)



#endif // SEGMENT_H
