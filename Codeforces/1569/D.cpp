#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ans = 0;
void solve(vector<vector<int>> &ch, int n){
    for(int i=0;i<n;i++){
        sort(ch[i].begin(), ch[i].end());
        int p1 = 0, p2 = 0;
        while(p1 < ch[i].size()){
            while(p2+1 < ch[i].size() && ch[i][p2+1] == ch[i][p1]) p2++;
            ll sz1 = p2-p1+1;
            ll sz2 = (ll)ch[i].size() - p2 - 1;
            ans += sz1 * sz2;
            p1 = ++p2;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        vector<vector<int>> ch1(n);
        vector<vector<int>> ch2(m);
        for(int i=0;i<k;i++){
            int x, y;
            cin >> x >> y;
            auto it1 = lower_bound(a.begin(), a.end(), x);
            auto it2 = lower_bound(b.begin(), b.end(), y);
            bool ok1 = false, ok2 = false;
            if(*it1 == x) ok1 = true;
            if(*it2 == y) ok2 = true;
            if(!ok1){
                ch1[it1-a.begin()].push_back(y);
            }
            if(!ok2){
                ch2[it2-b.begin()].push_back(x);
            }
        }
        
        ans = 0;
        solve(ch1, n);
        solve(ch2, m);
        cout << ans << "\n";
    }
}
