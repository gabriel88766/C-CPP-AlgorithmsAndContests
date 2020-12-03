#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector<string> v;
    while(next_permutation(s.begin(),s.end()));
    do{
        v.push_back(s);
    }
    while(next_permutation(s.begin(),s.end()));
    cout << v.size() << "\n";
    for(int i=0;i<v.size();i++){
        cout << v[i] << "\n";
    }
}

