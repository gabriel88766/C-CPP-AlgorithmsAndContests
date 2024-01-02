#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int a_and(int i, int j){
    cout << "and " << i << " " << j << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int a_or(int i, int j){
    cout << "or " << i << " " << j << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<ll> v(n+1);
    for(int i=2;i<=n;i++){
        int a1, a2;
        a1 = a_and(1, i);
        a2 = a_or(1, i);
        v[i] = a1 + a2;
    }
    ll a3, a4;
    a3 = a_and(2, 3);
    a4 = a_or(2, 3);
    ll res = v[2] - (a3 + a4) + v[3];
    assert(!(res % 2));
    res /= 2;
    v[1] = res;
    for(int i=2;i<=n;i++) v[i] -= v[1];
    sort(v.begin() + 1, v.end());
    cout << "finish " << v[k] << "\n";
    cout.flush();
    //v[2] + v[3] = a3 + a4
    //v[1] + v[2] = arr[2]
    //v[1] + v[3] = arr[3]
    //then v[1] = (arr[2] + arr[3] - a3 - a4)/2
}
