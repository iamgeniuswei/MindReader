#include <QCoreApplication>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <memory>
#include <odb/sqlite/database.hxx>
#include <iostream>
#include "person.h"
#include "person-odb.hxx"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::shared_ptr<odb::sqlite::database> db;
    try {
        std::shared_ptr<odb::sqlite::database> db(new odb::sqlite::database("D:\\tools\\test.db",
                                                                            SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE));
        odb::transaction t(db->begin ());
        odb::schema_catalog::create_schema (*db);

        t.commit ();

        person john;
        person jane;
        person joe;
        odb::transaction t1(db->begin ());
        unsigned long john_id = db->persist(john);
        unsigned long jane_id = db->persist(jane);
        unsigned long joe_id = db->persist(joe);
        t1.commit ();
        std::cerr << john_id << " " <<jane_id << " " << joe_id << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what ();
    }


    return a.exec();
}
