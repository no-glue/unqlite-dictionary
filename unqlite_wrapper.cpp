#include <string>
#include "unqlite_wrapper.h"

using namespace std;

int main() {
  UnqliteWrapper<string> * table = new UnqliteWrapper<string>();
  delete table;
};