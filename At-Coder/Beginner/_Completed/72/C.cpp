#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int cnt[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, in;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> in;
        if(in) cnt[in-1]++;
        cnt[in]++;
        cnt[in+1]++;
    }
    int ans = 0;
    for(int i=0;i<N;i++) ans = max(ans, cnt[i]);
    cout << ans;
}
