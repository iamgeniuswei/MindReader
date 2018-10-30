#ifndef MRNOTEDATA_H
#define MRNOTEDATA_H
#include "odb/core.hxx"
#include <string>
#include <memory>
#include "mrdata_global.h"
#include "mrarticlemetadata.h"
/**
 * @brief The MRNoteData class
 */
#pragma db object
class MRDATASHARED_EXPORT MRNoteData
{
public:
    MRNoteData();

private:
    friend class odb::access;
#pragma db id auto
    unsigned long long _id = 0;
    unsigned int _index = 0;
    std::string _title;
    std::string _text;
    std::string _path;
    std::string _note;
#pragma db not_null
    std::shared_ptr<MRArticleMetaData> _article;

public:
    unsigned long long persist();
    void update();
    unsigned int index() const;
    void setIndex(unsigned int index);
    std::string title() const;
    void setTitle(const std::string &title);
    std::string text() const;
    void setText(const std::string &text);
    std::string path() const;
    void setPath(const std::string &path);
    std::string note() const;
    void setNote(const std::string &note);
    std::shared_ptr<MRArticleMetaData> article() const;
    void setArticle(const std::shared_ptr<MRArticleMetaData> &article);
};

#endif // MRNOTEDATA_H
