#include <bits/stdc++.h>
using namespace std;

int main(){ 
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    while(cin >> n >> k){
        vector<long long> v(n);
        for(auto & i : v)cin >> i;
        string s; cin >> s;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(s[i] == s[j]){
                j++;
            }
            sort(v.begin()+i, v.begin()+j, greater<long long> ());
            long long mmax = 0;
            for(int x = 0; x < k && (i+x) < j; x++){
                mmax += v[i+x];
            }
            ans += mmax;
            i = j - 1;
        }
        cout << ans << endl;
    }
    return 0;
}