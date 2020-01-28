/*
 * Library for Convolution
 */
#ifndef _CONVOLUTION_H_
#define _CONVOLUTION_H_

#include <complex>
#include <vector>
#include "power.hpp"
#include "algebra.hpp"
using namespace std;

// begin library fft here
// usage of this library: fft(f);
template <typename T>
struct custom_complex{
  T x = 0, y = 0;
  custom_complex(){}
  custom_complex(T x, T y): x(x), y(y){}
  custom_complex operator+(const custom_complex &r) const{
    return custom_complex(x + r.x, y + r.y);
  }
  custom_complex operator-(const custom_complex &r) const{
    return custom_complex(x - r.x, y - r.y);
  }
  custom_complex operator*(const custom_complex &r) const{
    return custom_complex(x * r.x - y * r.y, x * r.y + y * r.x);
  }
  custom_complex conjugate() const{
    return custom_complex(x, - y);
  }
  custom_complex operator/(const custom_complex &r ) const{
    T norm = r.x * r.x + r.y * r.y;
    custom_complex cc = (*this) * r.conjugate();
    cc.x /= norm;
    cc.y /= norm;
    return cc;
  }
  custom_complex& operator*=(const custom_complex &r){
    T xp = x, yp = y;
    x = xp * r.x - yp * r.y;
    y = xp * r.y + yp * r.x;
    return *this;
  }
  T real() const{
    return x;
  }
  T imag() const{
    return y;
  }
};

template <typename T>
custom_complex<T> pol(T r, T theta){
  return custom_complex<T>(r * cosl(theta), r * sinl(theta));
}

using cd = custom_complex<double>;
// f.size() should be the power of 2.
void rec_fft(vector<cd> &f, bool inv=false){
  int n = f.size();
  if(n == 1)return;
  vector<cd> f0(n / 2), f1(n / 2);
  for(int i = 0; i < n / 2; i++){
    f0[i] = f[i * 2];
    f1[i] = f[i * 2 + 1];
  }
  rec_fft(f0, inv);
  rec_fft(f1, inv);
  double th = M_PI * 2 / n;
  if(inv)th = - th;
  cd u(cos(th), sin(th)), ui(1., 0);
  for(int i = 0; i < n; i++){
    f[i] = f0[i%(n/2)] + ui * f1[i%(n/2)];
    ui = ui * u;
  }
}

// f.size() should be the power of 2.
void fft(vector<cd> &f, bool inv=false){
  int n = f.size(), mask = n - 1;
  vector<cd> tmp(n);
  for(int i = n >> 1; i >= 1; i >>= 1){
    cd zeta = pol<double>(1., 2. * M_PI * i * (inv ? -1.: 1.) / n);
    cd w = cd(1., 0);
    for(int j = 0; j < n; j += i){
      for(int k = 0; k < i; k++){
        tmp[j + k] = f[((j<<1)&mask) + k] + w * f[(((j<<1)+i)&mask)+k];
      }
      w *= zeta;
    }
    swap(f, tmp);
  }
}

void dft(vector<cd> &f){
  fft(f);
}

void idft(vector<cd> &f){
  fft(f, true);
  for(size_t i = 0; i < f.size(); i++)f[i] = f[i] / cd(f.size(), 0.);
}

template <typename T>
vector<T> convolution(const vector<T> &f, const vector<T> &g){
  int n = 1;
  while(n < 2 * f.size() + 1)n *= 2;
  vector<cd> F(n, cd(0., 0.)), G(n, cd(0., 0.));
  for(int i = 0; i < f.size(); i++)F[i] = cd(f[i], 0.);
  for(int i = 0; i < g.size(); i++)G[i] = cd(g[i], 0.);

  dft(F);
  dft(G);
  vector<cd> H(n);
  for(int i = 0; i < n; i++)H[i] = F[i] * G[i];
  idft(H);
  vector<T> h(n);
  for(int i = 0; i < n; i++){
    h[i] = T(round(H[i].real()));
  }
  return h;
}
// end library

// begin library ntt here
// usage of this library: NTT1 ntt;
// usage of this library: h = ntt.convolution(f, g);
// depends: power
// depends: garner
template <int MOD, int g>
struct NTT{
  int get_mod(){
    return MOD;
  }
  void _ntt(vector<long long> &f, bool inv=false){
    int n = f.size(), mask = n - 1;
    int h = power<long long>(g, (MOD - 1) / n, MOD);
    if(inv)h = modinv(h, MOD);
    vector<long long> tmp(n);
    for(int i = n >> 1; i >= 1; i >>= 1){
      long long zeta = power<long long>(h, i, MOD);
      long long w = 1;
      for(int j = 0; j < n; j += i){
        for(int k = 0; k < i; k++){
          tmp[j+k] = (f[((j<<1)&mask)+k] + w * f[(((j<<1)+i)&mask)+k] % MOD) % MOD;
        }
        w = w * zeta % MOD;
      }
      swap(f, tmp);
    }
  }
  void ntt(vector<long long> &f){
    _ntt(f, false);
  }
  void intt(vector<long long> &f){
    _ntt(f, true);
    int n = f.size();
    int ni = modinv(n, MOD);
    for(int i = 0; i < n; i++)f[i] = f[i] * ni % MOD;
  }
  vector<long long> convolution(vector<long long> f, vector<long long> h){
    int n = 1;
    while(n < int(f.size() + h.size()))n *= 2;
    f.resize(n, 0); h.resize(n, 0);
    ntt(f);
    ntt(h);
    for(int i = 0; i < n; i++)f[i] = f[i] * h[i] % MOD;
    intt(f);
    return f;
  }
};

using NTT1 = NTT<167772161, 3>;
using NTT2 = NTT<469762049, 3>;
using NTT3 = NTT<1224736769, 3>;

vector<long long> arbitrary_mod_convolution(vector<long long> f, vector<long long> g, long long MOD){
  for(size_t i = 0; i < f.size(); i++)f[i] %= MOD;
  for(size_t i = 0; i < g.size(); i++)g[i] %= MOD;
  NTT1 ntt1;
  NTT2 ntt2;
  NTT3 ntt3;
  auto x1 = ntt1.convolution(f, g);
  auto x2 = ntt2.convolution(f, g);
  auto x3 = ntt3.convolution(f, g);

  vector<long long> res(x1.size());
  vector<long long> b(3), m(3);
  m[0] = ntt1.get_mod();
  m[1] = ntt2.get_mod();
  m[2] = ntt3.get_mod();
  for(size_t i = 0; i < x1.size(); i++){
    b[0] = x1[i];
    b[1] = x2[i];
    b[2] = x3[i];
    res[i] = garner<long long>(b, m, MOD);
  }
  return res;
}
// end library

#endif
