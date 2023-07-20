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
        int n, m, q;
        cin >> n >> m;
        vector<pair<int,int>> vs(m);
        for(int i=0;i<m;i++){
            cin >> vs[i].first >> vs[i].second;
        }
        cin >> q;
        vector<int> vq(q);
        for(int i=0;i<q;i++){
            cin >> vq[i];
        }
        //input taken
        int lo = 1, hi = q+1, mid;
        while(lo != hi){
            mid = lo+(hi-lo)/2;
            bool ok = false;
            //check if at least 1 segment is beautiful
            vector<int> ps(n+1, 0);
            for(int i=0;i<mid;i++){
                ps[vq[i]]++;
            }
            for(int i=2;i<=n;i++) ps[i] += ps[i-1]; 
            for(int i=0;i<m;i++){
                int qt = ps[vs[i].second] - ps[vs[i].first-1];
                if(2*qt > (vs[i].second - vs[i].first + 1)) ok = true;
            }
            if(ok) hi = mid;
            else lo = mid+1;
        }
        if(lo <= q) cout << lo << "\n";
        else cout << "-1\n";
        
    }
}   
