#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    int a[n], tmp[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tmp[i] = a[i];
    }
    int res = d;
    if(n < d)res = n % d;
    for(int i = 0; i < n; i++){
        a[i] = tmp[(i + res) % n];
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}