#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        char c;
        cin >> n >> c;
        map<char, vector<string>> mp;
        for(int i=0;i<2*n;i++){
            string s;
            cin >> s;
            mp[s[1]].push_back(s);
        }
        vector<pair<string, string>> ans;
        vector<string> aux;
        for(auto &[x, v] : mp){
            if(x == c) continue;
            sort(v.begin(), v.end());
            for(int i=0;i<v.size();i+=2){
                if(i+1 < v.size()) ans.push_back({v[i], v[i+1]});
                else aux.push_back(v[i]);
            }
        }
        if(aux.size() <= mp[c].size()){
            sort(mp[c].begin(), mp[c].end());
            for(int i=0;i<aux.size();i++){
                ans.push_back({aux[i], mp[c][i]});
            }
            for(int i=aux.size();i<mp[c].size();i+=2){
                ans.push_back({mp[c][i], mp[c][i+1]});
            }
            for(auto [a, b] : ans) cout << a << " " << b << "\n";
        }else cout << "IMPOSSIBLE\n";
        
    }
}
