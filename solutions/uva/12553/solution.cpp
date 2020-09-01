#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &i : v) cin >> i;
    bool once = 0;
    int i = 0, j = 0;
    vector<string> b = {"Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "Rujia",
    "Happy", "birthday", "to", "you"};
    while(true){
        cout << v[i] << ": " << b[j] << endl;
        if(i == n - 1)once = 1;  // every one singing at least once
        if(j == 15 && once)break;
        i++, j++;
        if(i >= n) i = 0;
        if(j > 15) j = 0;
    }

    return 0;
}