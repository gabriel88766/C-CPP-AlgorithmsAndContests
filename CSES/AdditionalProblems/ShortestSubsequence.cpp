#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    bool has[4];
    has[0] = false;
    has[1] = false;
    has[2] = false;
    has[3] = false;
    string ans,s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'A')  has[0] = true;
        if(s[i] == 'C')  has[1] = true;
        if(s[i] == 'G')  has[2] = true;
        if(s[i] == 'T')  has[3] = true;
        if(has[0] && has[1] && has[2] && has[3]){
            has[0] = false;
            has[1] = false;
            has[2] = false;
            has[3] = false;
            ans += s[i];
        }
    }
    if(!has[0]) ans+= 'A';
    else if(!has[1]) ans+= 'C';
    else if(!has[2]) ans+= 'G';
    else ans+= 'T';
    cout << ans;
 
}