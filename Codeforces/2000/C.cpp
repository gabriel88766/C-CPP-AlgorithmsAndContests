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
        cin >> n;
        vector<int> v(n);
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            cin >> v[i];
            mp[v[i]].push_back(i);
        }
        int q;
        cin >> q;
        for(int j=0;j<q;j++){
            string s;
            cin >> s;
            if(s.size() != n) cout << "NO\n";
            else{
                //condition 3
                vector<vector<int>> inx(26);
                for(int i=0;i<n;i++){
                    inx[s[i]-'a'].push_back(i);
                }
                bool ok = true;
                for(int i=0;i<26;i++){
                    for(int k=1;k<inx[i].size();k++){
                        if(v[inx[i][k]] != v[inx[i][0]]) ok = false;
                    }
                }
                for(auto const &[k, vx] : mp){
                    for(int i=1;i<vx.size();i++){
                        if(s[vx[i]] != s[vx[0]]) ok = false;
                    }
                }
                if(ok) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}
