/*
 * Library for converting char <> int
 */
#ifndef _CONVERT_H_
#define _CONVERT_H_
using namespace std;

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

#endif
