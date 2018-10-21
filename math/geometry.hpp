/*
 * library for math function
 * author: fumiphys
 */

#include <iostream>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

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
