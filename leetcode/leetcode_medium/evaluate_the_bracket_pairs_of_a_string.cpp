#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

string evaluate(string s, vector<vector<string>>& k){
	unordered_map<string,string> mp;
	int n = k.size();
	for(int i=0;i<n;i++)
		mp[k[i][0]] = k[i][1];
	string s1 = "";
	n = s.size();
	for(int i=0;i<n;i++){
		if(s.at(i) == '('){
			string s2 = "";
			i++;
			while(s.at(i) != ')'){
				s2.push_back(s[i]);
				i++;
			}
			if(mp.find(s2) != mp.end())
				s1 += mp[s2];
			else
				s1 += "?";
		}
		else
			s1.push_back(s[i]);
	}
	return s1;
}

int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	vector<vector<string>> v(n, vector<string> (2,""));
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		v[i][0] = s1;
		v[i][1] = s2;
	}
	cout<<evaluate(s,v)<<endl;
	return 0;
}