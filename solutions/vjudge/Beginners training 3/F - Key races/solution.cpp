#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v1, v2, t1, t2, s;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int x = v1 * s + 2 * t1;
    int y = v2 * s + 2 * t2;
    if(x < y) cout << "First" << endl;
    else if(y < x) cout << "Second" << endl;
    else cout << "Friendship" << endl;
    return 0;
}