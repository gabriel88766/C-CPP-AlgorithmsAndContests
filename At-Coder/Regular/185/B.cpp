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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        ll mxn = v[n];
        ll bl = 0, rem = 0;
        for(int i=n-1;i>=1;i--){
            if(v[i] + bl <= mxn){
                v[i] += bl;
                bl = 0;
                ll ttn = n - i;
                ll os = mxn * ttn + rem + v[i];
                mxn = os / (ttn + 1);
                rem = (os - mxn*(ttn+1));
            }else{
                if(v[i] <= mxn) bl -= (mxn - v[i]);
                else bl += (v[i] - mxn);
            }
        }
        if(bl == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}
