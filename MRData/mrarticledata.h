#ifndef MRARTICLEDATA_H
#define MRARTICLEDATA_H

#include <QString>
#include "mrdata_global.h"
class MRDATASHARED_EXPORT MRArticleData
{
    enum TYPE{PDF, DOC};
public:
    MRArticleData();
    QString getFileName() const;
    void setFileName(const QString &value);

    QString getRelativePath() const;
    void setRelativePath(const QString &value);

    QString getAuthor() const;
    void setAuthor(const QString &value);

    int getPageCount() const;
    void setPageCount(int value);

    TYPE getType() const;
    void setType(const TYPE &value);

private:
    QString fileName;
    QString relativePath;
    QString author;
    int pageCount = 0;
    TYPE type;
};

#endif // MRARTICLEDATA_H
