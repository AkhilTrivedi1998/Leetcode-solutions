#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	If we are able to form any number in the range [s,e].
	If we take a number A and include it with every number of the range [s,e]. We will be able to form ant number in the range[s+A,e+A].
	Now lets consider the two ranges:
		[s,e] - formed without taking A
		[s+A,e+A] - formed by taking A with every number in the range [s,e]
	So, the range of numbers we can form with or without taking A is [s,e] U [s+A,e+A]
	If s+A <= e+1, then [s,e] U [s+A,e+A] will form a continous sequence [s,e+A]
	Now suppose s+A > e+1, this means we cannot form e+1
		Now lets take another number B >= A.
		The smallest number we can form considering the range [s,e] with B is s+B
		But B >= a => s+B >= s+A > e+1 => s+B > e+1. Thie means we cannot form e+1 by considering B or rather any number greater than A.
		This implies e+1 will be the smallest number which cannot be formed considering the elements of the array.
	If we keep forming continous sequence still at the end we will get e+1 as the required answer.		
*/
int getMaximumConsecutive(vector<int>& coins){
	// To implement the above algorithm we need to sort the array so that each number is greater than or equal to the previous number
	sort(coins.begin(),coins.end());
	// 0 can always be formed by taking no elements
	if(coins[0] != 1)
		return 1;
	// Setting the initial range as [0,1] and then implementing the above algorithm
	int s = 0, e = 1, n = coins.size();
	for(int i=1;i<n;i++){
		int l = s + coins[i], r = e + coins[i];
		if(l <= e + 1){
			e = r;
		}
		else{
			return e + 1;
		}
	}
	return e + 1;        
}
int main(){
	vector<int> v{1,1,1,4};
	cout<<getMaximumConsecutive(v)<<endl;
	return 0;
}
/*
	Time complexity : O(NlogN)
	Space complexity : o(1)
*/