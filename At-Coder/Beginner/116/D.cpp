#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<ll> dd[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int t, d;
        cin >> t >> d;
        dd[t].push_back(d);
    }
    vector<pair<ll, ll>> bv;
    for(int i=1;i<=n;i++){
        if(dd[i].size()){
            sort(dd[i].begin(), dd[i].end(), greater<ll>());
            bv.push_back({dd[i][0], i});
        }
    }
    sort(bv.begin(), bv.end(), greater<pair<ll, ll>>());
    multiset<ll> an;
    ll sum = 0, ans = 0, sum2 = 0;
    for(ll i=0;i<bv.size(); i++){
        ll cans = (i+1) * (i+1);
        int x = bv[i].second;
        sum2 += dd[x][0];
        int ttn = k - i - 1;
        if(ttn < 0) break;
        for(int j=1;j<dd[x].size();j++){
            sum += dd[x][j];
            an.insert(dd[x][j]);
        }
        while(an.size() > ttn){
            sum -= *an.begin();
            an.erase(an.begin());
        }
        if(an.size() == ttn) ans = max(ans, sum + sum2 + cans);
    }
    cout << ans << "\n";
}
