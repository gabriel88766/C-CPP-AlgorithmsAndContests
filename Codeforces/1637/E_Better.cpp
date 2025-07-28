#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<ll> val[N];
vector<ll> av;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        map<ll, ll> cnt;
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        for(auto [k, v]: cnt){
            val[v].push_back(k);
            av.push_back(v);
        }
        sort(av.begin(), av.end());
        av.resize(unique(av.begin(), av.end()) - av.begin());
        ll ans = 0;
        assert(av.size() <= 800);
        for(auto x : av) sort(val[x].begin(), val[x].end(), greater<int>());

        map<int, set<int>> ds;
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            ds[a].insert(b);
            ds[b].insert(a);
        }
        for(auto &x : av){
            for(auto &y : av){
                int lmj = val[y].size() - 1;
                for(int i=0;i<val[x].size();i++){
                    for(int j=0;j<=lmj;j++){
                        if(val[x][i] == val[y][j]) continue;
                        else if(ds[val[x][i]].count(val[y][j])) continue;
                        else{
                            ans = max(ans, (val[x][i] + val[y][j]) * (x+y));
                            lmj = j - 1;
                            break;
                        }
                    }
                    if(lmj < 0) break;
                }
            }
        }
        cout << ans << "\n";
        for(auto x : av) val[x].clear();
        av.clear();

    }
}
