#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    int distress = 0;
    for(int i = 0; i < n; i++) {
        char c; int d;
        cin >> c >> d;
        if(c == '-' && x < d){
            distress++;
            continue;
        }
        x += (c == '+' ? d : -d);
    }
    cout << x <<  ' ' << distress << endl;
    return 0;
}