#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

bool rotateString(string s, string goal) {
	int n = s.size(), m = goal.size();
	if(n != m)
	    return false;
	char ch = goal.at(0);
	int i = 0;
	while(i < n && s.at(i) != ch)
	    i++;
	if(i == n)
	    return false;
	int l = i, j = 1, f = 0;
	i = (i+1)%n;
	while(i != l){
	    if(s.at(i) != goal.at(j)){
	        f = 1;
	        break;
	    }
	    i = (i+1)%n;
	    j++;
	}
	if(f == 1)
	    return false;
	else
	    return true;
}

int main(){
	cout<<rotateString("gcmbf","fgcmb")<<endl;
	return 0;
}