#include <bits/stdc++.h>
using namespace std;


int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int mayorab=(a+b+abs(a-b))/2;
	cout<<(mayorab+c+abs(mayorab-c))/2<<" eh o maior"<<endl;
	return 0;
}
