// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "mrnotedata-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

#include <odb/sqlite/traits.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/simple-object-statements.hxx>
#include <odb/sqlite/container-statements.hxx>
#include <odb/sqlite/exceptions.hxx>
#include <odb/sqlite/simple-object-result.hxx>

namespace odb
{
  // MRNoteData
  //

  const char alias_traits<  ::MRArticleMetaData,
    id_sqlite,
    access::object_traits_impl< ::MRNoteData, id_sqlite >::article_tag>::
  table_name[] = "\"article\"";

  struct access::object_traits_impl< ::MRNoteData, id_sqlite >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      sqlite::connection&,
      image_type&,
      id_image_type&,
      sqlite::binding&,
      sqlite::binding&)
    {
    }
  };

  access::object_traits_impl< ::MRNoteData, id_sqlite >::id_type
  access::object_traits_impl< ::MRNoteData, id_sqlite >::
  id (const id_image_type& i)
  {
    sqlite::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      sqlite::value_traits<
          long long unsigned int,
          sqlite::id_integer >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::MRNoteData, id_sqlite >::id_type
  access::object_traits_impl< ::MRNoteData, id_sqlite >::
  id (const image_type& i)
  {
    sqlite::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      sqlite::value_traits<
          long long unsigned int,
          sqlite::id_integer >::set_value (
        id,
        i._id_value,
        i._id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::MRNoteData, id_sqlite >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // _id
    //
    t[0UL] = false;

    // _index
    //
    t[1UL] = false;

    // _title
    //
    if (t[2UL])
    {
      i._title_value.capacity (i._title_size);
      grew = true;
    }

    // _text
    //
    if (t[3UL])
    {
      i._text_value.capacity (i._text_size);
      grew = true;
    }

    // _path
    //
    if (t[4UL])
    {
      i._path_value.capacity (i._path_size);
      grew = true;
    }

    // _note
    //
    if (t[5UL])
    {
      i._note_value.capacity (i._note_size);
      grew = true;
    }

    // _article
    //
    t[6UL] = false;

    return grew;
  }

  void access::object_traits_impl< ::MRNoteData, id_sqlite >::
  bind (sqlite::bind* b,
        image_type& i,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    std::size_t n (0);

    // _id
    //
    if (sk != statement_update)
    {
      b[n].type = sqlite::bind::integer;
      b[n].buffer = &i._id_value;
      b[n].is_null = &i._id_null;
      n++;
    }

    // _index
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i._index_value;
    b[n].is_null = &i._index_null;
    n++;

    // _title
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i._title_value.data ();
    b[n].size = &i._title_size;
    b[n].capacity = i._title_value.capacity ();
    b[n].is_null = &i._title_null;
    n++;

    // _text
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i._text_value.data ();
    b[n].size = &i._text_size;
    b[n].capacity = i._text_value.capacity ();
    b[n].is_null = &i._text_null;
    n++;

    // _path
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i._path_value.data ();
    b[n].size = &i._path_size;
    b[n].capacity = i._path_value.capacity ();
    b[n].is_null = &i._path_null;
    n++;

    // _note
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i._note_value.data ();
    b[n].size = &i._note_size;
    b[n].capacity = i._note_value.capacity ();
    b[n].is_null = &i._note_null;
    n++;

    // _article
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i._article_value;
    b[n].is_null = &i._article_null;
    n++;
  }

  void access::object_traits_impl< ::MRNoteData, id_sqlite >::
  bind (sqlite::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::MRNoteData, id_sqlite >::
  init (image_type& i,
        const object_type& o,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    bool grew (false);

    // _id
    //
    if (sk == statement_insert)
    {
      long long unsigned int const& v =
        o._id;

      bool is_null (false);
      sqlite::value_traits<
          long long unsigned int,
          sqlite::id_integer >::set_image (
        i._id_value,
        is_null,
        v);
      i._id_null = is_null;
    }

    // _index
    //
    {
      unsigned int const& v =
        o._index;

      bool is_null (false);
      sqlite::value_traits<
          unsigned int,
          sqlite::id_integer >::set_image (
        i._index_value,
        is_null,
        v);
      i._index_null = is_null;
    }

    // _title
    //
    {
      ::std::string const& v =
        o._title;

      bool is_null (false);
      std::size_t cap (i._title_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i._title_value,
        i._title_size,
        is_null,
        v);
      i._title_null = is_null;
      grew = grew || (cap != i._title_value.capacity ());
    }

    // _text
    //
    {
      ::std::string const& v =
        o._text;

      bool is_null (false);
      std::size_t cap (i._text_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i._text_value,
        i._text_size,
        is_null,
        v);
      i._text_null = is_null;
      grew = grew || (cap != i._text_value.capacity ());
    }

    // _path
    //
    {
      ::std::string const& v =
        o._path;

      bool is_null (false);
      std::size_t cap (i._path_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i._path_value,
        i._path_size,
        is_null,
        v);
      i._path_null = is_null;
      grew = grew || (cap != i._path_value.capacity ());
    }

    // _note
    //
    {
      ::std::string const& v =
        o._note;

      bool is_null (false);
      std::size_t cap (i._note_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i._note_value,
        i._note_size,
        is_null,
        v);
      i._note_null = is_null;
      grew = grew || (cap != i._note_value.capacity ());
    }

    // _article
    //
    {
      ::std::shared_ptr< ::MRArticleMetaData > const& v =
        o._article;

      typedef object_traits< ::MRArticleMetaData > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::MRArticleMetaData > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_image (
          i._article_value,
          is_null,
          id);
        i._article_null = is_null;
      }
      else
        throw null_pointer ();
    }

    return grew;
  }

  void access::object_traits_impl< ::MRNoteData, id_sqlite >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // _id
    //
    {
      long long unsigned int& v =
        o._id;

      sqlite::value_traits<
          long long unsigned int,
          sqlite::id_integer >::set_value (
        v,
        i._id_value,
        i._id_null);
    }

    // _index
    //
    {
      unsigned int& v =
        o._index;

      sqlite::value_traits<
          unsigned int,
          sqlite::id_integer >::set_value (
        v,
        i._index_value,
        i._index_null);
    }

    // _title
    //
    {
      ::std::string& v =
        o._title;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i._title_value,
        i._title_size,
        i._title_null);
    }

    // _text
    //
    {
      ::std::string& v =
        o._text;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i._text_value,
        i._text_size,
        i._text_null);
    }

    // _path
    //
    {
      ::std::string& v =
        o._path;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i._path_value,
        i._path_size,
        i._path_null);
    }

    // _note
    //
    {
      ::std::string& v =
        o._note;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i._note_value,
        i._note_size,
        i._note_null);
    }

    // _article
    //
    {
      ::std::shared_ptr< ::MRArticleMetaData >& v =
        o._article;

      typedef object_traits< ::MRArticleMetaData > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::MRArticleMetaData > > ptr_traits;

      if (i._article_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_value (
          id,
          i._article_value,
          i._article_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<sqlite::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }
  }

  void access::object_traits_impl< ::MRNoteData, id_sqlite >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      sqlite::value_traits<
          long long unsigned int,
          sqlite::id_integer >::set_image (
        i.id_value,
        is_null,
        id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::MRNoteData, id_sqlite >::persist_statement[] =
  "INSERT INTO \"MRNoteData\" "
  "(\"id\", "
  "\"index\", "
  "\"title\", "
  "\"text\", "
  "\"path\", "
  "\"note\", "
  "\"article\") "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::MRNoteData, id_sqlite >::find_statement[] =
  "SELECT "
  "\"MRNoteData\".\"id\", "
  "\"MRNoteData\".\"index\", "
  "\"MRNoteData\".\"title\", "
  "\"MRNoteData\".\"text\", "
  "\"MRNoteData\".\"path\", "
  "\"MRNoteData\".\"note\", "
  "\"MRNoteData\".\"article\" "
  "FROM \"MRNoteData\" "
  "WHERE \"MRNoteData\".\"id\"=?";

  const char access::object_traits_impl< ::MRNoteData, id_sqlite >::update_statement[] =
  "UPDATE \"MRNoteData\" "
  "SET "
  "\"index\"=?, "
  "\"title\"=?, "
  "\"text\"=?, "
  "\"path\"=?, "
  "\"note\"=?, "
  "\"article\"=? "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::MRNoteData, id_sqlite >::erase_statement[] =
  "DELETE FROM \"MRNoteData\" "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::MRNoteData, id_sqlite >::query_statement[] =
  "SELECT\n"
  "\"MRNoteData\".\"id\",\n"
  "\"MRNoteData\".\"index\",\n"
  "\"MRNoteData\".\"title\",\n"
  "\"MRNoteData\".\"text\",\n"
  "\"MRNoteData\".\"path\",\n"
  "\"MRNoteData\".\"note\",\n"
  "\"MRNoteData\".\"article\"\n"
  "FROM \"MRNoteData\"\n"
  "LEFT JOIN \"MRArticleMetaData\" AS \"article\" ON \"article\".\"id\"=\"MRNoteData\".\"article\"";

  const char access::object_traits_impl< ::MRNoteData, id_sqlite >::erase_query_statement[] =
  "DELETE FROM \"MRNoteData\"";

  const char access::object_traits_impl< ::MRNoteData, id_sqlite >::table_name[] =
  "\"MRNoteData\"";

  void access::object_traits_impl< ::MRNoteData, id_sqlite >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    im._id_null = true;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj._id = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::MRNoteData, id_sqlite >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace sqlite;
    using sqlite::update_statement;

    callback (db, obj, callback_event::pre_update);

    sqlite::transaction& tr (sqlite::transaction::current ());
    sqlite::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj._id);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::MRNoteData, id_sqlite >::
  erase (database& db, const id_type& id)
  {
    using namespace sqlite;

    ODB_POTENTIALLY_UNUSED (db);

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::MRNoteData, id_sqlite >::pointer_type
  access::object_traits_impl< ::MRNoteData, id_sqlite >::
  find (database& db, const id_type& id)
  {
    using namespace sqlite;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::MRNoteData, id_sqlite >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::MRNoteData, id_sqlite >::
  reload (database& db, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj._id);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::MRNoteData, id_sqlite >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace sqlite;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::MRNoteData, id_sqlite >::object_type >
  access::object_traits_impl< ::MRNoteData, id_sqlite >::
  query (database&, const query_base_type& q)
  {
    using namespace sqlite;
    using odb::details::shared;
    using odb::details::shared_ptr;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        true,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) sqlite::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::MRNoteData, id_sqlite >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

namespace odb
{
  static bool
  create_schema (database& db, unsigned short pass, bool drop)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (pass);
    ODB_POTENTIALLY_UNUSED (drop);

    if (drop)
    {
      switch (pass)
      {
        case 1:
        {
          return true;
        }
        case 2:
        {
          db.execute ("DROP TABLE IF EXISTS \"MRNoteData\"");
          return false;
        }
      }
    }
    else
    {
      switch (pass)
      {
        case 1:
        {
          db.execute ("CREATE TABLE \"MRNoteData\" (\n"
                      "  \"id\" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\n"
                      "  \"index\" INTEGER NOT NULL,\n"
                      "  \"title\" TEXT NOT NULL,\n"
                      "  \"text\" TEXT NOT NULL,\n"
                      "  \"path\" TEXT NOT NULL,\n"
                      "  \"note\" TEXT NOT NULL,\n"
                      "  \"article\" INTEGER NOT NULL,\n"
                      "  CONSTRAINT \"article_fk\"\n"
                      "    FOREIGN KEY (\"article\")\n"
                      "    REFERENCES \"MRArticleMetaData\" (\"id\")\n"
                      "    DEFERRABLE INITIALLY DEFERRED)");
          return false;
        }
      }
    }

    return false;
  }

  static const schema_catalog_create_entry
  create_schema_entry_ (
    id_sqlite,
    "MRNoteData",
    &create_schema);
}

#include <odb/post.hxx>
