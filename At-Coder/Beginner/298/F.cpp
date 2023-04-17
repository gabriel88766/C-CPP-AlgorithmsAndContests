#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<int, ll> mpr;
map<int, ll> mpc;
map<pair<int,int>, ll> mpd;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    set<int> rows;
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        rows.insert(a);
        mpr[a] += c;
        mpc[b] += c;
        mpd[{a,b}] = c;
    }
    set<pair<ll,ll>> sumsc;
    for(auto x : mpc){
        sumsc.insert({x.second, x.first});
    }
    ll maxsum = 0;
    for(auto x : rows){
        ll cur = mpr[x];
        for(auto it = prev(sumsc.end()); ; --it){
            if(mpd.count({x, it->second})){
                maxsum = max(maxsum, cur + it->first - mpd[{x, it->second}]);
            }else{
                maxsum = max(maxsum, cur + it->first);
                break;
            }
            if(it == sumsc.begin()) break;
        }
    }
    cout << maxsum;
}

