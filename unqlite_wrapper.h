extern "C"
{
#include <unqlite.h>
}

class UnqliteWrapper {
public:
  UnqliteWrapper() {open(db);}
  ~UnqliteWrapper() {close(db);}
private:
  unqlite * db;
  void open(unqlite * & db) {unqlite_open(&db, ":mem:", UNQLITE_OPEN_CREATE);}
  void close(unqlite * & db) {unqlite_close(db);}
};