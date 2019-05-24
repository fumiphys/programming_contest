/*
 * library for math function
 * author: fumiphys
 */
#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double, double> Pd;

const double EPS = 1e-10;

struct point2d{
  double x, y;
  point2d(){}
  point2d(double x, double y): x(x), y(y){}
  point2d operator+(const point2d &r) const{
    return point2d(x + r.x, y + r.y);
  }
  point2d operator-(const point2d &r) const{
    return point2d(x - r.x, y - r.y);
  }
  point2d& operator+=(const point2d &r){
    *this = *this + r;
    return *this;
  }
  point2d& operator-=(const point2d &r){
    *this = *this - r;
    return *this;
  }
  bool operator==(const point2d &r) const{
    return abs(x - r.x) < EPS && abs(y - r.y) < EPS;
  }
  bool operator!=(const point2d &r) const{
    return !(*this == r);
  }
  bool operator<(const point2d &r) const{
    if(abs(x - r.x) >= EPS)return x < r.x;
    return y < r.y;
  }
};

point2d operator*(double x, const point2d &p){
  return point2d(x * p.x, x * p.y);
}

point2d operator/(const point2d &p, double x){
  return point2d(p.x / x, p.y / x);
}

double norm(const point2d &a){
  return sqrt(a.x * a.x + a.y * a.y);
}

double dis(const point2d &a, const point2d &b){
  point2d c = a - b;
  return norm(c);
}

double inner_product(const point2d &a, const point2d &b){
  return a.x * b.x + a.y * b.y;
}

double outer_product(const point2d &a, const point2d &b){
  return a.x * b.y - a.y * b.x;
}

double cosine(const point2d &a, const point2d &b){
  return inner_product(a, b) / norm(a) / norm(b);
}

double cross(const point2d &o, const point2d &a, const point2d &b){
  return outer_product(a - o, b - o);
}

vector<point2d> convex_hull(vector<point2d> vec){
  int n = vec.size(), k = 0;
  if(n < 3)return vec;

  vector<point2d> ch(2 * n);
  sort(vec.begin(), vec.end());

  // lower
  for(int i = 0; i < n; i++){
    while(k >= 2 && cross(ch[k-2], ch[k-1], vec[i]) <= 0.)k--;
    ch[k++] = vec[i];
  }

  // upper
  for(int i = n - 1, t = k + 1; i > 0; i--){
    while(k >= t && cross(ch[k-2], ch[k-1], vec[i-1]) <= 0.)k--;
    ch[k++] = vec[i-1];
  }

  ch.resize(k-1);
  return ch;
}

struct point3d{
  double x, y, z;
  point3d(){}
  point3d(double x, double y, double z): x(x), y(y), z(z){}
};

struct plane3d{
  double a, b, c, d;
  double norm = 1.;
  plane3d(){}
  plane3d(double a, double b, double c, double d): a(a), b(b), c(c), d(d){
    build();
  }
  void build(){
    norm = sqrt(a * a + b * b + c * c);
  }
  double dis(point3d p){
    return abs(a * p.x + b * p.y + c * p.z + d) / norm;
  }
};

plane3d get_eq(point3d pa, point3d pb, point3d pc){
  plane3d res;
  res.a = (pb.y - pa.y) * (pc.z - pa.z) - (pc.y - pa.y) * (pb.z - pa.z);
  res.b = (pb.z - pa.z) * (pc.x - pa.x) - (pc.z - pa.z) * (pb.x - pa.x);
  res.c = (pb.x - pa.x) * (pc.y - pa.y) - (pc.x - pa.x) * (pb.y - pa.y);
  res.d = - (res.a * pa.x + res.b * pa.y + res.c * pa.z);
  res.build();
  return res;
}

#endif
