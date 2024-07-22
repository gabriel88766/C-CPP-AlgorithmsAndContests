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
    cin >> n;
    vector<ll> l(n), r(n);
    for(int i=0;i<n;i++) cin >> l[i] >> r[i];
    ll s1 = 0, s2 = 0;
    for(int i=0;i<n;i++){
        s1 += l[i];
        s2 += r[i];
    }
    if(s1 <= 0 && s2 >= 0){
        cout << "Yes\n";
        ll qt = abs(s1);
        for(int i=0;i<n;i++){
            int dif = min(qt, r[i]-l[i]);
            qt -= dif;
            cout << l[i] + dif << " ";
        }
        cout << "\n";
    }else cout << "No\n";
}
