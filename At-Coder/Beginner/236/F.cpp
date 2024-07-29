#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int num[18];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=1;i<(1 << n);i++){
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i=0;i<v.size();i++){
        int cn = v[i].second;
        while(cn){
            int b = 31 - __builtin_clz(cn);
            if(num[b]){
                cn ^= num[b];
            }else{
                num[b] = cn;
                break;
            }
        }
        if(cn){
            ans += v[i].first;
        }
    }
    cout << ans << "\n";
}
