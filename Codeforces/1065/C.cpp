#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+5;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int me = *min_element(v.begin(), v.end());
    for(int i=0;i<n;i++) v[i] -= me;
    for(int i=0;i<n;i++) cnt[v[i]]++;
    int mx = *max_element(v.begin(), v.end());
    if(mx == 0){
        cout << "0\n";
        return 0;
    }
    int ans = 1;
    int sc = 0;
    for(int i=N-2;i>=1;i--){
        cnt[i] += cnt[i+1];
        if(sc + cnt[i] <= k) sc += cnt[i];
        else{
            ans++;
            sc = cnt[i];
        }
    }
    cout << ans << "\n";
    
}
