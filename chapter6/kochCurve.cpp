#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
typedef pair<double, double> dot;
double th = M_PI * 60.0 / 180.0;

void printDot(dot d) {
    cout << fixed << setprecision(8)
        << d.first
        << " "
        << d.second
        << endl;
}

void koch(int d, dot p1, dot p2) {
    if(d == 0) return;
    double xdist = p2.first - p1.first;
    double ydist = p2.second - p1.second;
    double dist = sqrt(xdist * xdist + ydist * ydist ) / 3;
    dot s = make_pair(xdist / 3, ydist / 3);
    dot t = make_pair(xdist * 2 / 3, ydist * 2 / 3);
    double ux = (t.first - s.first) * cos(th) - (t.second - s.second) * sin(th) + s.first;
    double uy = (t.first - s.first) * sin(th) + (t.second - s.second) * cos(th) + s.second;
    dot u = make_pair(ux, uy);

    koch(d-1, p1, s);
    printDot(s);
    koch(d-1, s, u);
    printDot(u);
    koch(d-1, u, t);
    printDot(t);
    koch(d-1, t, p2);
}

int main() {
    int n;
    cin >> n;
    dot p1 = make_pair(0, 0);
    dot p2 = make_pair(100, 0);
    printDot(p1);
    koch(n, p1, p2);
    printDot(p2);
    return 0;
}
