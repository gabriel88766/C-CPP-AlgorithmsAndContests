#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;



int main(){
    string s,ans;
    int cont=0;
    cin >> s;
    bool hasS=true;
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    for(int i=0;i<26;i++){
        if(mp['A'+i]%2) cont++;
    }
    if(cont >1) hasS=false;

    if(!hasS) cout << "NO SOLUTION";
    else{
        for(int i=0;i<26;i++){
            while(mp['A'+i]>1){
                ans+=(char)('A'+i);
                mp['A'+i]-=2;
            }
        }
        cout << ans;
        if(s.size()%2){
            for(int i=0;i<26;i++){
                if(mp['A'+i]==1) cout << (char)('A'+i);
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans;
    }
}

