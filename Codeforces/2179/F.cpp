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
    if(s == "first"){
        int t;
        cin >> t;
        while(t--){
            int n, m;
            cin >> n >> m;
            vector<vector<int>> adj(n+1);
            for(int i=1;i<=m;i++){
                int a, b;
                cin >> a >> b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            vector<int> d(n+1, INF_INT);
            d[1] = 0;
            queue<int> q;
            q.push(1);
            while(q.size()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(d[v] > d[u] + 1){
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
            string ans;
            for(int i=1;i<=n;i++){
                if(d[i] % 3 == 0) ans += 'r';
                else if(d[i] % 3 == 1) ans += 'g';
                else ans += 'b';
            }
            cout << ans << "\n";
        }
    }else{
        int t;
        cin >> t;
        while(t--){
            int q;
            cin >> q;
            while(q--){
                int dx;
                string s;
                cin >> dx >> s;
                bool hr = false, hg = false, hb = false;
                for(auto c : s){
                    if(c == 'r') hr = true;
                    if(c == 'g') hg = true;
                    if(c == 'b') hb = true;
                }
                assert(hr == false || hg == false || hb == false);
                char cans;
                if(hr && hb) cans = 'r';
                else if(hg && hr) cans = 'g';
                else if(hb && hg) cans = 'b';
                else{
                    if(hr) cans = 'r';
                    else if(hg) cans = 'g';
                    else cans = 'b';
                }
                for(int j=0;j<s.size();j++){
                    if(s[j] == cans){
                        cout << j+1 << "\n";
                        break;
                    }
                }
            }
        }
    }
}
