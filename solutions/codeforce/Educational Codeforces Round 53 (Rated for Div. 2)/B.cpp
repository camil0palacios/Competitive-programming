#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v[tmp] = i;
    }
    int actual = 0;
    bool first = false;
    for(int i = 0; i < n; i++){
        int q;
        cin >> q;
        if(!first){
            actual = v[q];
            cout << actual + 1;
            first = true; 
        }
        else if(v[q] > actual){
            cout << v[q] - actual;
            actual = v[q];  
        }
        else cout << 0 ;
        if(i < n - 1)cout << " ";
        else cout << endl;
    }
    return 0;
}