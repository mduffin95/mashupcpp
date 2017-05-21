#include "program.h"
#include "srtparser.h"
#include <QTextStream>
#include <QVector>

Program::Program(QString subFile, QString videoFile)
{
    SubtitleParserFactory *subParserFactory = new SubtitleParserFactory(subFile.toStdString());
    SubtitleParser *parser = subParserFactory->getParser();

    QString tmp = QString::fromStdString(parser->getFileData());

    std::vector<SubtitleItem*> sub = parser->getSubtitles();

    for(std::vector<SubtitleItem*>::iterator it = sub.begin(); it != sub.end(); ++it)
    {
        QString tmp = QString::fromStdString((*it)->getDialogue());
        text.append(tmp.simplified()).append(" ");
    }
}

QString Program::getText()
{
    return text;
}

QStringRef Program::getStringRef(int start, int len)
{
    return QStringRef(&text, start, len);
}
