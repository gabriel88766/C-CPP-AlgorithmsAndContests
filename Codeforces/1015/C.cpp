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
    ll n, m;
    cin >> n >> m;
    int ans = n;
    ll sum = 0;
    vector<int> dif;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        sum += b;
        dif.push_back(a-b);
    }
    sort(dif.begin(), dif.end());
    if(sum > m) cout << "-1\n";
    else{
        for(int i=0;i<n;i++){
            if(sum + dif[i] <= m){
                ans--;
                sum += dif[i];
            }else break;
        }
        cout << ans << "\n";
    }
}
