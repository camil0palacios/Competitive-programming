#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    while(cin >> n){
        vector<pair<int,int>> v(n, pair<int,int>(0,0));
        for(int i = 0; i < (n*2); i++){
            int tmp;
            cin >> tmp;
            if(v[tmp-1].first == 0)v[tmp-1].first = i;
            else v[tmp-1].second = i;
        }
        long long ans = v[0].first + v[0].second;
        for(int i = 0; i < n - 1; i++){
            int a = abs(v[i].first - v[i+1].first) + abs(v[i].second - v[i+1].second);
            int b = abs(v[i].first - v[i+1].second) + abs(v[i].second - v[i+1].first);
            ans += min(a,b);
        }
        cout << ans << endl;
    }
    return 0;   
}