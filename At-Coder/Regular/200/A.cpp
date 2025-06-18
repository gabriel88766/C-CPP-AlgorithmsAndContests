#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll a[N], b[N], c[N];
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
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        int idx = -1;
        for(int i=2;i<=n;i++){
            if(a[i] * b[i-1] != a[i-1] * b[i]){
                idx = i;
                break;
            }
        }
        if(idx == -1) cout << "No\n";
        else{
            for(int i=1;i<=n;i++){
                if(i != idx && i+1 != idx) c[i] = 0;
                else c[i] = -1;
            }
            c[idx-1] = a[idx-1] + b[idx-1]; // x
            c[idx] = a[idx] + b[idx]; // y
            //check if tg[a] > tg[c] -> a[idx] / a[idx-1] > c[idx] / c[idx-1];
            //if so, rotate 90 counterclockwise
            if(a[idx] * c[idx-1] > c[idx] * a[idx - 1]){
                ll y = c[idx-1];
                ll x = -c[idx];
                c[idx-1] = x;
                c[idx] = y;
            }else{
                ll y = -c[idx-1];
                ll x = c[idx];
                c[idx-1] = x;
                c[idx] = y;
            }
            cout << "Yes\n";
            for(int i=1;i<=n;i++) cout << c[i] << " ";
            cout << "\n";
        }
    }
}
