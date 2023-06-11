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
    vector<int> v(n), ps(n,0);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=2;i<n;i+=2){
        ps[i] += ps[i-1];
        ps[i] += (v[i] - v[i-1]);
        ps[i+1] = ps[i];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        int posl = lower_bound(v.begin(), v.end(), l) - v.begin();
        int posr = prev(upper_bound(v.begin(), v.end(), r)) - v.begin();
        ans = ps[posr] - ps[posl];
        if(posl % 2 == 0){
            ans += v[posl] - l;
        }
        if(posr % 2){
            ans += r - v[posr];
        }
        cout << ans << "\n";
    }
}
