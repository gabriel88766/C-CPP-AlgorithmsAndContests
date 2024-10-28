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
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        int mv = *max_element(a.begin(), a.end());
        if(mv == a[k]) cout << n-1 << "\n";
        else{
            int fp = -1;
            for(int i=1;i<=n;i++){
                if(a[i] > a[k]){
                    fp = i;
                    break;
                }
            }
            int ans = max(fp - 2, 0); 
            if(k > fp){
                swap(a[k], a[fp]);
                int ans2 = fp > 1 ? 1 : 0;
                for(int i=fp+1;;i++){
                    if(a[i] < a[fp]) ans2++;
                    else break;
                }
                ans = max(ans, ans2);
            }
            cout << ans << "\n";
        }
    }
}
