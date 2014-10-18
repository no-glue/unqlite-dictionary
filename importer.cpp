#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "unqlite_wrapper.h"
#include "tokenizer.h"
#include "cstring_wrapper.h"
#include "double_node.h"
#include "double_list.h"
#include "double_list_walk.h"
#include "tokenizer_list.h"
#include "helper_wrapper.h"
#include "decorator_file_read.h"
#include "generator_file.h"
#include "importer.h"
#include "adapter_metrics_table.h"
#include "metrics_table.h"

using namespace std;

int main() {
  string line;
  getline(cin, line);
  DoubleList<DoubleNode<string>, string> * results = new DoubleList<DoubleNode<string>, string>();
  Tokenizer * tokenizer = new Tokenizer(), * tokenizer_visited = new Tokenizer();
  // tokenizer
  CstringWrapper * str = new CstringWrapper(), * str_visited = new CstringWrapper(), * str_adapter = new CstringWrapper();
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
  GeneratorFile<
    ifstream, string
  > * files = new GeneratorFile<
    ifstream, string
  >(line);
  // get file generator
  DecoratorFileRead<
    ostream, string
  > * file_read = new DecoratorFileRead<
    ostream, string
  >(cout);
  // get file read messages
  Importer<
    GeneratorFile<ifstream, string>, 
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
    >, 
    DecoratorFileRead<ostream, string>, 
    string, 
    ifstream> * importer = new Importer<
      GeneratorFile<ifstream, string>, 
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
      >, 
      DecoratorFileRead<ostream, string>, 
      string, 
      ifstream>();
  // get file reader
  AdapterMetricsTable<
    string,
    // keys and values simple type
    CstringWrapper,
    // wrapper to use for strings
    DoubleNode<string>,
    // node
    DoubleList<DoubleNode<string>, string>,
    // list
    DoubleListWalk<
      DoubleNode<string>,
      DoubleList<DoubleNode<string>, string>
    >,
    // walk list
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
    >
    // table 
  > * adapter = new AdapterMetricsTable<
    string,
    // keys and values simple type
    CstringWrapper,
    // wrapper to use for strings
    DoubleNode<string>,
    // node
    DoubleList<DoubleNode<string>, string>,
    // list
    DoubleListWalk<
      DoubleNode<string>,
      DoubleList<DoubleNode<string>, string>
    >,
    // walk list
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
    >
    // table
  >(str_adapter, table, table_visited, results);
  // get table adapter
  // todo put walk in front
  MetricsTable<
    // start template list
    AdapterMetricsTable<
      string,
      // keys and values simple type
      CstringWrapper,
      // wrapper to use for strings
      DoubleNode<string>,
      // node
      DoubleList<DoubleNode<string>, string>,
      // list
      DoubleListWalk<
        DoubleNode<string>,
        DoubleList<DoubleNode<string>, string>
      >,
      // walk list
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
      >
      // table 
    >
    // adapter for index (table here)
  > * metrics = new MetricsTable<
    // start template list
    AdapterMetricsTable<
      string,
      // keys and values simple type
      CstringWrapper,
      // wrapper to use for strings
      DoubleNode<string>,
      // node
      DoubleList<DoubleNode<string>, string>,
      // list
      DoubleListWalk<
        DoubleNode<string>,
        DoubleList<DoubleNode<string>, string>
      >,
      // walk list
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
      >
      // table 
    >
    // adapter for index (table here)
  >(adapter);
  // get metrics
  delete results;
  delete tokenizer;
  delete tokenizer_visited;
  delete str;
  delete str_visited;
  delete str_adapter;
  delete tokenizer_list;
  delete tokenizer_list_visited;
  delete table_base;
  delete table_base_visited;
  delete table;
  delete table_visited;
  delete files;
  delete file_read;
  delete importer;
  delete adapter;
  delete metrics;
  return 0;
}