#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++){
        long long n;
        string s;
        cin >> n >> s;
        long long limit = n/2 + (n&1), ans = 0;
        for(long long j = 0; j < limit; j++){
            ans += s[j] - '0';
        }
        long long mmax = ans;
        for(long long j = 0; j + limit < n; j++){
            ans -= s[j] - '0';
            ans += s[j + limit] - '0';
            mmax = max(mmax, ans);
        }
        cout << "Case #" << i + 1 << ": " << mmax << endl;
        
    }
    return 0;
}