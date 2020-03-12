#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x;
    cin >> x;
    cout << (x / 5) + (x % 5 != 0) << endl;
    return 0;
}