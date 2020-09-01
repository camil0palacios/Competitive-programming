#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
long long a[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; long long s;
        cin >> n >> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        } 
        long long sum = 0, pt = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i];
            if(a[pt] < a[i])pt = i;
            if(sum > s)break;
        }
        if(sum <= s)cout << 0;
        else cout << pt;
        cout << endl;
    }
    return 0;
}