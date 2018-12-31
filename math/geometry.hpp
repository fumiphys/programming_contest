/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double, double> Pd;

const double EPS = 1e-10;

bool crossing(P p1, P p2, P q1, P q2){
  double pq1 = (q1.first - p1.first) * (q2.second - p1.second)
    - (q1.second - p1.second) * (q2.first - p1.first);
  double pq2 = (q1.first - p2.first) * (q2.second - p2.second)
    - (q1.second - p2.second) * (q2.first - p2.first);
  double qp1 = (p1.first - q1.first) * (p2.second - q1.second)
    - (p1.second - q1.second) * (p2.first - q1.first);
  double qp2 = (p1.first - q2.first) * (p2.second - q2.second)
    - (p1.second - q2.second) * (p2.first - q2.first);
  return (pq1 * pq2 < EPS && qp1 * qp2 < EPS);
}

double cross(const Pd &o, const Pd &a, const Pd &b){
  return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}

vector<Pd> convex_hull(vector<Pd> vec){
  int n = vec.size(), k = 0;
  if(n <= 3)return vec;

  vector<Pd> ch(2 * n);
  sort(vec.begin(), vec.end());

  // lower
  for(int i = 0; i < n; i++){
    while(k >= 2 && cross(ch[k-2], ch[k-1], vec[i]) <= 0.)k--;
    ch[k++] = vec[i];
  }

  // upper
  for(int i = n - 1, t = k + 1; i > 0; --i){
    while(k >= t && cross(ch[k-2], ch[k-1], vec[i-1]) <= 0.)k--;
    ch[k++] = vec[i-1];
  }

  ch.resize(k - 1);
  return ch;

}
