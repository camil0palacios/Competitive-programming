#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<double> &v){
    for(auto &i: v)cout<<i<<" ";
    cout<<endl;
}

double f_binary_search(vector<double>& strips, int a,double imax,double imin){
    double h = imin +((imax - imin)/2),area=0.0000;
    if(imax < imin){return h;}
    for(auto &i :strips){
        if(h < i) area+= i-h;
    }
    if(area > a) return f_binary_search(strips,a,imax,h+1e-10);
    else if(area < a)return f_binary_search(strips,a,h-1e-10,imin);
    else return h;
}

int main(){
    int n,a;
    while(true){
        cin>>n>>a;
        if(n == 0 && a == 0)break;
        else if(a == 0)continue;
        else if(n !=0){
            vector<double> strips(n);
            double area=0;
            for(auto &i: strips){cin>>i;area+=i;}
            if(area == a){cout<<":D"<<endl;continue;}
            if(a > area){cout<<"-.-"<<endl;continue;}
            sort(strips.begin(),strips.end(),std::greater<double>());
            double result = f_binary_search(strips,a,strips[0],0);
            printf("%.4f\n",result);
        }
    }
}
