#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


/*
const int INF = 1e9 + 7;
struct heap{
    int x, w;
    bool operator<(const heap & h)const{
        return x < h.x;
    }
};
heap h[1005];
int go(int idx, int nk){ // O(n^3)
    if(idx == n)return nk == 0 ? 0 : INF;
    if(dp[idx][nk] != -1)return dp[idx][nk];
    int ans = INF, W = 0, par = 0;
    if(nk - 1 >= 0){
        ans = min(ans, go(idx + 1, nk - 1));
        for(int i = 1; (i + idx) < n; i++){
            W += h[idx + i - 1].w[idx + i - 1];
            par += W * (h[idx + i].x - h[idx + i - 1].x);
            ans = min(ans, go(idx + i + 1, nk - 1) + par);
        }
    }
    return dp[idx][nk] = ans;   
} 
*/

int N, K, X[1001], W[1001];
long long dp[1001][1001], g[1001], f[1001];

struct line{
    int m;
    long long b;
    line(){}
    line(int m, long long b): m(m), b(b) {}
};

struct convexHull{
    line stk[2000]; 
    int ptr, sz;
    convexHull(): ptr(0), sz(0) {}
    bool check(line l1, line l2, line l3){
        // x1*m1 + b1 = x1*m2 + b2 => x1 = (b2 - b1) / (m1 - m2)
        // x2*m1 + b1 = x2*m3 + b3 => x2 = (b3 - b1) / (m1 - m3)
        // (b3 - b1) * (m1 - m2) < (b2 - b1) * (m1 - m3)
        return (l3.b - l1.b) * (l1.m - l2.m) < (l2.b - l1.b) * (l1.m - l3.m);
    }
    long long eval(int idx, int x){
        return (long long)x * stk[idx].m + stk[idx].b;
    }
    void update(line l){
        while(sz >= 2 && check(stk[sz - 2], stk[sz - 1], l)){
            sz--;
        }
        stk[sz++] = l;
    }
    long long query(int x){
        ptr = min(ptr, sz - 1);
        while(ptr + 1 < sz && eval(ptr + 1, x) < eval(ptr, x))ptr++;
        return eval(ptr, x);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> N >> K){
        for(int i = 0; i < N; i++){
            cin >> X[i] >> W[i];
        }
        f[0] = W[0];
        g[0] = (long long)X[0] * W[0];
        for(int i = 1; i < N; i++){
            f[i] = f[i - 1] + W[i];
            g[i] =  g[i - 1] + (long long)X[i] * W[i];
        }
        for(int i = 0; i < N; i++){
            dp[i][1] = X[i] * f[i] - g[i]; 
        }
        for(int k = 2; k <= K; k++){
            convexHull hull;
            for(int i = k - 1; i < N; i++){
                hull.update(line(-f[i - 1], dp[i - 1][k - 1] + g[i - 1]));
                dp[i][k] = X[i]*f[i] - g[i] + hull.query(X[i]);
            }    
        }
        cout << dp[N - 1][K] << endl;
    }
    return 0;
}