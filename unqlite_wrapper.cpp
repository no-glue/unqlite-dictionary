#define SAMPLE_SIZE 16

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

using namespace std;

int main() {
  UnqliteWrapper<string> * table = new UnqliteWrapper<string>();
  char * result;
  int result_size;
  char tok[SAMPLE_SIZE];
  Tokenizer * tokenizer = new Tokenizer();
  DoubleList<
    DoubleNode<string>,
    string
  > * list = new DoubleList<
    DoubleNode<string>,
    string
  >();
  CstringWrapper * wrapper = new CstringWrapper();
  TokenizerList<
    string,
    CstringWrapper,
    DoubleList<
      DoubleNode<string>,
      string
    >,
    Tokenizer
  > * tokenizer_list = new TokenizerList<
    string,
    CstringWrapper,
    DoubleList<
      DoubleNode<string>,
      string
    >,
    Tokenizer
  >(wrapper, tokenizer);
  string key("a");
  string anotherkey("b");
  table->insert(key, "a");
  table->insert(key, "b");
  table->insert(key, "c");
  table->insert(key, "dd");
  table->insert(key, "ee");

  result_size = table->value_size(key);
  
  result = new char[result_size];
  table->find(key, result);
  cout<<"result size: "<<result_size<<endl;
  cout<<key<<" "<<result<<endl;

  tokenizer->set_buffer(result, result_size);
  while(tokenizer->token(tok)) {
    cout<<"token "<<tok<<endl;
    memset(tok, '\0', SAMPLE_SIZE);
  }
  cout<<"token "<<tok<<endl;
  memset(tok, '\0', SAMPLE_SIZE);

  tokenizer->rewind();
  tokenizer_list->tokens(key, list);
  while(list->get_head()) {
    cout<<"from list "<<list->get_head()->value<<endl;
    list->pop_left();
  }

  cout<<"exists "<<key<<" "<<table->exists(key)<<endl;
  cout<<"exists "<<anotherkey<<" "<<table->exists(anotherkey)<<endl;

  cout<<"insert unique "<<anotherkey<<" "<<table->insert_unique(anotherkey, "a")<<endl;
  cout<<"insert unique "<<anotherkey<<" "<<table->insert_unique(anotherkey, "b")<<endl;

  table->remove(anotherkey);
  cout<<"exists "<<anotherkey<<" "<<table->exists(anotherkey)<<endl;
  delete table;
  delete result;
  delete tokenizer;
  delete list;
  delete wrapper;
  delete tokenizer_list;
};