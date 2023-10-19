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
    int n;
    vector<int> v = {0};
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    v.push_back(0);
    ll tt = 0;
    for(int i=1;i<=n+1;i++){
        tt += abs(v[i] - v[i-1]);
    }
    for(int i=1;i<=n;i++){
        ll cur = tt;
        cur -= abs(v[i] - v[i-1]);
        cur -= abs(v[i+1] - v[i]);
        cur += abs(v[i+1] - v[i-1]);
        cout << cur << "\n";
    }
}
