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
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll Sum = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        ll aux = v[i];
        ll cur = 0;
        while(aux){
            cur += aux % 10;
            aux /= 10;
        }
        Sum += n*cur;
    }
    Sum *= 2;
    ll c = 0;
    ll mod = 1;
    for(int i=1;i<=15;i++){ //suffix size.
        mod *= 10;
        vector<ll> cv;
        for(int j=0;j<n;j++){
            cv.push_back(v[j] % mod);
        }
        sort(cv.begin(), cv.end());
        int pl = n-1;
        for(int j=0;j<n;j++){
            while(pl >= 0 && cv[pl] + cv[j] >= mod) --pl;
            c += n-1 - pl;
        }
    }


    Sum -= 9*c;
    cout << Sum << "\n";
}
