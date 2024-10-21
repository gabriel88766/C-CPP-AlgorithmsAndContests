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
    vector<int> a(n), b(n-1);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p0 = n-1, p1 = n-2;
    int ans = -1;
    for(int i=n-1;i>=0;i--){
        if(p1 >= 0){
            if(b[p1] >= a[p0]){
                p0--;
                p1--;
            }else{
                if(ans == -1){
                    ans = a[p0];
                    p0--;
                }else{
                    ans = -1;
                    break;
                }
            }
        }else{
            ans = a[p0];
            assert(p0 == 0);
        }
    }
    cout << ans << "\n";
}
