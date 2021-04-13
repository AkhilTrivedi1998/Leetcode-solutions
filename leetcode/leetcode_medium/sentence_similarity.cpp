#include <bits/stdc++.h>
using namespace std;
 
void removeDupWord(vector<string>& v, string str){
	istringstream ss(str);
	string word;
	while (ss >> word) 
	    v.push_back(word);
}

bool fun(vector<string>& v1, vector<string>& v2){
	int n1 = v1.size(),n2 = v2.size();
	int i = 0;
	while(i < n2 && v1[i] == v2[i])
		i++;
	if(i == n2)
		return true;
	else{
		int d = n1 - n2;
		while(i <  n2 && v1[d+i] == v2[i])
			i++;
		if(i == n2)
			return true;
		else
			return false;
	}
}

bool areSentencesSimilar(string s1, string s2){
	vector<string> v1, v2;
	removeDupWord(v1,s1);
	removeDupWord(v2,s2);
	if(v1.size() >= v2.size())
		return fun(v1,v2);
	else
		return fun(v2,v1);
}

int main(){
	string s1 = "Lucy";
	string s2 = "Luccy";
	cout<<areSentencesSimilar(s1,s2)<<endl;
	return 0;
}