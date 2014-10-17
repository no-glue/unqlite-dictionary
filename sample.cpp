#include <string>
#include <iostream>
extern "C"
{
#include <unqlite.h>
}

using namespace std;

int main() {
  int code;
  unqlite * db;
  size_t size;
  char * buffer;

  code = unqlite_open(&db, ":mem:", UNQLITE_OPEN_CREATE);
  if(code != UNQLITE_OK) return 1;
  unqlite_kv_append(db, "a", -1, "a", 1);
  unqlite_kv_append(db, "a", -1, "b", 1);
  unqlite_kv_append(db, "a", -1, "c", 1);
  unqlite_kv_append(db, "a", -1, "dd", 2);
  unqlite_kv_append(db, "a", -1, "ee", 2);
  unqlite_kv_fetch(db, "a", -1, NULL, &size);
  // get the size
  buffer = new char[size];
  unqlite_kv_fetch(db, "a", -1, buffer, &size);
  cout<<"a "<<buffer<<endl;
  delete buffer;
  unqlite_close(db);
}