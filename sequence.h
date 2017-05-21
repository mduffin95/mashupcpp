#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <QVector>
#include "segment.h"


class Sequence
{
public:
    Sequence();

    QVector<Segment*> segments;
};

#endif // SEQUENCE_H
