# math
library for math
## geometry
[geometry.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/geometry.hpp)  
幾何に関するライブラリ
  - crossing
  - convex hull (by graham, upper, lowerのwhile条件式の等号を外すと内角180度に対応できる)  
  verify: [AOJ(Convex Hull)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A)

## power
[power.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/power.hpp)  
繰り返し二乗法で累乗を求める.  
  - power by doubling  
  verify: [AOJ(Power)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B)

## prime
[prime.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/prime.hpp)  
素数に関するモジュール  
  - check is the number is a prime number
  - list all prime number lower than or equals to a number
  - list devisors
  - prime factorization  
  verify: [AOJ(Prime Factorize)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A)
  - millar rabin algorithm  
  verify: [yukicoder(tatyamと素数大富豪)](https://yukicoder.me/problems/no/774)

## algebra
[algebra.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/algebra.hpp)  
主に余りに関するモジュール  
  - greatest common devider  
  verify: [AOJ(Least Common Multiple)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C)
  - extgcd  
  verify: [Extended Euclid Algorithm](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E)
  - modinv  
  - Garner Algorithm
  - chinese reminder theorem  
  verify: [yukicoder(中華風 (Easy))](https://yukicoder.me/problems/no/186)
  - factorial, combination, permutation, h  
  verify: [yukicoder(組み合わせの数)](https://yukicoder.me/problems/no/117)

## convex hull trick
[convex\_hull\_trick.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/convex_hull_trick.hpp)  
複数の直線の中で最小の値を求める  
  - monotonious update of lines

## matrix
[matrix.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/matrix.hpp)  
ガウスの掃き出し法
  - gauss jordan
  - gauss jordan (mod p)
  - gauss jordan (bit)

# interpolation
[interpolation.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/interpolation.hpp)  
多項式補間
  - lagrange interpolation for double
  - lagrange interpolation for T (ex. modint)
  - lagrange interpolation for [0..N]  
  verify: [AtCoder(見たことのない多項式)](https://atcoder.jp/contests/arc033/tasks/arc033_4)

# ModInt
[modint.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/modint.hpp)  
剰余体での演算
  - modint

# Convolution
[convolution.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/convolution.hpp)  
FFT, Convolution
  - convolution
  - fft (dft, idft)
