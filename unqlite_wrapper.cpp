#define TOK_SIZE 16

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "unqlite_wrapper.h"
#include "tokenizer.h"

using namespace std;

int main() {
  UnqliteWrapper<string> * table = new UnqliteWrapper<string>();
  char * result;
    int result_size;
  char tok[TOK_SIZE];
  Tokenizer * tokenizer = new Tokenizer();
  table->insert("a", "a");
  table->insert("a", "b");
  table->insert("a", "c");
  table->insert("a", "dd");
  table->insert("a", "ee");
  result_size = table->value_size("a");
  result = new char[result_size];
  table->find("a", result);
  cout<<"result size: "<<result_size<<endl;
  cout<<"a "<<result<<endl;
  tokenizer->set_buffer(result, result_size);
  while(tokenizer->token(tok)) {
    cout<<"token "<<tok<<endl;
    memset(tok, '\0', TOK_SIZE);
  }
  delete table;
  delete result;
  delete tokenizer;
};