#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> val[N];
vector<int> av;
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

        map<int, vector<pair<int, int>>> ds;
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            ds[a].push_back({cnt[b], b});
            ds[b].push_back({cnt[a], a});
        }
        //N sqrt N
        for(auto [k, v] : cnt){
            sort(ds[k].begin(), ds[k].end(), [&](pair<int, int> a, pair<int, int> b){
                if(a.first != b.first) return a.first < b.first;
                else return a.second > b.second;
            });
            int p = 0;
            auto &vx = ds[k];
            for(auto &x : av){
                while(p < vx.size() && vx[p].first < x) p++;
                for(auto &y : val[x]){
                    if(p < vx.size() && vx[p].second == y) p++;
                    else if(y == k) continue;
                    else{
                        ans = max(ans, (k + y) * (v + x));
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
        for(auto x : av) val[x].clear();
        av.clear();

    }
}
