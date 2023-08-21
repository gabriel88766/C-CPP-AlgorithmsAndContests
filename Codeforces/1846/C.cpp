#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct player{
    ll i;
    ll prob;
    ll pen;
    bool operator< (const player &p) const {
        if(p.prob != prob) return prob > p.prob;
        else if(p.pen != pen) return pen < p.pen;
        else return i < p.i;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, m, h;
        cin >> n >> m >> h;
        vector<vector<ll>> v(n, vector<ll> (m));
        vector<player> vp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end());
            ll S = 0;
            ll pen = 0;
            ll p = 0;
            while(S <= h && p < m){
                if(S + v[i][p] <= h){
                    S += v[i][p];
                    p++;
                    pen += S;
                }else break;
            }
            vp[i].prob = p;
            vp[i].pen = pen;
            vp[i].i = i;
        }
        sort(vp.begin(), vp.end());
        for(int i=0;i<n;i++){
            if(vp[i].i == 0) cout << i+1 << "\n";
        }
    }
}
