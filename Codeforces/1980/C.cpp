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
        int n;
        cin >> n;
        set<int> s;
        multiset<int> nd;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            if(b[i] != a[i]) nd.insert(b[i]);
            s.insert(b[i]);
        }
        int m;
        cin >> m;
        bool ok = true;
        for(int i=1;i<=m;i++){
            int x;
            cin >> x;
            auto it = nd.lower_bound(x);
            if(it != nd.end() && *it == x) nd.erase(it);
            if(i == m && !s.count(x)) ok = false;
        }
        if(nd.size()) ok = false;
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
