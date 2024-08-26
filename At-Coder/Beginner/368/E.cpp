#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> adji[N];
int a[N], b[N], s[N], t[N], ans[N];

void notdijkstra(int x){
    priority_queue<pair<int, int>> pq;
    pq.push({x, 1});
    ans[1] = x;
    while(!pq.empty()){
        auto [x, j] = pq.top();
        pq.pop();
        if(x != ans[j]) continue;
        if(adji[b[j]].size() == 0) continue;
        int lo = 0, hi = adji[b[j]].size() - 1;
        while(lo != hi){
            int m = lo + (hi - lo)/2;
            if(s[adji[b[j]][m]] < t[j]) lo = m + 1;
            else hi = m;
        }
        if(s[adji[b[j]][lo]] < t[j]) continue;
        for(int i = lo ; i < adji[b[j]].size(); i++){
            auto ind = adji[b[j]][i];
            assert(s[ind] >= t[j]);
            int w = x - (s[ind] - t[j]);
            if(ans[ind] < w){
                ans[ind] = w;
                pq.push({w, ind});
            }else break;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, x;
    cin >> n >> m >> x;
    for(int i=1;i<=m;i++){
        cin >> a[i] >> b[i] >> s[i] >> t[i];
        adji[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        sort(adji[i].begin(), adji[i].end(), [&](int u, int v){
            return s[u] < s[v];
        });
    }
    notdijkstra(x);
    for(int i=2;i<=m;i++) cout << ans[i] << " ";
    cout << "\n";
}
