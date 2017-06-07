#ifndef _STRING_STREAM_H_INCLUDED_
#define _STRING_STREAM_H_INCLUDED_

#include <Arduino.h>
#include <WString.h>
#include <Stream.h>

class StringStream : public Stream {
private:
  String &string;
  unsigned int position;
public:
  StringStream(String &s) : string(s), position(0) { }
  int available() { return string.length() - position; }
  int read() { return position < string.length() ? string[position++] : -1; }
  int peek() { return position < string.length() ? string[position] : -1; }
  void reset() { position = 0; }
  int parseInt() { return string.toInt(); }
  float parseFloat() { return string.toFloat(); }
  void trim() { string.trim(); }
  void flush() { }
  void setTimeout(int) { }
  const char* c_str() { return string.c_str(); }
  String readString() { return string; }
  String readStringUntil(char);
  size_t write(uint8_t c) { string += (char)c; return 1; }
};

#endif // _STRING_STREAM_H_INCLUDED_
