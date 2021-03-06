/*
 * Library for converting char <> int
 */
#ifndef _CONVERT_H_
#define _CONVERT_H_
using namespace std;

// begin library convert here
// usage of this library: int d = dto_int(c);
int ato_int(char c){
  return int(c - 'a');
}

char to_achar(int i){
  return char(i + 'a');
}

int Ato_int(char c){
  if('a' <= c && c <= 'z')return int(c - 'a');
  return int(c - 'A') + 26;
}

char to_Achar(int i){
  if(i < 26)return char(i + 'a');
  return char(i - 26 + 'A');
}

int dto_int(char c){
  return int(c - '0');
}

char to_dchar(int i){
  return char(i + '0');
}
// end library

#endif // _CONVERT_H_
