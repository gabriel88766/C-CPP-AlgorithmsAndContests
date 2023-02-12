#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    int val;
    string s;
    vector<int> cnt(26, 0);
    while(cin >> s){
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'A' && s[i] <= 'Z') cnt[s[i]-'A']++;
            else cnt[s[i]-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        cout << (char)('a'+i) << " : " << cnt[i] << "\n";
    }
    
}

