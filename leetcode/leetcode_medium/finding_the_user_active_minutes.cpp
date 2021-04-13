#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> fun(vector<vector<int>>& logs, int k){
	vector<int> res(k,0);
	set<pair<int,int>> s;
	int n = logs.size();
	for(int i=0;i<n;i++){
		s.insert(make_pair(logs[i][0], logs[i][1]));
	}
	int cnt = 0;
	for(auto l=s.begin(),r=s.begin();r!=s.end();r++){
		if(l == r)
			cnt = 1;
		else if((*l).first == (*r).first)
			cnt++;
		else{
			res[cnt-1] += 1;
			l = r;
			r--;
		}
	}
	res[cnt-1] += 1;
	for(int i=0;i<k;i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return res;
}
int main(){
	vector<vector<int>> logs{{0,5},{1,2},{0,2},{0,5},{1,3}};
	int k = 5;
	fun(logs,k);
	return 0;
}