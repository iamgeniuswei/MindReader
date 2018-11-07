#include "mrarticlemetadata.h"
#include "ORMHelper.h"
#include "mrarticlemetadata-odb.hxx"
#include <QDebug>
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

bool MRArticleMetaData::exist(const std::string& title,
                              const std::string& dir)
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db ();
        Q_ASSERT (db != nullptr );
        typedef odb::query<MRArticleMetaData> query;
        typedef odb::result<MRArticleMetaData> result;
        odb::transaction t(db->begin ());
        result r(db->query<MRArticleMetaData> (
                     query::title == title && query::relative_path == dir
                     ));
        qDebug() << "r.empty: " << r.empty ();
        t.commit ();


    } catch (std::exception &e)
    {
        qDebug() << e.what ();
        return  false;
    }
    return  true;
}

bool MRArticleMetaData::query()
{
    try
    {
        std::shared_ptr<database> db = ORMHelper::db ();
        Q_ASSERT (db != nullptr );
        typedef odb::query<MRArticleMetaData> query;
        typedef odb::result<MRArticleMetaData> result;
        odb::transaction t(db->begin ());
        result r(db->query<MRArticleMetaData> (
                     query::relative_path == _relative_path
                     ));
        if(!r.empty ())
        {
            result::iterator i(r.begin ());
            this->_id = i.id ();
            this->_pages = i->pages ();
            this->_author = i->author ();
            this->_publisher = i->publisher ();
            this->_isbn = i->isbn ();
            this->_year = i->year ();
        }
        t.commit ();


    } catch (std::exception &e)
    {
        qDebug() << e.what ();
        return  false;
    }
    return  true;
}
