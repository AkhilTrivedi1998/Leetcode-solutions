#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

string sortSentence(string s) {
	int n = s.size(),l = 0, r = 0;
	priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> q;
	while(r != n){
	    while(r != n && s.at(r) == ' ')
	        r++;
	    if(r == n)
	        break;
	    l = r;
	    while(r != n && !((s.at(r) >= 48) && (s.at(r) <= 57)))
	        r++;
	    int n = s.at(r) - 48;
	    string s1 = s.substr(l,r-l);
	    q.push(make_pair(n,s1));
	    r++;
	}
	string s2 = "";
	while(!q.empty()){
		int n2 = q.size();
	    auto itr = q.top();
	    string s3 = itr.second;
	    if(n2 > 1)
	    	s2 = s2 + s3 + " ";
	    else
	    	s2 = s2 + s3;
	    q.pop();
	}
	return s2;
}

int main(){
	string s;
	getline(cin, s);
	cout<<sortSentence(s)<<endl;
	return 0;
}