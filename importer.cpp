#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "unqlite_wrapper.h"
#include "tokenizer.h"
#include "cstring_wrapper.h"
#include "double_node.h"
#include "double_list.h"
#include "tokenizer_list.h"
#include "helper_wrapper.h"

using namespace std;

int main() {
  string line;
  getline(cin, line);
  DoubleList<DoubleNode<string>, string> * results = new DoubleList<DoubleNode<string>, string>();
  Tokenizer * tokenizer = new Tokenizer(), * tokenizer_visited = new Tokenizer();
  // tokenizer
  CstringWrapper * str = new CstringWrapper(), * str_visited = new CstringWrapper();
  // str for c strings
  TokenizerList<
    string,
    CstringWrapper,
    DoubleList<DoubleNode<string>, string>,
    Tokenizer
  > * tokenizer_list = new TokenizerList<
    string,
    CstringWrapper,
    DoubleList<DoubleNode<string>, string>,
    Tokenizer
  >(str, tokenizer),
  * tokenizer_list_visited = new TokenizerList<
    string,
    CstringWrapper,
    DoubleList<DoubleNode<string>, string>,
    Tokenizer
  >(str_visited, tokenizer_visited);
  // tokenizer to work with list or something else
  UnqliteWrapper<string> * table_base = new UnqliteWrapper<string>(), * table_base_visited = new UnqliteWrapper<string>();
  // table for storing things
  HelperWrapper<
    string,
    DoubleList<DoubleNode<string>, string>,
    Tokenizer,
    TokenizerList<
      string,
      CstringWrapper,
      DoubleList<DoubleNode<string>, string>,
      Tokenizer
    >,
    UnqliteWrapper<string>
  > * table = new HelperWrapper<
    string,
    DoubleList<DoubleNode<string>, string>,
    Tokenizer,
    TokenizerList<
      string,
      CstringWrapper,
      DoubleList<DoubleNode<string>, string>,
      Tokenizer
    >,
    UnqliteWrapper<string>
  >(tokenizer, tokenizer_list, table_base),
  * table_visited = new HelperWrapper<
    string,
    DoubleList<DoubleNode<string>, string>,
    Tokenizer,
    TokenizerList<
      string,
      CstringWrapper,
      DoubleList<DoubleNode<string>, string>,
      Tokenizer
    >,
    UnqliteWrapper<string>
  >(tokenizer_visited, tokenizer_list_visited, table_base_visited);
  // table store
  delete results;
  delete tokenizer;
  delete tokenizer_visited;
  delete str;
  delete str_visited;
  delete tokenizer_list;
  delete tokenizer_list_visited;
  delete table_base;
  delete table_base_visited;
  delete table;
  delete table_visited;
  return 0;
}