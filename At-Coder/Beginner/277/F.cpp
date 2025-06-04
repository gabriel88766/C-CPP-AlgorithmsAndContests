//THIS IS WRONG!!
//THIS IS FUCKING WRONG!!!!
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    vector<vector<int>> gr(h, vector<int>(w));
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> gr[i][j];
    vector<pair<int, int>> rows;
    for(int i=0;i<h;i++){
        int mn = INF_INT, mx = 0;
        for(int j=0;j<w;j++){
            if(gr[i][j] != 0){
                mn = min(mn, gr[i][j]);
                mx = max(mx, gr[i][j]);
            }
        }
        if(mn <= mx) rows.push_back({mn, mx});
    }
    sort(rows.begin(), rows.end());
    bool ok = true;
    for(int i=1;i<rows.size();i++){
        if(rows[i].first < rows[i-1].second) ok = false;
    }
    function<void(vector<int>)> qsort = [&](vector<int> v){
        if(v.size() <= 1) return;
        auto y = v[uniform_int_distribution<int>(0, v.size()-1)(rng)];
        cout << y << "\n";
        vector<int> lw, eq, gv, aux;
        for(auto &x : v){
            if(x == y) continue;
            bool il = false, ig = false;
            for(int i=0;i<h;i++){
                if(gr[i][x] && gr[i][y]){
                    if(gr[i][x] < gr[i][y]) il = true;
                    if(gr[i][x] > gr[i][y]) ig = true;
                }
            }
            if(ig && il){
                ok = false;
                return;
            }else if(ig) gv.push_back(x);
            else if(il) lw.push_back(x);
            else aux.push_back(x);
        }
        vector<int> mx(h, 0), mn(h, INF_INT);
        for(int i=0;i<h;i++){
            for(auto &x : lw) if(gr[i][x]) mx[i] = max(mx[i], gr[i][x]);
            for(auto &x : gv) if(gr[i][x]) mn[i] = min(mn[i], gr[i][x]);
            if(mx[i] > mn[i]){
                ok = false;
                return;
            }
        }
        for(auto &x : aux){
            bool il = false, ig = false;
            for(int i=0;i<h;i++){
                if(gr[i][x]){
                    if(gr[i][x] < mx[i]) il = true;
                    if(gr[i][x] > mn[i]) ig = true;
                }
            }
            if(ig && il){
                ok = false;
                break;
            }else if(ig) gv.push_back(x);
            else if(il) lw.push_back(x);
            // else eq.push_back(x);
        }
        qsort(lw); qsort(gv); qsort(eq);
    };
    vector<int> v(w);
    iota(v.begin(), v.end(), 0);
    qsort(v);
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
