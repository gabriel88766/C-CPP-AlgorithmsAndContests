#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    int val;
    string s, t;
    cin >> s >> t;
    int n = s.size();
    s += s;
    bool ok = false;
    for(int i=0;i<n;i++){
        if(s.substr(i, t.size()) == t) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}

