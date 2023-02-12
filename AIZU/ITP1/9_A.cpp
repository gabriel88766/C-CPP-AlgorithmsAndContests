#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    string W, s;
    vector<string> T;
    cin >> W;
    for(int i=0;i<W.size();i++){
        if(W[i] >= 'A' && W[i] <= 'Z') W[i] = W[i] - 'A' + 'a';
    }
    cin >> s;
    while(s != "END_OF_TEXT"){
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        }
        T.push_back(s);
        cin >> s;
    }
    int cnt = 0;
    for(int i=0;i<T.size();i++){
        if(T[i] == W) cnt++;
    }
    cout << cnt << "\n";

}

