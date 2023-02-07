#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, s, ts = 0;
        cin >> n >> s;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            ts += a[i];
        }
        if(ts < s){
            cout << "-1\n";
            continue;
        }else if(ts == s){
            cout << "0\n";
            continue;
        }
        int bp = 0, ep = 0, sum = 0, ans = 0;
        while(true){
            if(sum < s){
                if(ep < n) sum += a[ep++];
                else break;
            }else if(sum > s) sum -= a[bp++];
            else{
                ans = max(ans, ep-bp+1);
                if(ep < n) sum += a[ep++];
                else break;
            }
        }
        cout << n - ans+1 << "\n";
    }
}
