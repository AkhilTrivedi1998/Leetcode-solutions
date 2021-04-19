#include<iostream>
#include<set>
#include<vector>
using namespace std;

int getNumberOfBacklogOrders(vector<vector<int>>& orders){
	const int mod = 1e9 + 7;
	multiset<pair<int,int>,greater<pair<int,int>>> cost;
	multiset<pair<int,int>> sell;
	for(auto v : orders){
		if(v[2] == 0){
			int p = v[0], amt = v[1];
			auto it = sell.begin();
			while(amt != 0 && it != sell.end()){
				if((*it).first <= p){
					if(amt >= (*it).second){
						amt = amt-(*it).second;
						sell.erase(it);
						it++;
					}
					else{
						int temp1 = (*it).first, temp2 = (*it).second - amt;
						amt = 0;
						sell.erase(it);
						sell.insert(make_pair(temp1,temp2));
					}
				}
				else
					break;
			}
			if(amt != 0)
				cost.insert(make_pair(p,amt));
		}
		else{
			int p = v[0], amt = v[1];
			auto it = cost.begin();
			while(amt != 0 && it != cost.end()){
				if((*it).first >= p){
					if(amt >= (*it).second){
						amt = amt-(*it).second;
						cost.erase(it);
						it++;
					}
					else{
						int temp1 = (*it).first, temp2 = (*it).second - amt;
						amt = 0;
						cost.erase(it);
						cost.insert(make_pair(temp1,temp2));
					}
				}
				else
					break;
			}
			if(amt != 0)
				sell.insert(make_pair(p,amt));
		}
	}
	long long cmt = 0;
	for(auto i : sell){
		cmt = (cmt + i.second)%mod;
	}
	for(auto i : cost){
		cmt = (cmt + i.second)%mod;
	}
	return (int)cmt;
}

int main(){
	vector<vector<int>> v{{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};
	cout<<getNumberOfBacklogOrders(v)<<endl;
	return 0;
}