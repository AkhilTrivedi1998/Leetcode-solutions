#include<iostream>
using namespace std;

int reinitializePermutation(int n){
	int idx = 1, m = n/2, cnt = 0;
	do{
		if(idx < m)
			idx = 2*idx;
		else
			idx = 2*(idx - m) + 1;
		cnt++;
	}while(idx != 1);
	return cnt;
}

int main(){
	int n;
	cin>>n;
	cout<<reinitializePermutation(n)<<endl;
	return 0;
}