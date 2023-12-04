#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> p[N];
int pos[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int p1 = 0;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
         cin >> v[i];
         pos[v[i]] = i;
    }
    ll ans = 0;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        for(auto x : p[v[i]]){
            if(pos[x] < i) p1 = max(p1, pos[x]+1);
        }
        ans += i - p1 + 1;
    }
    cout << ans << "\n";
}
