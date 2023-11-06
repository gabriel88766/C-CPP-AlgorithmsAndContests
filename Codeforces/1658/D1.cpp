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
        int l, r;
        cin >> l >> r;
        int n = r-l+1;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = 0;
        vector<int> cnt1(17, 0), cnt2(17, 0);
        for(int j=16;j>=0;j--){
            for(int i=0;i<n;i++){
                if(v[i] & (1 << j)) cnt1[j]++;
            }
        }
        for(int j=16;j>=0;j--){
            for(int i=l;i<=r;i++){
                if(i & (1 << j)) cnt2[j]++;
            }
        }
        for(int j=16;j>=0;j--){
            if(cnt1[j] != cnt2[j]) ans ^= (1 << j);
        }
        cout << ans << "\n";
    }
}