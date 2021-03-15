#include <bits/stdc++.h>
#define endl '\n'
#define fori(i,a,b) for(int i = a; i < b; i++) 
#define ll long long
using namespace std;

const int MXN = 3e5 + 5;
int n, q;
int a[MXN];
ll s;

void add(int i) {
    if(i == 0|| i == n + 1) return;
    if(a[i] > a[i - 1] && a[i] > a[i + 1]) s += a[i];
    if(a[i] < a[i - 1] && a[i] < a[i + 1]) s -= a[i];
}

void erase(int i) {
    if(i == 0 || i == n + 1) return;
    if(a[i] > a[i - 1] && a[i] > a[i + 1]) s -= a[i];
    if(a[i] < a[i - 1] && a[i] < a[i + 1]) s += a[i];
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for(int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n + 1] = -1;
        s = 0;
        for(int i = 1; i <= n; i++) add(i);
        cout << s << endl;
        while(q--) {
            int l, r;
            cin >> l >> r;
            erase(l-1), erase(l), erase(l+1);
            if(l != r) {
                if(r - 1 != l + 1 && r - 1 != l) erase(r - 1);
                if(r != l + 1) erase(r);
                erase(r + 1);
            }
            swap(a[l], a[r]);
            add(l), add(l + 1), add(l - 1);
            if(l != r) {
                if(r - 1 != l + 1 && r - 1 != l) add(r - 1);
                if(r != l + 1) add(r);
                add(r + 1);
            }
            cout << s << endl;
        }
    }
    return 0; 
}