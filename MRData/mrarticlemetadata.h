#ifndef MRARTICLEMETADATA_H
#define MRARTICLEMETADATA_H
#include <string>
#include "odb/core.hxx"
#include "mrdata_global.h"
#pragma db object
class MRDATASHARED_EXPORT MRArticleMetaData
{
public:
    MRArticleMetaData();

private:
    friend class odb::access;
#pragma db id auto
    unsigned long long _id = 0;
    unsigned int _pages = 0;
    std::string _title;
#pragma db unique
    std::string _relative_path;
    std::string _author;
    std::string _publisher;
    std::string _isbn;
    std::string _year;
public:
    unsigned long long persist();
    bool exist(const std::string &tilte, const std::string &dir);
    bool query();
    unsigned int pages() const;
    void setPages(unsigned int pages);
    std::string title() const;
    void setTitle(const std::string &title);
    std::string relative_path() const;
    void setRelative_path(const std::string &relative_path);
    std::string author() const;
    void setAuthor(const std::string &author);
    std::string publisher() const;
    void setPublisher(const std::string &publisher);
    std::string isbn() const;
    void setIsbn(const std::string &isbn);
    std::string year() const;
    void setYear(const std::string &year);
};

#endif // MRARTICLEMETADATA_H
