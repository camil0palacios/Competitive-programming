#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, mmax = 0;
    cin >> n;
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        int stop;
        cin >> stop;
        unordered_set<int> s1;
        for(int j = 0; j < stop; j++){
            int aux;
            cin >> aux;
            if(i == 0)s.insert(aux);
            else if(s.count(aux))s1.insert(aux);
        }
        if(i != 0)s = s1;
    }

    set<int> c;
    for(auto &i : s)
        c.insert(i);
    for(auto &i : c)
        cout << i << " ";
    cout << endl;

    return 0;
}