#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,a,b,c,d,e;
	char s;
	while(true){
		cin>>n;
		if(n==0)break;
		while(n--){
			cin>>a>>b>>c>>d>>e;
			int cont=0;
			if(a <= 127 ){a = 1;cont++;}else a=0;
			if(b <= 127 ){b = 1;cont++;}else b=0;
			if(c <= 127 ){c = 1;cont++;}else c=0;
			if(d <= 127 ){d = 1;cont++;}else d=0;
			if(e <= 127 ){e = 1;cont++;}else e=0;

			if(cont == 1){
				if(a == 1)cout<<"A"<<endl;
				if(b == 1)cout<<"B"<<endl;
				if(c == 1)cout<<"C"<<endl;
				if(d == 1)cout<<"D"<<endl;
				if(e == 1)cout<<"E"<<endl;
			}
			else cout<<"*"<<endl;
		}
	}

	return 0;
}