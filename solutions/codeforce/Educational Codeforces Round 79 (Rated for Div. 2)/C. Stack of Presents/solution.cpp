#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            a[x] = i;
        }
        int tmp = 0;
        long long ans = 0;
        for(int i = 1; i <= m; i++){
            int x; cin >> x;
            int aux = a[x];
            if(aux > tmp){
                tmp = aux;
                ans += 2*(tmp - i);
            }
        }
        cout << ans + m << endl;
    }
    return 0;
}