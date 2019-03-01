#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(){}
};

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int ans = 0;
        vector<point> v(n);
        for(auto & i : v)cin >> i.x >> i.y;
        for(int i = 0; i < n; i++){
            bool u = 0, d = 0, l = 0, r = 0;
            for(int j = 0; j < n; j++){
                if(v[i].x == v[j].x && v[i].y < v[j].y)u = 1;
                if(v[i].x == v[j].x && v[i].y > v[j].y)d = 1;
                if(v[i].y == v[j].y && v[i].x < v[j].x)r = 1;
                if(v[i].y == v[j].y && v[i].x > v[j].x)l = 1;
            }
            if(l && r && u && d)ans++;
        }
        cout << ans << endl;
    }
    return 0;
}