#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<string> a;
    string aux;
    cin>>n;
    for(int i=0; i < n ; i++){
        cin>>aux;
        a.push_back(aux);
    }
    for(int i=0; i < a.size(); i++){
        if(a[i].size() > 10){
            cout<<a[i][0]<<a[i].size()-2<<a[i][a[i].size()-1]<<"\n";
        }else cout<<a[i]<<"\n";
    }
    return 0;
}
