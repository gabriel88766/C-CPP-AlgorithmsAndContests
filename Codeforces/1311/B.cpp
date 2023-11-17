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
        int n, m;
        cin >> n >> m;
        vector<int> v(n+1), p;
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        for(int i=0;i<m;i++){
            int a;
            cin >> a;
            p.push_back(a);
        }
        sort(p.begin(), p.end());
        int p1 = 0;
        while(p1 < m){
            int p2 = p1;
            while(p2+1 < m &&  p[p2] + 1 == p[p2+1]) p2++;
            sort(v.begin() + p[p1], v.begin() + p[p2] + 2);
            //cout << p[p1] << " " << p[p2] << " - ";
            p1 = p2 = p2 + 1;
        }
        auto x = v;
        sort(x.begin(), x.end());
        if(x == v) cout << "YES\n";
        else cout << "NO\n";
    }
}
