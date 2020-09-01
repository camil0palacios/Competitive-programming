#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];
int col[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int tcol = 1, lst = a[0];
        col[0] = 1;
        int k = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] != lst){
                k = 2;
                tcol = (tcol == 1 ? 2 : 1);
            }
            col[i] = tcol;
            lst = a[i];
        }
        if(col[n - 1] == col[0] && a[n - 1] != a[0]) {
            k = 3;
            for(int i = 0; a[i] == a[0]; i++){
                col[i] = 3;
            }
        }
        cout << k << endl;
        for(int i = 0; i < n; i++) {
            cout << col[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}