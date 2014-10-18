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
  DoubleList<DoubleNode<string>, string> * results = new DoubleList<DoubleNode<string>, string>();
  Tokenizer * tokenizer = new Tokenizer();
  // tokenizer
  CstringWrapper * str = new CstringWrapper();
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
  >(str, tokenizer);
  // tokenizer to work with list or something else
  UnqliteWrapper<string> * table_base = new UnqliteWrapper<string>();
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
  >(tokenizer, tokenizer_list, table_base);
  // table store
  table->insert("a", "a");
  table->insert("a", "b");
  table->insert("a", "c");
  table->insert("a", "dd");
  table->insert("a", "ee");
  table->insert("a", "ff");
  table->insert("a", "gg");
  table->insert("a", "hhh");
  table->insert("a", "iii");
  table->insert("a", "jjj");
  table->insert("a", "kkk");
  table->insert("a", "llll");
  table->insert("a", "mmmm");
  table->insert("a", "nnnn");
  table->insert("b", "a");
  table->insert("b", "b");
  table->insert("b", "c");
  table->insert("b", "dd");
  table->insert("b", "ee");
  table->insert("b", "ff");
  table->insert("b", "gg");
  table->insert("b", "hhh");
  table->insert("b", "iii");
  table->insert("b", "jjj");
  table->insert("b", "kkk");
  table->insert("b", "llll");
  table->insert("b", "mmmm");
  table->insert("b", "nnnn");
  table->find("a", results);
  table->find("b", results);
  while(results->get_head()) {
    cout<<results->get_head()->key<<" "<<results->get_head()->value<<endl;
    results->pop_left();
  }
  table->insert_unique("c", "a");
  table->insert_unique("c", "b");
  table->find("c", results);
  while(results->get_head()) {
    cout<<results->get_head()->key<<" "<<results->get_head()->value<<endl;
    results->pop_left();
  }
  cout<<"exists "<<table->exists("c")<<endl;
  delete results;
  delete tokenizer;
  delete str;
  delete tokenizer_list;
  delete table_base;
  delete table;
  return 0;
}