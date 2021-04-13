#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int rev(int n){
	int m = 0;
	while(n != 0){
		int r = n%10;
		m = m*10 + r;
		n = n/10;
	}
	return m;
}
int countNicePairs(vector<int>& nums){
	const int nxM = 1e9 + 7;
	int n = nums.size();
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		int temp = rev(nums[i]);
		mp[nums[i] - temp] += 1;
	}
	long long cnt = 0;
	for(auto it : mp){
		int m = it.second;
		if(m >= 2)
			cnt += ((m*(m-1))/2);
	}
	return (int)cnt % nxM;
}
int main(){
	vector<int> n{13,10,35,24,76};
	cout<<countNicePairs(n)<<endl;
	return 0;
}