#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int h[2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h, h + n);
    cout << h[b] - h[b - 1] << endl; 
    return 0;
}