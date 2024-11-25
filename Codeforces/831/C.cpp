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
    int k, n;
    cin >> k >> n;
    vector<int> a(k+1), b(n);
    for(int i=1;i<=k;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++) cin >> b[i];
    vector<int> pos;
    sort(b.begin(), b.end());
    int s = b[0];
    for(int i=1;i<=k;i++){
        s -= a[i];
        pos.push_back(s);
    }

    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    int ans = 0;
    for(auto x : pos){
        vector<int> cur;
        int aux = x;
        for(int i=1;i<=k;i++){
            aux += a[i];
            cur.push_back(aux);
        }
        sort(cur.begin(), cur.end());
        int p = 0;
        for(auto &x : cur){
            if(p < b.size() && b[p] == x) p++; 
        }
        if(p == b.size()) ans++;
    }
    cout << ans << "\n";
}
