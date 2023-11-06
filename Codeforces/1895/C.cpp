#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<string> s[6];

vector<pair<vector<int>,vector<int>>> vt = { {{0}, {0,1,1}}, {{0}, {0,0,1,1,1}}, {{0,0},{0,1,1,1}}, {{0,0,1},{1}}
, {{0,0,0}, {0,1,1,1,1}}, {{0,0,0,1}, {1,1}}, {{0,0,0,1,1}, {1}}, {{0,0,0,0,1}, {1,1,1}} };
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string t;
        cin >> t;
        s[t.size()].push_back(t);
    }
    ll ans = 0;
    for(int i=1;i<=5;i++){
        map<ll,ll> mp;
        for(int j=0;j<s[i].size();j++){
            int cur = 0;
            for(int k=0;k<i;k++){
                cur += s[i][j][k] - '0';
            }
            mp[cur]++;
        }
        for(auto x : mp){
            ans += x.second * x.second;
        }
    }

    for(auto x : vt){
        map<ll, ll> mp[2];
        mp[0].clear();
        mp[1].clear();
        int s1 = x.first.size();
        int s2 = x.second.size();
        
        for(int i=0;i<s[s1].size();i++){
            int cur = 0;
            for(int j=0;j<s1;j++){
                if(x.first[j] == 0) cur += s[s1][i][j] - '0';
                else cur -= s[s1][i][j] - '0';
            }
            mp[0][cur]++;
        }
        
        
        for(int i=0;i<s[s2].size();i++){
            int cur = 0;
            for(int j=0;j<s2;j++){
                if(x.second[j] == 1) cur += s[s2][i][j] - '0';
                else cur -= s[s2][i][j] - '0';
            }
            mp[1][cur]++;
        }
        for(auto x : mp[0]){
            if(mp[1].count(x.first)){
                ans += x.second*mp[1][x.first];
            }
        }

    }



    cout << ans << "\n";

}
