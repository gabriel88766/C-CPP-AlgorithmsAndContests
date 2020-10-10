#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int Sum=0,ans=0;
char isnegsomewhere = false;
int oldc,newc;
stack<char> st;
string s;
cin >> s;
for(int i=0;i<s.size();i++){
    if(s[i]=='{' || s[i]=='(' || s[i] == '<' || s[i] == '['){
        Sum++;
        st.push(s[i]);
    }else{
        Sum--;
        if(Sum < 0){
            isnegsomewhere=true;
            break;
        }
        newc = (int) s[i];
        oldc = (int) st.top();
        st.pop();
        if(newc != (oldc+1) && newc != (oldc+2)) ans++;
    }
}
if(isnegsomewhere || Sum>0) cout << "Impossible";
else cout << ans;

}

