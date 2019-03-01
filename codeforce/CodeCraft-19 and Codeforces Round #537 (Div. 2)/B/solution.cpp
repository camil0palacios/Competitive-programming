#include <bits/stdc++.h>
using namespace std;
int main(){

    long long n, k, m;
    while(cin >> n >> k >> m){
        deque<int> v(n);
        for(auto & i : v)cin >> i;
        sort(v.begin(), v.end());
        while(m && v.size() > 1){
            m--;
            v.pop_front();
        }
        vector<int> cnt(v.size(), 0);
        int aux = 0;
        while(m){
            for(int i = v.size() - 1; i >= 0; i--){
                if(m && cnt[i] < k){
                    v[i]++;
                    cnt[i]++;
                    m--;
                }
                if(cnt[i] == k){
                    aux++;
                }
                if(aux == v.size())m = 0;
            }
        }
        long double ans = 0;
        for(int i = 0; i < v.size(); i++)
            ans += (long double)v[i];
        cout << fixed << setprecision(15) << ans/v.size() << endl;
    }
    return 0;   
}