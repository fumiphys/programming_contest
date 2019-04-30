/*
 * Library for Convolution
 */
#ifndef _CONVOLUTION_H_
#define _CONVOLUTION_H_

#include <complex>
#include <vector>
using namespace std;
using cd = complex<double>;

// f.size() should be the power of 2.
void fft(vector<cd> &f, bool inv=false){
  int n = f.size();
  if(n == 1)return;
  vector<cd> f0(n / 2), f1(n / 2);
  for(int i = 0; i < n / 2; i++){
    f0[i] = f[i * 2];
    f1[i] = f[i * 2 + 1];
  }
  fft(f0, inv);
  fft(f1, inv);
  double th = M_PI * 2 / n;
  if(inv)th = - th;
  cd u(cos(th), sin(th)), ui(1, 0);
  for(int i = 0; i < n; i++){
    f[i] = f0[i%(n/2)] + ui * f1[i%(n/2)];
    ui = ui * u;
  }
}

void dft(vector<cd> &f){
  fft(f);
}

void idft(vector<cd> &f){
  fft(f, true);
  for(int i = 0; i < f.size(); i++)f[i] = f[i] / cd(f.size());
}

template <typename T>
vector<T> convolution(vector<T> &f, vector<T> &g){
  int n = 1;
  while(n < 2 * f.size() + 1)n *= 2;
  vector<cd> F(n, 0), G(n, 0);
  for(int i = 0; i < f.size(); i++)F[i] = cd(f[i]);
  for(int i = 0; i < g.size(); i++)G[i] = cd(g[i]);

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

#endif
