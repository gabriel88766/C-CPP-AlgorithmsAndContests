#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> v;
ll cn[1 << 12];
int n;
vector<ll> solve(int msk){
    vector<ll> ret;
    if(__builtin_popcount(msk) == n){
        ret.push_back(0);
        return ret;
    }
    int msb = -1;
    for(int j=n-1;j>=0;j--){
        if((msk & (1 << j)) == 0){
            msb = j;
            break;
        }
    }
    if(msb == -1){
        cout << msk << endl;
    }
    msk |= (1 << msb);
    int x = (1 << n) - 1;
    x ^= msk;
    ll num = v[msb];
    for(int s = x; ;s = (s-1) & x){
        ll cnn = num + cn[s];
        auto aux = solve(msk | s);
        for(auto &x : aux){
            ret.push_back(x ^ cnn);
        }
        if(s == 0) break;
    }
    return ret;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=1;i<(1 << n);i++){
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                cn[i] += v[j];
            }
        }
    }
    auto ans = solve(0);
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << "\n";
}
