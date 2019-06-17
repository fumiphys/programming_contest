/*
 * library for math function
 * author: fumiphys
 */
#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
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
  plane3d(const point3d pa, const point3d pb, const point3d pc){
    point3d re = outer_product(pb - pa, pc - pa);
    a = re.x, b = re.y, c = re.z;
    d = - (a * pa.x + b * pa.y + c * pa.z);
    build();
  }
  void build(){
    norm = sqrt(a * a + b * b + c * c);
  }
  double dis(point3d p){
    return abs(a * p.x + b * p.y + c * p.z + d) / norm;
  }
  double val(const point3d &p){
    return a * p.x + b * p.y + c * p.z + d;
  }
};

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

struct plane2d{
  double a, b, c;
  double norm;
  plane2d(){}
  plane2d(double a, double b, double c): a(a), b(b), c(c){}
  plane2d(const point2d &p, const point2d &q){
    point2d l = p - q;
    a = l.y, b = - l.x;
    c = - a * p.x - b * p.y;
    build();
  }
  void build(){
    norm = sqrt(a * a + b * b);
  }
  double dis(const point2d &p){
    return abs(a * p.x + b * p.y + c) / norm;
  }
  double val(const point2d &p){
    return a * p.x + b * p.y + c;
  }
};

bool parallel(const plane2d &p, const plane2d &q){
  return abs(p.a * q.b - p.b * q.a) < EPS;
}

bool orthogonal(const plane2d &p, const plane2d &q){
  return abs(p.a * q.a + p.b * q.b) < EPS;
}

bool intersection(const point2d &p1, const point2d &p2, const point2d &p3, const point2d &p4){
  plane2d pl1(p1, p2), pl2(p3, p4);
  if(abs(pl1.val(p3)) < EPS && min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) &&
      min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y))return true;
  if(abs(pl1.val(p4)) < EPS && min(p1.x, p2.x) <= p4.x && p4.x <= max(p1.x, p2.x) &&
      min(p1.y, p2.y) <= p4.y && p4.y <= max(p1.y, p2.y))return true;
  if(abs(pl2.val(p1)) < EPS && min(p3.x, p4.x) <= p1.x && p1.x <= max(p3.x, p4.x) &&
      min(p3.y, p4.y) <= p1.y && p1.y <= max(p3.y, p4.y))return true;
  if(abs(pl2.val(p2)) < EPS && min(p3.x, p4.x) <= p2.x && p2.x <= max(p3.x, p4.x) &&
      min(p3.y, p4.y) <= p2.y && p2.y <= max(p3.y, p4.y))return true;
  return pl1.val(p3) * pl1.val(p4) <= - EPS && pl2.val(p1) * pl2.val(p2) <= - EPS;
}

double closest_pair(vector<point2d> &a, int l, int r){
  double d = numeric_limits<double>::max();
  if(r - l == 1)return d;

  int m = (l + r) / 2;
  double x = a[m].x;
  d = min(closest_pair(a, l, m), closest_pair(a, m, r));
  inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r, [](const point2d &u, const point2d &v){
      return u.y < v.y;
      });

  vector<point2d> v;
  for(int i = l; i < r; i++){
    if(abs(x - a[i].x) >= d)continue;
    for(int j = 0; j < v.size(); j++){
      double dx = a[i].x - v[v.size()-j-1].x;
      double dy = a[i].y - v[v.size()-j-1].y;
      if(dy >= d)break;
      d = min(d, sqrt(dx * dx + dy * dy));
    }
    v.push_back(a[i]);
  }
  return d;
}

double closest_pair(vector<point2d> &a){
  sort(a.begin(), a.end(), [](const point2d &u, const point2d &v){
      if(u.x != v.x)return u.x < v.x;
      return u.y < v.y;
      });
  return closest_pair(a, 0, int(a.size()));
}

// begin library circle here
// usage of this library: circle c(point2d(x, y), r);
// usage of this library: circle_crossing_state(c1, c2);
struct circle{
  point2d c;
  double r;
  circle(){}
  circle(point2d c, double r): c(c), r(r){}
};

enum circle_crossing_state{
  NOTCROSS = 4,
  CIRCUMSCRIBE = 3,
  INTERSECT = 2,
  INSCRIBED = 1,
  INCLUDED = 0,
};

circle_crossing_state circle_crossing(const circle &a, const circle &b){
  double d = dis(a.c, b.c);
  cout << setprecision(20);
  if(d > a.r + b.r + EPS)return NOTCROSS;
  if(abs(d - (a.r + b.r)) < EPS)return CIRCUMSCRIBE;
  if(abs(d - abs(a.r - b.r)) < EPS)return INSCRIBED;
  if(d + EPS < abs(a.r - b.r))return INCLUDED;
  return INTERSECT;
}
// end library

#endif
