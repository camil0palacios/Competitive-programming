#include <bits/stdc++.h>
using namespace std;

int a[2001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 2*n; i++)cin >> a[i];
    sort(a, a+(2*n));
    if(a[0] == a[2*n - 1]){
        cout << -1 << endl;
    }else{
        for(int i = 0; i < 2*n; i++){
            cout << a[i] << " ";
        }   
    }
    return 0;
}