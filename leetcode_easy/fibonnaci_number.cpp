#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

int fib(int n) {
	if(n == 0)
	    return 0;
	int f[n+1];
	f[0] = 0;
	f[1] = 1;
	for(int i=2;i<n+1;i++)
	    f[i] = f[i-1] + f[i-2];
	return f[n];
}

int main(){
	cout<<fib(10)<<endl;
	return 0;
}