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
    int p0 = 0, p1 = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i){
            if(i % 2) p0 += v[i];
            else p1 += v[i];
        }
    }
    int ans = 0;
    if(p0 == p1) ans++;
    for(int i=1;i<n;i++){
        if(i % 2){
             p0 -= v[i];
             p0 += v[i-1];
        }else{
             p1 -= v[i];
             p1 += v[i-1];
        }
        if(p0 == p1) ans++;
    }
    cout << ans << "\n";
}
