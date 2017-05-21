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

int Segment::getPosition()
{
    return ref.position();
}

int Segment::getLength()
{
    return ref.length();
}

int Segment::setPosition(int pos)
{
    QStringRef tmp = ref;
    ref = QStringRef(tmp.string(), pos, tmp.length());
}

int Segment::setLength(int len)
{
    QStringRef tmp = ref;
    ref = QStringRef(tmp.string(), tmp.position(), len);
}
