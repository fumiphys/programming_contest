# character\_strings
library for strings

## Burrows Wheeler Transformation
[burrows\_wheeler.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/burrows_wheeler.hpp)  
各文字を接尾辞でsort
  - bwt\_sa (construct from suffix array)
  - inverse\_bwt (restore string)
  - construct directly (TODO)

## Rolling Hash
[rolling\_hash.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/rolling_hash.hpp)  
ハッシュを用いた文字列検索アルゴリズム
  - RollingHash  
  verify: [AOJ(String Search)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B)

## Utils for String
[string\_utils.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/string_utils.hpp)  
固定長のランダムな文字列を生成する
  - generate\_random\_string

## Suffix Array
[suffix\_array.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/suffix_array.hpp)  
接尾辞配列の構築
  - Manber Myers
  - SA-IS (TODO)

## Text Search
[text\_search.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/text_search.hpp)  
文字列検索
  - find\_text (brute force)  
  verify: [AOJ(Naive String Search)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_A)
  - kmp\_search (KMP)  
  verify: [AOJ(Naive String Search)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_A)
  - bm\_search (BM)  
  verify: [AOJ(Naive String Search)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_A)
  - sa\_search (suffix array)
  - rh\_search (rolling hash)  
  verify: [AOJ(String Search)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B)
  - z\_search (Z algorithm)  
  verify: [AOJ(String Search)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B)

## Trie
[trie.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/trie.hpp)  
文字列を格納しておくための木
  - trie

## Z-Algorithm
[z.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/z.hpp)  
文字列sとs[i:]の共通接頭辞の長さを線形時間で求める.
  - zarray (calculate Z array)
