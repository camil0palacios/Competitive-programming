#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const double INF = 0x3f3f3f3f3f3f;
const double eps = 1e-8;
const int MXN = 60;
int n;
double dp[MXN][MXN];

struct pt {
    double x, y;    
};

pt a[MXN];

bool zero(double x) {
    x = x < 0 ? -x : x;
    return x < eps;
}

// u = (x[i] - x[k], y[i] - y[k])
// v = (x[j] - x[k], y[j] - y[k])

double mult(pt p1, pt p2, pt p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y); 
}

double area(pt a, pt b, pt c) {
    double x = mult(b, c, a) * 0.5;
    return x < 0 ? -x : x;
}

bool check(int a1, int a2, int a3) {
    for(int i = 0; i < n; i++) {
        if(i == a1 || i == a2 || i == a3) continue;
        double x = area(a[a1], a[a2], a[i]) + area(a[a1], a[a3], a[i]) + area(a[a2], a[a3], a[i]) - area(a[a1], a[a2], a[a3]); 
        if(zero(x)) return 0;
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int cs = 0; cs < t; cs++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lf %lf", &a[i].x, &a[i].y);
        }
        for(int i = n; i >= 1; i--) {
            dp[i][i + 1] = 0.0;
            for(int j = i + 2; j <= n; j++) { 
                dp[i][j] = INF;
                for(int k = i + 1; k < j; k++) {
                    if(check(i, k, j))
                        dp[i][j] = min(dp[i][j], max(area(a[i], a[j], a[k]), max(dp[i][k], dp[k][j])));
                }
            }
        }
        printf("%.1lf\n", dp[1][n]);
    }
    return 0;
}