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
        vector<int> a(n-1);
        deque<int> b(m);
        int kv;
        for(int i=0;i<n;i++){
            if(i == 0) cin >> kv;
            else cin >> a[i-1];
        }
        sort(a.begin(), a.end(), greater<int>());
        for(int i=0;i<n-1;i++){
            if(a[i] <= kv) {
                a.resize(i);
                break;
            }
        }
        for(int i=0;i<m;i++) cin >> b[i];
        sort(b.begin(), b.end());
        while(b.size() && b[0] <= kv) b.pop_front();
        int p0 = 0;
        int p1 = a.size();
        p1 -= 1;
        vector<pair<int,int>> va;
        if(a.size() > 0 && b.size() > 0){
            while(p0 < b.size() && p1 >= 0){
                while(p1 >= 0 && a[p1] < b[p0]) --p1;
                if(p1 < 0) break;
                int p2 = p0;
                while(p2 + 1 < b.size() && a[p1] >= b[p2+1]) p2++;
                va.push_back({p2 - p0 + 1, p1 + 1});
                p0 = p2 + 1;
            }   
        }
        int x = 0;
        vector<int> aux(m+1);
        for(auto [a, b] : va){
            for(int i=x+1;i<=x+a;i++) aux[i] = b;
            x += a;
            
        }
        for(int k=1;k<=m;k++){
            int x = m/k;
            int r = m - x*k;
            ll ans = x;
            for(int i=0;i<x;i++){
                ans += aux[r + i*k + 1];
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
 