# math
library for math
## geometry
[geometry.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/geometry.hpp)  
幾何に関するライブラリ
  - point2d: 2次元座標, ベクトル  
  - point3d: 3次元座標, ベクトル  
  - convex hull (by graham, upper, lowerのwhile条件式の等号を外すと内角180度に対応できる)  
  verify: [AOJ(Convex Hull)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A)  
  - plane equation  
  verify: [yukicoder(点と平面との距離)](https://yukicoder.me/problems/no/132)  
  - projection  
  verify: [AOJ(Projection)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A)  
  - reflection  
  verify: [AOJ(Reflection)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B)  
  - parallel, orthogonal  
  verify: [AOJ(Parallel/Orthogonal)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A)  
  - intersection  
  verify: [AOJ(Intersection)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B)  
  - closest pair  
  verify: [AOJ(Closest Pair)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A)  
  verify: [AtCoder(Big Bang)](https://atcoder.jp/contests/abc022/tasks/abc022_d)  
  - circle intersection  
  verify: [AOJ(Intersection)](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A)
  - square test  
  veriry: [yukicoder(正方形を描くだけの簡単なお仕事です。)](https://yukicoder.me/problems/no/55)

## power
[power.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/power.hpp)  
繰り返し二乗法で累乗を求める.  
  - power by doubling  
  verify: [AOJ(Power)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B)

## prime
[prime.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/prime.hpp)  
素数に関するモジュール  
  - check if the number is a prime number
  - list all prime number lower than or equals to a number
  - list all prime number in [a, b) (b - a should be small enough)
  - list devisors
  - prime factorization  
  verify: [AOJ(Prime Factorize)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A)
  - millar rabin algorithm  
  verify: [yukicoder(tatyamと素数大富豪)](https://yukicoder.me/problems/no/774)
  - euler's phi function  
  verify: [AOJ(Euler's Phi Function)](https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D)

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
ガウスの掃き出し法など
  - gauss jordan
  - gauss jordan (mod p)
  - gauss jordan (bit)  
  - matrix power

## interpolation
[interpolation.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/interpolation.hpp)  
多項式補間
  - lagrange interpolation for double
  - lagrange interpolation for T (ex. modint)
  - lagrange interpolation for [0..N]  
  verify: [AtCoder(見たことのない多項式)](https://atcoder.jp/contests/arc033/tasks/arc033_4)

## ModInt
[modint.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/modint.hpp)  
剰余体での演算
  - modint

## Convolution
[convolution.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/convolution.hpp)  
FFT, Convolution
  - convolution  
  verify: [AtCoder(高速フーリエ変換)](https://atcoder.jp/contests/atc001/tasks/fft_c)
  - fft (dft, idft)  
  verify: [AtCoder(高速フーリエ変換)](https://atcoder.jp/contests/atc001/tasks/fft_c)  
  - NTT, arbitrary mod convolution  
  verify: [AtCoder(高速フーリエ変換)](https://atcoder.jp/contests/atc001/tasks/fft_c)  


## Rational
[rational.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/rational.hpp)  
有理数ライブラリ
  - stern brocot tree  
  verify: [yukicoder(貯金箱の消失)](https://yukicoder.me/problems/no/152)

## set by bit
[set\_by\_bit.hpp](https://github.com/fumiphys/programming_contest/blob/master/math/set_by_bit.hpp)  
bitを用いた集合演算
  - next_combination  
