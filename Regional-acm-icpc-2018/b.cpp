#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        long long total = 0;
        unordered_set<long long> s;
        vector<long long> v(n);
        for(auto &i : v)cin >> i, total += i, s.insert(total);
        if(total % 2 == 0){
            total /= 2;
            int ans = 0;
            long long cur = 0;
            for(int i = 0; i < n && cur < total; i++){
                if(s.count(cur + total))ans++;
                cur += v[i];
            }
            if(ans < 2)cout << 'N' << endl;
            else cout << 'Y' << endl;
        }
        else cout << 'N' << endl;

    }
    return 0;
}