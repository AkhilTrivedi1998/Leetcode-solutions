#include<iostream>
#include<set>
#include<vector>
using namespace std;
double maxAverageRatio(vector<vector<int>>& classes, int extraStudents){
	multiset<pair<double,pair<int,int>>,greater<pair<double,pair<int,int>>>> s;
	int n = classes.size();
	for(int i=0;i<n;i++){
		s.insert(make_pair((((double)classes[i][0] + 1)/(classes[i][1] + 1)) - ((double)classes[i][0]/classes[i][1]), make_pair(classes[i][0],classes[i][1])));
	}
	// for(auto i : s){
	// 	cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
	// }
	while(extraStudents--){
		auto it = s.begin();
		int a = (*it).second.first + 1, b = (*it).second.second + 1;
		s.erase(it);
		s.insert(make_pair((((double)a+1)/(b+1))-((double)a/b), make_pair(a,b)));
		// cout<<" ################ "<<endl;
		// for(auto i : s){
		// 	cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
		// }
	}
	// auto it = s.begin();
	// int a = (*it).second.first + extraStudents, b = (*it).second.second + extraStudents;
	// s.erase(it);
	// s.insert(make_pair((double)a/b, make_pair(a,b)));
	double res = 0;
	for(auto i : s){
		res += ((double)(i.second.first)/(i.second.second));
	}
	//cout<<" --- "<<res<<endl;
	res = res/n;
	return res;
}
int main(){
	vector<vector<int>> classes{{2,4},{3,9},{4,5},{2,10}};
	cout<<maxAverageRatio(classes,4)<<endl;
	// vector<vector<int>> classes{{1,2},{3,5},{2,2}};
	// cout<<maxAverageRatio(classes,2)<<endl;
	return 0;
}