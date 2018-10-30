/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ORMHelper.cpp
 * Author: lenovo
 * 
 * Created on May 14, 2017, 2:45 PM
 */

#include "ORMHelper.h"
#ifdef DATAPERSISTENCE
#include <odb/sqlite/database.hxx>
#endif
#include <iostream>
#include <QDebug>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
using namespace odb::core;
std::shared_ptr<database> ORMHelper::_db = nullptr;
ORMHelper::ORMHelper() {
}


ORMHelper::~ORMHelper() {
}

void ORMHelper::initDB(const std::string& type, const std::string& user, const std::string& password, const std::string& db, const std::string& host, unsigned int port) 
{
    try
    {
        if(type == "pgsql")
        {
//            _db = std::make_shared<odb::pgsql::database>(user, password, db, host, port);
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        std::cerr << "error#1: " << e.what()
                    << " @" << __func__
                    << " @" << __FILE__
                    << " @" << __LINE__ << std::endl;
#endif
    }
}

void ORMHelper::initializeSqlite(const std::string &sqlite_name)
{
    try {
        _db = std::make_shared<odb::sqlite::database>(sqlite_name,
                                                      SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
    } catch (std::exception &e)
    {
        qDebug() << e.what ();
    }
}

void ORMHelper::initializeTables()
{
    try {
        odb::transaction t(_db->begin ());
        odb::schema_catalog::create_schema (*_db, "MRArticleMetaData", false);
        odb::schema_catalog::create_schema (*_db, "MRNoteData", false);
        t.commit ();
    } catch (std::exception &e) {
        qDebug() << e.what ();
    }

}

std::shared_ptr<database> ORMHelper::db() 
{
    return _db;
}


