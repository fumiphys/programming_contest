# DP
library for DP
## bit DP
[bit.hpp](https://github.com/fumiphys/programming_contest/blob/master/DP/bit.hpp)  
部分集合に関する更新の高速化  
 verify: [AtCoder(Or Plus Max)](https://atcoder.jp/contests/arc100/tasks/arc100_c)  
 verify: [AOJ(Enumeration)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446)


| function | arguments | return | description | complexity |
|:--------:|:---------|:------|:-----------|:-------------:|
| fast\_zeta\<T\> | vector\<T\> &f | vector\<T\> | 高速ゼータ変換<br> $\displaystyle f(U) = \sum_{U\in T}f(T)$. <br>For $\displaystyle f(U) = \sum_{T\in U}f(T)$, use $f[j \vert i] += f[j]$| $O(2^n n)$ , $n$: 全体集合のサイズ|
| fast\_moebius\<T\> | vector\<T\> &f | vector\<T\> | 高速メビウス変換<br> $\displaystyle f(U) = \sum_{U\in T}(-1)^{\|T\setminus U\|}f(T)$. <br>For $\displaystyle f(U) = \sum_{T\in U}(-1)^{\|U\setminus T\|}f(T)$, use $f[j \vert i] -= f[j]$ | $O(2^n n)$, $n$: 全体集合のサイズ |