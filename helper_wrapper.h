template<typename Type, class List, class Tokenizer, class TokenizerHelper, class Wrapper>class HelperWrapper {
public:
  HelperWrapper(Tokenizer * tokenizer, TokenizerHelper * tokenizer_helper, Wrapper * wrapper):tokenizer(tokenizer), tokenizer_helper(tokenizer_helper), wrapper(wrapper) {}
  void insert(Type key, Type value) {insert(key, value, wrapper);}
  bool insert_unique(Type key, Type value) {return insert_unique(key, value, wrapper);}
  bool exists(Type key) {return exists(key, wrapper);}
  void find(Type key, List * & result) {find(key, result, tokenizer, tokenizer_helper, wrapper);}
  void remove(Type key) {remove(key, wrapper);}
  int value_size(Type key) {return value_size(key, wrapper);}
  unsigned int get_longest_chain() {return get_longest_chain(wrapper);}
private:
  Tokenizer * tokenizer;
  TokenizerHelper * tokenizer_helper;
  Wrapper * wrapper;
  void insert(Type key, Type value, Wrapper * & wrapper) {wrapper->insert(key, value);}
  bool insert_unique(Type key, Type value, Wrapper * & wrapper) {return wrapper->insert_unique(key, value);}
  bool exists(Type key, Wrapper * & wrapper) {return wrapper->exists(key);}
  void find(Type key, List * & result, Tokenizer * & tokenizer, TokenizerHelper * & tokenizer_helper, Wrapper * & wrapper) {
    // find values in store and them to list
    // todo use wrapper for tokens
    int buffer_size = wrapper->value_size(key);
    char * buffer = new char[buffer_size];
    wrapper->find(key, buffer);
    tokenizer->set_buffer(buffer);
    tokenizer_helper->tokens(key, result);
    delete buffer;
  }
  void remove(Type key, Wrapper * & wrapper) {wrapper->remove(key);}
  int value_size(Type key, Wrapper * & wrapper) {return wrapper->value_size(key);}
  unsigned int get_longest_chain(Wrapper * & wrapper) {return wrapper->get_longest_chain();}
};
