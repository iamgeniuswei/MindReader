#include "mrnotedata.h"
#include "ORMHelper.h"
#include "mrnotedata-odb.hxx"
MRNoteData::MRNoteData()
{

}

std::shared_ptr<MRArticleMetaData> MRNoteData::article() const
{
    return _article;
}

void MRNoteData::setArticle(const std::shared_ptr<MRArticleMetaData> &article)
{
    _article = article;
}

std::string MRNoteData::note() const
{
    return _note;
}

void MRNoteData::setNote(const std::string &note)
{
    _note = note;
}

std::string MRNoteData::path() const
{
    return _path;
}

void MRNoteData::setPath(const std::string &path)
{
    _path = path;
}

std::string MRNoteData::text() const
{
    return _text;
}

void MRNoteData::setText(const std::string &text)
{
    _text = text;
}

std::string MRNoteData::title() const
{
    return _title;
}

void MRNoteData::setTitle(const std::string &title)
{
    _title = title;
}

unsigned int MRNoteData::index() const
{
    return _index;
}

void MRNoteData::setIndex(unsigned int index)
{
    _index = index;
}

unsigned long long MRNoteData::persist()
{
    unsigned long long id =0;
    id = ORMHelper::persist<MRNoteData*>(this);
    return id;
}

void MRNoteData::update()
{
    ORMHelper::update<MRNoteData*>(this);
}
