#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<pair<string,int>> v;
map<string,int> mp, mp2;
set<string> winners;
string winner;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxv = 0, p;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s >> p;
        mp[s] += p;
        v.push_back({s, p});
    }
    
    for(int i=0; i < n; i++){
        maxv = max(maxv, mp[v[i].first]);
    }

    for(int i=0; i < n; i++){
        if( maxv == mp[v[i].first]){
            winners.insert(v[i].first);
        }
    }
    
    for(int i=0; i < n; i++){
        mp2[v[i].first] += v[i].second;
        if(mp2[v[i].first] >= maxv && winners.count(v[i].first)){
            winner = v[i].first;
            break;
        }
    }

    cout << winner;
}
