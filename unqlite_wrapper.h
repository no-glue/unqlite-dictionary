extern "C"
{
#include <unqlite.h>
}

template<typename Type>class UnqliteWrapper {
public:
  UnqliteWrapper() {open(db);}
  ~UnqliteWrapper() {close(db);}
  void insert(Type key, Type value) {insert(key, value, db);}
private:
  unqlite * db;
  void open(unqlite * & db) {unqlite_open(&db, ":mem:", UNQLITE_OPEN_CREATE);}
  void close(unqlite * & db) {unqlite_close(db);}
  void insert(Type key, Type value, unqlite * & db) {unqlite_kv_append(db, key.c_str(), -1, value.c_str(), value.length());}
};