#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    vector<string> vs;
    int cnt = 0;
    while(cin >> s){
        if(cnt++ >= 1) cout << " ";
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
            else if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
        }
        cout << s;
        cout.flush();
    }
    cout << endl;
    
}

