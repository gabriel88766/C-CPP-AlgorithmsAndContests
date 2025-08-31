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
    ll r1, c1, r2, c2;
    ll n, m, l;
    cin >> r1 >> c1 >> r2 >> c2 >> n >> m >> l;
    vector<pair<char,ll>> v1(m), v2(l);
    for(int i=0;i<m;i++){
        cin >> v1[i].first >> v1[i].second;
    }
    for(int i=0;i<l;i++){
        cin >> v2[i].first >> v2[i].second;
    }
    ll p1 = 0, p2 = 0, av1 = 0, av2 = 0;
    ll ans = 0;


    auto checkmove = [&](char x, ll &r, ll &c){
        if(x == 'L'){
            r = 0, c = -1;
        }else if(x == 'R'){
            r = 0, c = 1;
        }else if(x == 'D'){
            r = 1, c = 0;
        }else{
            r = -1, c = 0;
        }
    };

    while(p1 < m && p2 < l){
        // cout << r1 << " " << c1 << " " << r2 << " " << c2 << "\n";
        ll mv = min(v1[p1].second - av1, v2[p2].second - av2);
        ll mr1 = 0, mr2 = 0, mc1 = 0, mc2 = 0;
        checkmove(v1[p1].first, mr1, mc1);
        checkmove(v2[p2].first, mr2, mc2);

        av1 += mv, av2 += mv;
        if(r1 == r2 && c1 == c2){
            //this was already counted! == YES
            if(v1[p1].first == v2[p2].first){
                ans += mv;
            }
        }else{
            if(v1[p1].first == v2[p2].first); //do nothing
            else if(min(v1[p1].first, v2[p2].first) == 'L' && max(v1[p1].first, v2[p2].first) == 'R'){
                if(r1 == r2){
                    ll val = llabs(c1-c2)/2;
                    ll dir = 2 * ((c1-c2) / llabs(c1 - c2));
                    if(val <= mv && abs(c1 % 2) == abs(c2 % 2) && dir == mc2 - mc1) ans++;
                }
            }//maybe 2
            else if(min(v1[p1].first, v2[p2].first) == 'D' && max(v1[p1].first, v2[p2].first) == 'U'){
                if(c1 == c2){
                    ll val = llabs(r1-r2)/2;
                    ll dir = 2 * ((r1-r2) / llabs(r1 - r2));
                    if(val <= mv && abs(r1 % 2) == abs(r2 % 2) && dir == mr2 - mr1) ans++;
                }
            }//maybe 3 ...
            else{
                // assert(abs(mr2 - mr1) == 1 && abs(mc2 - mc1) == 1);
                ll d1 = r1 - r2;
                ll d2 = c1 - c2;
                if(llabs(d1) == llabs(d2) && llabs(d1) <= mv){
                    //maybe ...
                    d1 /= llabs(d1);
                    d2 /= llabs(d2);
                    if(d1 == mr2 - mr1 && d2 == mc2 - mc1) ans++;
                }
            }
        }
        
        r1 += mr1 * mv;
        r2 += mr2 * mv;
        c1 += mc1 * mv;
        c2 += mc2 * mv;
        if(av1 == v1[p1].second){
            p1++;
            av1 = 0;
        }
        if(av2 == v2[p2].second){
            p2++;
            av2 = 0;
        }
    }
    cout << ans << "\n";

}
