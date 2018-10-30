#ifndef PERSON_H
#define PERSON_H
#include <odb/core.hxx>
#include <string>
#pragma db object
class person
{
public:
    person();
private:
    friend class odb::access; // (4)
    #pragma db id auto // (5)
    unsigned long id_; // (5)
    std::string first_;
    std::string last_;
    unsigned short age_;
};

#endif // PERSON_H
