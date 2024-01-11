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
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int a0, a1, a2;
    ll maxs = 0;
    for(int i=0;i<=n;i++){
        //now delim 1 = i
        ll curms = 0;
        vector<ll> ps(i);
        int i1=0, i2=i;
        for(int j=0;j<i;j++){
            if(j == 0) ps[j] = v[j];
            else ps[j] = ps[j-1] + v[j];
        }
        ll mps = 0;
        for(int j=0;j<i;j++){
            if(ps[j] > mps){
                mps = ps[j];
                i1 = j+1;
            }
        }
        if(i) curms += 2*mps - ps[i-1];
        vector<ll> ps2(n-i);
        for(int j=i;j<n;j++){
            if(j == i) ps2[j-i] = v[j];
            else ps2[j-i] = ps2[j-i-1] + v[j]; 
        }
        mps = 0;
        for(int j=i;j<n;j++){
            if(ps2[j-i] > mps){
                mps = ps2[j-i];
                i2 = j+1;
            }
        }
        if(i != n) curms += 2*mps - ps2[n-i-1];
        if(curms > maxs){
            maxs = curms;
            a0 = i1, a1 = i, a2 = i2;
        }
    }
    cout << a0 << " " << a1 << " " << a2 << "\n";
}
