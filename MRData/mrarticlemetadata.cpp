#include "mrarticlemetadata.h"
#include "ORMHelper.h"
#include "mrarticlemetadata-odb.hxx"
MRArticleMetaData::MRArticleMetaData()
{

}

std::string MRArticleMetaData::year() const
{
    return _year;
}

void MRArticleMetaData::setYear(const std::string &year)
{
    _year = year;
}

std::string MRArticleMetaData::isbn() const
{
    return _isbn;
}

void MRArticleMetaData::setIsbn(const std::string &isbn)
{
    _isbn = isbn;
}

std::string MRArticleMetaData::publisher() const
{
    return _publisher;
}

void MRArticleMetaData::setPublisher(const std::string &publisher)
{
    _publisher = publisher;
}

std::string MRArticleMetaData::author() const
{
    return _author;
}

void MRArticleMetaData::setAuthor(const std::string &author)
{
    _author = author;
}

std::string MRArticleMetaData::relative_path() const
{
    return _relative_path;
}

void MRArticleMetaData::setRelative_path(const std::string &relative_path)
{
    _relative_path = relative_path;
}

std::string MRArticleMetaData::title() const
{
    return _title;
}

void MRArticleMetaData::setTitle(const std::string &title)
{
    _title = title;
}

unsigned int MRArticleMetaData::pages() const
{
    return _pages;
}

void MRArticleMetaData::setPages(unsigned int pages)
{
    _pages = pages;
}

unsigned long long MRArticleMetaData::persist()
{
    unsigned long long id =0;
    id = ORMHelper::persist<MRArticleMetaData*>(this);
    return id;
}
