#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool a[10];

long long solve(){
    long long n;
    cin >> n;
    if(n == 0)return -1;
    memset(a, 0, sizeof a);
    int cnt = 10, x = 1;
    while(true){
        int tmp = n * x;
        while(tmp){
            int aux = tmp % 10;
            if(!a[aux]){
                cnt--;
                a[aux] = 1;
            }
            tmp /= 10;
        }
        if(!cnt)break;
        x++;
    }
    return x*n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int ans = solve();
        cout << "Case #" << cs << ": ";
        if(ans == -1)cout << "INSOMNIA" << endl;
        else cout << ans << endl;
    }
    return 0;
}