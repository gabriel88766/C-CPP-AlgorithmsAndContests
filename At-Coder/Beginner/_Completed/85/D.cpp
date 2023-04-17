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
    int n, h, maxv = 0;
    cin >> n >> h;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        int a;
        cin >> a >> b[i];
        maxv = max(a, maxv);
    }
    sort(b.begin(), b.end(), greater<int>());
    int curdmg = 0, ans = INF_INT;
    for(int i=0;i<=n;i++){
        if(curdmg < h){
            ans = min(ans, i + (h-curdmg-1)/maxv+1);
        }else{
            ans = min(ans, i);
            break;
        }
        if(i == n) break;
        curdmg += b[i]; 
    }
    cout << ans;
}
