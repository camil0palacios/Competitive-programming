#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	string s;
	if(n == 1)s = "January";
	else if(n == 2)s = "February";
	else if(n == 3)s = "March";
	else if(n == 4)s = "April";
	else if(n == 5)s = "May";
	else if(n == 6)s = "June";
	else if(n == 7)s = "July";
	else if(n == 8)s = "August";
	else if(n == 9)s = "September";
	else if(n == 10)s = "October";
	else if(n == 11)s = "November";
	else if(n == 12)s = "December";
	cout<<s<<endl;

	return 0;
}