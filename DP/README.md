# DP
library for DP
## bit DP
[bit.hpp](https://github.com/fumiphys/programming_contest/blob/master/DP/bit.hpp)  
部分集合に関する更新の高速化  
 verify: [AtCoder(Or Plus Max)](https://atcoder.jp/contests/arc100/tasks/arc100_c)  
 verify: [AOJ(Enumeration)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446)


| function | arguments | return | description |
|:--------:|:---------|:------|:-----------|
| fast\_zeta\<T\> | vector\<T\> &f | vector\<T\> | 高速ゼータ変換 (O(2<sup>n</sup> n), n: 全体集合のサイズ)<br>f(U) = \sum\_\{U\in T\}f(T). <br>For f(U) = \sum_\{T\in U\}f(T), use f\[j \| i\] += f\[j\]|
| fast\_moebius\<T\> | vector\<T\> &f | vector\<T\> | 高速メビウス変換 (O(2<sup>n</sup> n), n: 全体集合のサイズ)<br>f(U) = \sum_\{U\in T\}(-1)<sup>\|T\U\|</sup>f(T). <br>For f(U) = \sum_\{T\in U\}f(T), use f\[j \| i\] -= f\[j\] |