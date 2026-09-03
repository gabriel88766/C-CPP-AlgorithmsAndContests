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
    int n, s;
    cin >> n >> s;
    vector<int> a(n+1), cnt(n+1);
    //if a[i] == 0 and i != s, then it will always be wrong no matter what.
    //if a[i] != 0 and i == s, then it will always be wrong no matter what.
    int wr = n-1, ms = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i == s){
            if(a[i] != 0) {wr++; ms = 1;}
        }else{
            cnt[a[i]]++;
        }
    }
    int ans = wr;
    for(int i=1;i<n;i++){
        wr -= cnt[i];
        if(cnt[i] == 0) ms++;
        ans = min(ans, max(ms, wr));
    }
    cout << ans << "\n";
}
