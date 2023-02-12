#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int val;
    string s;
    cin >> s;
    while(s != "0"){
        val = 0;
        for(int i=0;i<s.size();i++) val+= s[i] - '0';
        cout << val << "\n";
        cin >> s;
    }
    
}

