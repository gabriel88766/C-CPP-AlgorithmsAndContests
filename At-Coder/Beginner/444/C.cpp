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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    //try mx
    int mx = v.back();
    bool ok = true;
    int xv = -1;
    for(int i=n-1;i>=0; i--){
        if(v[i] == mx) continue;
        else{
            xv = i;
            break;
        }
    }
    if(xv % 2){
        for(int i=0;xv - i > i; i++){
            if(v[i] + v[xv-i] != mx) ok = false;
        }
    }else ok = false;
    if(ok) cout << mx << " ";
    //try v[0] + v.back();
    mx = v.back() + v[0];
    ok = true;
    xv = n - 1;
    if(xv % 2){
        for(int i=0;xv-i> i; i++){
            if(mx != v[i] + v[xv-i]) ok = false;
        }
    }else ok = false;
    if(ok) cout << mx << " ";
    cout << "\n";
}
