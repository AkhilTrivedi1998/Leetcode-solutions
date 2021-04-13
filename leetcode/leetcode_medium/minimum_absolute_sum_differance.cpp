#include<iostream>
#include<set>
#include<vector>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
	return a.first >= b.first;
}
int fun(vector<int>& num1, vector<int>& num2){
	const int nxM = 1e9 + 7;
	multiset<int> s2;
	int n = num1.size();
	long long summation = 0;
	for(int i=0;i<n;i++){
		s2.insert(num1[i]);
		int temp = abs(num1[i] - num2[i]);
		summation = (summation + temp)%nxM;
	}
	long long min_sum = summation;
	for(int i=0;i<n;i++){
		auto it = s2.lower_bound(num2[i]);
		if(it == s2.begin()){
			long long s = (summation - abs(num1[i] - num2[i]) + abs((*it) - num2[i]))%nxM;
			if(s < min_sum)
				min_sum = s;
		}
		else{
			int t1 = abs((*it) - num2[i]);
			it--;
			int t2 = abs((*it) - num2[i]);
			int t3 = min(t1,t2);
			long long s = (summation - abs(num1[i] - num2[i]) + t3)%nxM;
			if(s < min_sum)
				min_sum = s;
		}
	}
	return min_sum % nxM;
}
int main(){
	vector<int> v1{1,7,5}, v2{2,3,5};
	cout<<fun(v1,v2)<<endl;
	return 0;
}