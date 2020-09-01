#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool sv[105];
int prime[105], idx = 0;
int ans[105];

/*
void fill(){
    memset(sv, -1, sizeof sv);
    sv[1] = sv[0] = 0;
    prime[idx++] = 2;
    int i;
    for(i = 3; i*i < 105; i += 2){
        if(sv[i]){
            prime[idx++] = i;
            for(int j = i * i; j < 105; j += i * 2){
                sv[j] = 0;
            }
        }
    }
    for(; i < 105; i += 2){
        if(sv[i])prime[idx++] = i;
    }
}
*/

void solve(){
    int n;
    cin >> n;
    memset(ans, 0, sizeof ans);
    for(int i = 2; i <= n; i++){
        int tmp = i;
        for(int j = 2; j * j <= tmp; j++){
            if(tmp % j == 0){
                int cnt = 0;
                while(tmp % j == 0){
                    cnt++, tmp /= j;
                }
                ans[j] += cnt;
            }
        }
        if(tmp > 1)ans[tmp]++;
    }
    bool flag = 0;
    cout << n << " = ";
    for(int i = 0; i < 105; i++){
        if(ans[i]){
            if(flag)cout << " * ";
            cout << i << " (" << ans[i] << ")";
            flag = 1;
        }
    }
    cout << endl;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}