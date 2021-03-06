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
  verify: [AOJ(Naive String Search)](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_A)
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
  verify: [Atcoder(ABCAC)](https://atcoder.jp/contests/arc055/tasks/arc055_c)


| function | arguments | return | description | complexity |
|:--------:|:---------:|:------:|:-----------|:----------:|
| zarray | const string &s | vector\<int\> z | $z[i] = s[i:]$と$s[0:]$の共通接頭辞の長さ | $O(n)$ |

## convert
[convert.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/convert.hpp)  
charとintを相互変換する  


| function | arguments | return | description | complexity |
|:--------:|:---------:|:------:|:-----------|:----------:|
| ato\_int | char | int | 小文字a-z $\rightarrow$ intへの変換 | $O(1)$ |
| to\_achar | int | char | int $\rightarrow$ 小文字a-zへの変換 | $O(1)$ |
| Ato\_int | char | int | A-Za-z $\rightarrow$ intへの変換(大文字は+26) | $O(1)$ |
| to\_Achar | int | char | int $\rightarrow$ A-Za-zへの変換(大文字は+26) | $O(1)$ |
| dto\_int | char | int | char0-9 $\rightarrow$ int0-9への変換(大文字は+26) | $O(1)$ |
| to\_dchar | int | char | int0-9 $\rightarrow$ char0-9への変換(大文字は+26) | $O(1)$ |

## Palindromic Tree
[palindromic\_tree.hpp](https://github.com/fumiphys/programming_contest/blob/master/character_strings/palindromic_tree.hpp)
回文に対するデータ構造
 - Palindromic Tree (i番目の文字が最後の最長回文など.)  
 verify: [yukicoder(Common Palindromes Extra)](https://yukicoder.me/problems/no/263)