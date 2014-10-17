#include <string>
#include <iostream>
#include "unqlite_wrapper.h"

using namespace std;

int main() {
  UnqliteWrapper<string> * table = new UnqliteWrapper<string>();
  char * result;
  table->insert("a", "a");
  table->insert("a", "b");
  table->insert("a", "c");
  table->insert("a", "dd");
  table->insert("a", "ee");
  result = new char[table->value_size("a")];
  table->find("a", result);
  cout<<"a "<<result<<endl;
  delete table;
  delete result;
};