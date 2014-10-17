class Tokenizer {
public:
  Tokenizer(): position(0), buffer_size(0), buffer(NULL) {}
  Tokenizer(char * buffer, int buffer_size):position(0), buffer_size(buffer_size), buffer(buffer) {}
  void set_buffer(char * _buffer, int _buffer_size, int _position = 0) {
    buffer = _buffer;
    buffer_size = _buffer_size;
    position = _position;
  }
  void unset_buffer() {
    buffer = NULL;
    buffer_size = 0;
    position = 0;
  }
  void rewind() {position = 0;}
  bool token(char * tok, int tok_position = 0) {return token(position, buffer, buffer_size, tok, tok_position);}
private:
  int position;
  int buffer_size;
  char * buffer;
  bool token(int & position, char * buffer, int buffer_size, char * tok, int tok_position) {
    // get the token
    while(position < buffer_size && buffer[position] != '|') tok[tok_position++] = buffer[position++];
    tok[tok_position] = '\0';
    position++;
    return (position < buffer_size) ? true : false;
  }
};