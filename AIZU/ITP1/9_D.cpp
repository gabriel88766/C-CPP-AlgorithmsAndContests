#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    string s;
    int n;
    cin >> s >> n;
    for(int i=0;i<n;i++){
        string op;
        int a, b;
        cin >> op >> a >> b;
        if(op == "replace"){
            string ns;
            cin >> ns;
            for(int i=a;i<=b;i++) s[i] = ns[i-a];
        }
        if(op == "reverse"){
            reverse(s.begin() + a, s.begin() + b + 1);
        }
        if(op == "print"){
            cout << s.substr(a, b-a+1) << "\n";
        }
    }

}

