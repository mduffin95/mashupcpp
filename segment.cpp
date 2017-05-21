#include "segment.h"
#include <QListWidgetItem>

Segment::Segment(Program *prog, int start, int len) :
    program(prog)
{
    int offset = 10;
    int begin = (start-10 >=0) ? start-offset : 0;
    int maxLength = program->getText().length()-begin;
    int length = (len+2*offset <= maxLength)
            ? len+2*offset : maxLength;
    ref = this->program->getStringRef(begin, length);
}

QString Segment::getText()
{
    return ref.toString();
}

QString Segment::serialize()
{
    return QString::number(ref.position()) + "," + QString::number(ref.length());
}

void Segment::deserialize(QString encoding)
{
    QStringList result = encoding.split(',');
    Q_ASSERT(result.length() == 2);
    ref = program->getStringRef(result[0].toInt(), result[1].toInt());
}
