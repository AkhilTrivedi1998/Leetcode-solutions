#include<iostream>
using namespace std;

long long sumUtil(int val, int i){
	if(i >= val-1)
		return (long long)(val-1)*val/2 + (i + 1 - val);
	else
		return (long long)i*(val-i + val-1)/2;
}

long long sum1(int val, int n, int i){
	return sumUtil(val,i) + val + sumUtil(val,n-i-1);
}

int binarySearch(int n, int i, int maxSum, int l, int r){
	if(l == r){
		return l;
	}
	if(r-l == 1){
		int s;
		long long s1 = sum1(l,n,i), s2 = sum1(r,n,i);
		if(s1 <= maxSum)
			s = l;
		if(s2 <= maxSum)
			s = r;
		return s;
	}
	int mid = (r+l)/2;
	long long s = sum1(mid,n,i);
	if(s > maxSum)
		return binarySearch(n,i,maxSum,l,mid);
	else
		return binarySearch(n,i,maxSum,mid,r);
}

int maxValue(int n, int i, int maxSum){
	return binarySearch(n,i,maxSum,1,maxSum);
}

int main(){
	int n,i,maxSum;
	cin>>n>>i>>maxSum;
	cout<<maxValue(n,i,maxSum)<<endl;
	return 0;
}