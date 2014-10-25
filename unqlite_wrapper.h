extern "C"
{
#include <unqlite.h>
}

template<typename Type>class UnqliteWrapper {
public:
  UnqliteWrapper():longest_chain(0) {open(db);}
  ~UnqliteWrapper() {close(db);}
  void insert(Type key, Type value) {insert(key, value, db);}
  bool insert_unique(Type key, Type value) {return insert_unique(key, value, db);}
  bool exists(Type key) {return exists(key, db);}
  void find(Type key, char * result) {find(key, result, db, longest_chain);}
  void remove(Type key) {remove(key, db);}
  int value_size(Type key) {return value_size(key, db);}
  unsigned int get_longest_chain() {return longest_chain;}
private:
  unqlite * db;
  unsigned int longest_chain;
  void open(unqlite * & db) {unqlite_open(&db, ":mem:", UNQLITE_OPEN_CREATE);}
  void close(unqlite * & db) {unqlite_close(db);}
  void insert(Type key, Type value, unqlite * & db) {unqlite_kv_append(db, key.c_str(), -1, (value + "|").c_str(), (value + "|").length());}
  bool insert_unique(Type key, Type value, unqlite * & db) {
    // insert unique key
    bool there = exists(key);
    if(!there) insert(key, value, db);
    return !there;
  }
  bool exists(Type key, unqlite * & db) {
    // check if key exists
    size_t size;
    int status;
    status = unqlite_kv_fetch(db, key.c_str(), -1, NULL, &size);
    return (status != UNQLITE_OK || !size) ? false : true;
  }
  void find(Type key, char * result, unqlite * & db, unsigned int & longest_chain) {
    // find value
    size_t size;
    int status;
    status = unqlite_kv_fetch(db, key.c_str(), -1, NULL, &size);
    longest_chain = size;
    if(status != UNQLITE_OK) return;
    status = unqlite_kv_fetch(db, key.c_str(), -1, result, &size);
  }
  int value_size(Type key, unqlite * & db) {
    // size of value
    size_t size;
    int status;
    status = unqlite_kv_fetch(db, key.c_str(), -1, NULL, &size);
    if(status != UNQLITE_OK) return 0;
    return size;
  }
  void remove(Type key, unqlite * & db) {
    // remove key
    unqlite_kv_delete(db, key.c_str(), -1);
  }
};