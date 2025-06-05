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
    ll sum = 0;
    vector<ll> ap;
    for(int i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        sum -= a;
        ap.push_back(2*a+b);
    }
    sort(ap.begin(), ap.end());
    int ans = 0;
    while(sum <= 0){
        ans++;
        sum += ap.back();
        ap.pop_back();
    }
    cout << ans << "\n";
}
