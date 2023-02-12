#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    string s;
    cin >> s;
    while(s != "-"){
        int n = s.size();
        s += s;
        int q, pos = 0;
        cin >> q;
        for(int i=0;i<q;i++){
            int a;
            cin >> a;
            pos += a;
            pos %= n;
        }
        cout << s.substr(pos, n) << "\n";

        cin >> s;
    }

}

