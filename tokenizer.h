class Tokenizer {
public:
  Tokenizer(): position(0), buffer(NULL) {}
  Tokenizer(char * buffer):position(0), buffer(buffer) {}
  void set_buffer(char * _buffer, int _position = 0) {
    buffer = _buffer;
    position = _position;
  }
  void unset_buffer() {
    buffer = NULL;
    position = 0;
  }
  void rewind() {position = 0;}
  bool token(char * tok, int tok_position = 0) {return token(position, buffer, tok, tok_position);}
  bool token_any(char * tok, char bound, int tok_position = 0) {return token_any(position, buffer, tok, bound, tok_position);}
private:
  int position;
  char * buffer;
  bool token(int & position, char * buffer, char * tok, int tok_position) {
    // get the token
    if(buffer[position] == '\0') return false;
    while(buffer[position] != '\0' && buffer[position] != '|') tok[tok_position++] = buffer[position++];
    tok[tok_position] = '\0';
    if(buffer[position] != '\0') position++;
    return true;
  }
  bool token_any(int & position, char * buffer, char * tok, char bound, int tok_position) {
    // get the token
    if(buffer[position] == '\0') return false;
    while(buffer[position] != '\0' && buffer[position] != bound) tok[tok_position++] = buffer[position++];
    tok[tok_position] = '\0';
    if(buffer[position] != '\0') position++;
    return true;
  }
};
