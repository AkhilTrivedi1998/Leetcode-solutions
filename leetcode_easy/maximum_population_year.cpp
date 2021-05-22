#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

int maximumPopulation(vector<vector<int>>& logs) {
	int log_chart[101] = {0};
	for(auto itr : logs){
	    int birth = itr[0]-1950, death = itr[1]-1950;
	    log_chart[birth] += 1;
	    log_chart[death] -= 1;
	}
	int year[101] = {0};
	year[0] = log_chart[0];
	for(int i=1;i<101;i++){
	    year[i] = year[i-1] + log_chart[i];
	}
	int max_count = 0, sma_year;
	for(int i=100;i>=0;i--){
	    if(year[i] >= max_count){
	        sma_year = i + 1950;
	        max_count = year[i];
	    }
	}
	return sma_year;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> v;
	for(int i=0;i<n;i++){
		vector<int> v1(2,0);
		cin>>v1[0]>>v1[1];
		v.push_back(v1);
	}
	cout<<maximumPopulation(v)<<endl;
	return 0;
}