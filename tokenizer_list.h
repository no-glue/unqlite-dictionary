#define TOKEN_SIZE 128
template<typename Type, class Wrapper, class List, class Tokenizer>class TokenizerList {
public:
  TokenizerList(Wrapper * wrapper, Tokenizer * tokenizer):wrapper(wrapper), tokenizer(tokenizer) {}
  void tokens(Type key, List * & list) {
    tokens(wrapper, tokenizer, key, list);
  }
private:
  Wrapper * wrapper;
  Tokenizer * tokenizer;
  void tokens(Wrapper * & wrapper, Tokenizer * & tokenizer, Type key, List * & list) {
    // add tokens to list
    char __token[TOKEN_SIZE];
    while(tokenizer->token(__token)) {
      list->insert_right(key, __token);
      wrapper->clear(__token, TOKEN_SIZE);
    }
    list->insert_right(key, __token);
    wrapper->clear(__token, TOKEN_SIZE);
  }
};