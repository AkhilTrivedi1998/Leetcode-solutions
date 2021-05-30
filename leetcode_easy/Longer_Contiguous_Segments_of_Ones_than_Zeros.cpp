#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

bool checkZeroOnes(string s) {
    int l = 0, r = 0, len1 = 0, len2 = 0, n = s.size();
    while(r < n){
        if(s.at(r) == '1'){
            while( r < n && s.at(r) == '1')
                r++;
            if(r-l > len1)
                len1 = r-l;
        }
        else{
            while( r < n && s.at(r) == '0')
                r++;
            if(r-l > len2)
                len2 = r-l;
        }
        l = r;
    }
    if(len1 > len2)
        return true;
    else
        return false;
}
int main(){
    string s = "11000";
    cout<<checkZeroOnes(s)<<endl;
    return 0;
}