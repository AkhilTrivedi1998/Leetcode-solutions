#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

int power(int a,int b){
	if(b == 0)
		return 1;
	int res = power(a, b/2);
	res = res*res;
	if(b%2 == 1)
		res = res*a;
	return res;
}

int subsetXORSum(vector<int>& nums){
	//cout<<"hello"<<endl;
	int n = power(2,nums.size()), t_xor = 0;
	//cout<<n<<endl;
	for(int i=1;i<n;i++){
		//cout<<i<<endl;
	    int x = 0, k = i, j = 0;
	    while(k){
	    	if(k & 1){
	    		//cout<<x<<" "<<nums[j]<<endl;
	    		x = x^nums[j];
	    		//cout<<k<<" "<<x<<endl;
	    	}
	    	k = k/2;
	    	j++;
	    }
	    t_xor += x;
	}
	return t_xor;
}

int main(){
	int n;
	//cout<<(1 & 2)<<endl;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	//cout<<power(2,12)<<endl;
	cout<<subsetXORSum(v)<<endl;
}