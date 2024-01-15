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
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int k = 31 - __builtin_clz(n);
    if(k == 0){
        cout << s << "\n";
        return 0;
    }
    vector<vector<int>> let(26);
    for(int i=1;i<=n;i++){
        let[s[i]-'a'].push_back(i);
    }
    int sz = n - (1 << k) + 1;
    int msk = (1 << k) - 1;
    vector<bool> can(1 << k, true);
    string ans;
    for(int i=1;i<=sz;i++){
        int newl = 0;
        vector<int> nmsk;
        for(int j=0;j<26;j++){
            bool ok = false;
            nmsk.clear();
            for(auto x : let[j]){
                if(x < i) continue;
                if(x - i > msk) continue;
                if(can[x-i]){
                    ok = true;
                    nmsk.push_back(x-i);
                }
            }
            if(ok){
                newl = j;
                break;
            }
        }
        ans += (char)(newl + 'a');
        vector<bool> vis(1 << k, false);
        queue<int> q;
        for(auto x : nmsk){
            q.push(x);
            vis[x] = true;
        }
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(int j=0;j<k;j++){
                if((1 << j) & u);
                else{
                    int v = (1 << j) | u;
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        can = vis;        
    }
    cout << ans << "\n";
}
