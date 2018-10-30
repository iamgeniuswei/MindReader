/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ORMHelper.h
 * Author: lenovo
 *
 * Created on May 14, 2017, 2:45 PM
 */

#ifndef ORMHELPER_H
#define ORMHELPER_H

#include <memory>
#include <string>
#include <iostream>
#include "mrdata_global.h"
#ifdef DATAPERSISTENCE
#include <odb/core.hxx>
#include <odb/database.hxx>
using namespace odb::core;
#endif

class MRDATASHARED_EXPORT ORMHelper
{
private:
    ORMHelper();
    ORMHelper(const ORMHelper& orig) = delete;
public:
    virtual ~ORMHelper();
    static void initDB(const std::string& type,
            const std::string& user,
            const std::string& password,
            const std::string& db,
            const std::string& host = "",
            unsigned int port = 0);
    static void initializeSqlite(const std::string& sqlite_name);
    static void initializeTables();
#ifdef DATAPERSISTENCE
    static std::shared_ptr<database> db();

    /**
     * persist the std::shared_ptr<T> into database.
     * throw std::execption.
     * @param value
     * @return if succuss, the record's id,
     *         if fail, 0 
     */
    template<typename T>
    static unsigned long long persist(std::shared_ptr<T> value)
    {
        if (value == nullptr) {
            return 0;
        }

        unsigned long long id = 0;
        transaction t(_db->begin());
        id = _db->persist(*value);
        t.commit();
        return id;
    }

    /**
     * persist the T into database.
     * throw std::execption.
     * @param value
     * @return if succuss, the record's id,
     *         if fail, 0 
     */
    template<typename T>
    static unsigned long long persist(T value)
    {

        if (value == nullptr) {
            return 0;
        }

        unsigned long long id = 0;
        transaction t(_db->begin());
        id = _db->persist(value);
        t.commit();
        return id;
    }

    /**
     * update std::shared_ptr<T> in database.
     * throw std::exception.
     * @param value
     */
    template<typename T>
    static void update(std::shared_ptr<T> value)
    {
        if (value == nullptr) {
            return;
        }

        transaction t(_db->begin());
        _db->update(*value);
        t.commit();

    }

    /**
     * update T in database.
     * throw std::exception.
     * @param value
     */
    template<typename T>
    static void update(T value)
    {
        if (value == nullptr) 
        {
            return;
        }

        transaction t(_db->begin());
        _db->update(value);
        t.commit();

    }

#endif
private:
#ifdef DATAPERSISTENCE
    static std::shared_ptr<database> _db;
#endif
};

#endif /* ORMHELPER_H */

