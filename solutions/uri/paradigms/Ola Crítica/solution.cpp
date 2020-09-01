#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(){}
};

bool cmp(const point & a, const point & b){
    return a.x < b.x;
}

int const N = 1005;
int dp[N];

int lis(vector<point> & v, int n, int y){
    
    int mmax = 1, a;
    for(int i = 0; i < n; i++)
        dp[i] = 1;
    for(int i = 1; i < n; i++){
        if(v[i].y - 1 == y)a = y - 1;
        else if(v[i].y + 1 == y)a = y + 1;
        else  continue;
        for(int j = 0; j < i; j++){
            if(v[i].x > v[j].x && v[j].y == a && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        mmax = max(mmax, dp[i]);
    }
    return mmax;
}

int main(){

    int n;
    while(cin >> n){
        vector<point> v(n);
        int ymin = 1000, ymax = -1000, ans = 1;
        for(point & p : v){
            cin >> p.x >> p.y;
            ymax = max(ymax, p.x);
            ymin = min(ymin, p.y);
        }
        sort(v.begin(), v.end(), cmp);
        for(int a = ymin + 1; a < ymax; a++)// suposse de rect a
            ans = max(ans, lis(v,n,a));

        cout << ans << endl;
    }
    return 0;
}