#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<bool> has(N, false), pos(N, false);
    for(int i=0;i<v.size();i++) has[v[i]] = true;
    for(int i=2;i<N;i++){
        bool hm = false;
        for(int j=i;j<N;j+=i){
            if(has[j]) hm = true;
        }
        if(hm){
            for(int j=i;j<N;j+=i) pos[j] = true;
        }
    }
    vector<int> ans;
    for(int i=1;i<=m;i++) if(!pos[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for(auto x : ans ) cout << x << "\n";
}
