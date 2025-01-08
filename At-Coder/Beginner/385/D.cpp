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
    map<int, set<int>> mx, my;
    int n, m;
    ll x, y;
    cin >> n >> m >> x >> y;
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        mx[x].insert(y);
        my[y].insert(x);
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        char d;
        int jmp;
        ll xd, yd;
        cin >> d >> jmp;
        if(d == 'U'){
            yd = y + jmp;
            xd = x;
        }
        if(d == 'D'){
            yd = y - jmp;
            xd = x;
        }
        if(d == 'L'){
            xd = x - jmp;
            yd = y;
        }
        if(d == 'R'){
            xd = x + jmp;
            yd = y;
        }
        vector<pair<int,int>> rml;
        if(xd != x){
            ll mn = min(xd, x);
            ll mxx = max(xd, x);
            mn = max(mn, -1'000'000'000LL);
            if(mn <= 1'000'000'000 && my.count(yd)){
                auto it = my[yd].lower_bound(mn);
                while(it != my[yd].end() && *it <= mxx){
                    rml.push_back({*it, yd});
                    ++it;
                }
            } 
        }else{
            ll mn = min(yd, y);
            ll mxx = max(yd, y);
            mn = max(mn, -1'000'000'000LL);
            if(mn <= 1'000'000'000 && mx.count(xd)){
                auto it = mx[xd].lower_bound(mn);
                while(it != mx[xd].end() && *it <= mxx){
                    rml.push_back({xd, *it});
                    ++it;
                }
            }
        }
        ans += rml.size();
        x = xd, y = yd;
        for(auto [a, b] : rml){
            mx[a].erase(b);
            my[b].erase(a);
        }
    }
    cout << x << " " << y << " " << ans << "\n";
}
