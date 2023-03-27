#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct SumSq{
    ll Sq, Sum, cnt;
    SumSq(){
        Sq = Sum = cnt = 0;
    }
    void add(ll num){
        Sq += num*num;
        Sum += num;
        cnt++;
    }
    void dec(int qt){
        while(qt--){
            Sq -= 2*Sum-cnt;
            Sum -= cnt;
        }
        cnt--;
    }

};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    SumSq s1, s2;
    for(int i=1;i<n;i++){
        s1.add(x[i]-x[0]);
        s2.add(y[i]-y[0]);
    }
    ll ans = 0;
    for(int i=1;i<n;i++){
        ans += s1.Sq + s2.Sq;
        s1.dec(x[i]-x[i-1]);
        s2.dec(y[i]-y[i-1]);
    }

    cout << ans;
}
