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
  point3d operator+(const point3d &r) const{
    return point3d(x + r.x, y + r.y, z + r.z);
  }
  point3d operator-(const point3d &r) const{
    return point3d(x - r.x, y - r.y, z - r.z);
  }
  point3d& operator+=(const point3d &r){
    *this = *this + r;
    return *this;
  }
  point3d& operator-=(const point3d &r){
    *this = *this - r;
    return *this;
  }
  bool operator==(const point3d &r) const{
    return abs(x - r.x) < EPS && abs(y - r.y) < EPS && abs(z - r.z) < EPS;
  }
  bool operator!=(const point3d &r) const{
    return !(*this == r);
  }
  bool operator<(const point3d &r) const{
    if(abs(x - r.x) >= EPS)return x < r.x;
    if(abs(y - r.y) >= EPS)return y < r.y;
    return z < r.z;
  }
};

point3d operator*(double x, const point3d &p){
  return point3d(x * p.x, x * p.y, x * p.z);
}

point3d operator/(const point3d &p, double x){
  return point3d(p.x / x, p.y / x, p.z / x);
}

double norm(const point3d &a){
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

double dis(const point3d &a, const point3d &b){
  point3d c = a - b;
  return norm(c);
}

double inner_product(const point3d &a, const point3d &b){
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

point3d outer_product(const point3d &a, const point3d &b){
  return point3d(a.y * b.z - a.z * b.y,
      a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double cosine(const point3d &a, const point3d &b){
  return inner_product(a, b) / norm(a) / norm(b);
}

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
  point3d re = outer_product(pb - pa, pc - pa);
  plane3d res;
  res.a = re.x, res.b = re.y, res.c = re.z;
  res.d = - (res.a * pa.x + res.b * pa.y + res.c * pa.z);
  res.build();
  return res;
}

point2d projection(const point2d &p, const point2d &p1, const point2d &p2){
  point2d p2p1 = p2 - p1, pp1 = p - p1;
  if(abs(inner_product(p2p1, pp1)) < EPS)return p1;
  double cosi = cosine(p2p1, pp1);
  return p1 + (dis(p, p1) * cosi / norm(p2 - p1)) * (p2 - p1);
}

point2d reflection(const point2d &p, const point2d &p1, const point2d &p2){
  point2d pr = projection(p, p1, p2);
  return p + 2. * (pr - p);
}

#endif
