#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Intervals{
    set<pair<int,int>> s;
    Intervals(){}

    void insert(int l, int r){
        if(r < l) return;
        auto it = s.lower_bound({l, -INF_INT});
        vector<pair<int,int>> erl;
        pair<int,int> p = {l, r};
        if(it != s.begin()){
            auto it2 = prev(it);
            if(it2->second >= r) return; //do nothing
            else if(it2->second >= l){ 
                p = {it2->first, r};
                erl.push_back(*it2);
            }
        }
        while(it != s.end()){
            if(it->second <= r){
                erl.push_back(*it);
                ++it;
                continue;
            }else if(it->first <= r){
                p.second = it->second;
                erl.push_back(*it);
            }
            break;
        }
        for(auto x : erl){
            s.erase(x);
        }
        s.insert(p);
    }
};

struct Rect{
    ll xl, xr, yl, yr, S;
};

map<int, Intervals> segx, segy;

int vis[2000000];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<ll> hx, vx;
    for(int i=0;i<n;i++){
        int l, r, x;
        cin >> l >> r >> x;
        vx.push_back(x);
        segy[x].insert(l, r);
    }
    for(int i=0;i<m;i++){
        int l, r, x;
        cin >> x >> l >> r;
        hx.push_back(x);
        segx[x].insert(l, r);
    }
    hx.push_back(-INF_LL);
    hx.push_back(INF_LL);
    vx.push_back(-INF_LL);
    vx.push_back(INF_LL);
    sort(hx.begin(), hx.end());
    hx.resize(unique(hx.begin(), hx.end()) - hx.begin());
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    vector<Rect> vrc;
    int ini = -1;
    for(int i=1;i<hx.size();i++){
        for(int j=1;j<vx.size();j++){
            Rect r = {vx[j-1], vx[j], hx[i-1], hx[i], 0};
            if(abs(r.xl) == INF_LL || abs(r.xr) == INF_LL || abs(r.yl) == INF_LL || abs(r.yr) == INF_LL) r.S = INF_LL;
            else r.S = (r.xr - r.xl) * (r.yr - r.yl);
            vrc.push_back(r);
            if(ini == -1 && r.xl <= 0 && r.xr >= 0 && r.yl <= 0 && r.yr >= 0) ini = vrc.size() - 1;
        }
    }
    int jmp = vx.size() - 1;
    int of[] = {1, -1, jmp, -jmp};
    queue<int> q;
    q.push(ini);
    vis[ini] = true;
    ll ans = min(vrc[ini].S, INF_LL);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int nxt = u + of[i];
            if(nxt < 0 || nxt >= vrc.size()) continue;
            if(vis[nxt]) continue;
            if(i == 0 || i == 1){
                auto it = segy[i == 0 ? vrc[u].xr : vrc[u].xl].s.lower_bound({vrc[u].yl+1, 0});
                if(it != segy[i == 0 ? vrc[u].xr : vrc[u].xl].s.begin()) --it;
                if(it->first <= vrc[u].yl && it->second >= vrc[u].yr);
                else{
                    ans = min(INF_LL, ans + vrc[nxt].S);
                    q.push(nxt);
                    vis[nxt] = true;
                }
            }else{
                auto it = segx[i == 2 ? vrc[u].yr : vrc[u].yl].s.lower_bound({vrc[u].xl+1, 0});
                if(it != segy[i == 2 ? vrc[u].yr : vrc[u].yl].s.begin()) --it;
                if(it->first <= vrc[u].xl && it->second >= vrc[u].xr);
                else{
                    ans = min(INF_LL, ans + vrc[nxt].S);
                    q.push(nxt);
                    vis[nxt] = true;
                }
            }
        }
    }
    if(ans == INF_LL) cout << "INF\n";
    else cout << ans << "\n";

}
