#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mk make_pair
using namespace std;

int numUniqueEmails(vector<string>& emails){
    const int p = 31;
    const int m = 1e9 + 7;
    set<ll> res;
    for(string s : emails){
        int n = s.size(), f = 0, j = 0;
        long long hash_val = 0, p_val = 1;
        for(int i=0;i<n;i++){
            char ch = s.at(i);
            if(ch == '@'){
                f = 1;
                hash_val = (hash_val%m + (27*p_val)%m + m)%m;
            }
            else if(f == 0 && ch == '.')
                continue;
            else if(f == 0 && ch == '+'){
                while(s.at(i) != '@')
                    i++;
                i--;
                continue;
            }
            else{
                if(ch == '.')
                    hash_val = (hash_val%m + (28*p_val)%m + m)%m;
                else if(ch == '+')
                    hash_val = (hash_val%m + (29*p_val)%m + m)%m;
                else
                    hash_val = (hash_val%m + ((ch-'a'+1)*p_val)%m + m)%m;
            }
            p_val = (p_val*p)%m;
            j++;
        }
        res.insert(hash_val);
    }
    int ans = res.size();
    return ans;
}

int main(){
    vector<string> emails = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    cout<<numUniqueEmails(emails)<<endl;
    return 0;
}