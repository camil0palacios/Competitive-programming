#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int w;
    cin >> w;
    cout << (w % 2 == 0 && w != 2 ? "YES" : "NO") << endl;
    return 0;
}