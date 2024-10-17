#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> solve(vector<ll> &a, ll p0, ll p1){
    vector<ll> v;
    v.push_back(p0);
    v.push_back(p1);
    for(auto x : a){
        auto u = v.size();
        v.push_back(x - v[u-1] - v[u-2]);
    }
    return v;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    auto aux = solve(a, 0, 0);
    ll mn2 = INF_LL, mn1 = INF_LL, mn0 = INF_LL;
    for(int i=0;i<n+2;i++){
        if(i % 3 == 0){
            mn0 = min(aux[i], mn0);
        }
        if(i % 3 == 1){
            mn1 = min(aux[i], mn1);
        }
        if(i % 3 == 2){
            mn2 = min(aux[i], mn2);
        } 
    }
    if(mn2 < 0) cout << "No\n";
    else{
        if(abs(mn0) + abs(mn1) <= mn2){
            //then ok
            aux = solve(a, abs(mn0), abs(mn1));
            cout << "Yes\n";
            for(auto x : aux) cout << x << " ";
            cout << "\n";
        }else cout << "No\n";
    }
}
