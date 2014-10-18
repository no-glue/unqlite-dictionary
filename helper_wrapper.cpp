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
  DoubleList<DoubleNode<string>, string> * list = new DoubleList<DoubleNode<string>, string>();
  Tokenizer * tokenizer = new Tokenizer();
  // tokenizer
  CstringWrapper * wrapper = new CstringWrapper();
  // wrapper for c strings
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
  >(wrapper, tokenizer);
  // tokenizer to work with list or something else
  UnqliteWrapper<string> * table = new UnqliteWrapper<string>();
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
  > * mem = new HelperWrapper<
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
  >(tokenizer, tokenizer_list, table);
  // memory store
  mem->insert("a", "a");
  mem->insert("a", "b");
  mem->insert("a", "c");
  mem->insert("a", "dd");
  mem->insert("a", "ee");
  mem->find("a", list);
  while(list->get_head()) {
    cout<<list->get_head()->key<<" "<<list->get_head()->value<<endl;
    list->pop_left();
  }
  delete list;
  delete tokenizer;
  delete wrapper;
  delete tokenizer_list;
  delete table;
  delete mem;
  return 0;
}