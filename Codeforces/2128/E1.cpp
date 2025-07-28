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
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int lo = 1, hi = n;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            vector<int> ps(n+1);
            int mn = INF_INT;
            bool ok = false;
            for(int i=1;i<=n;i++){
                if(v[i] < mid) ps[i] = -1;
                else ps[i] = 1;
                ps[i] += ps[i-1];
                if(i >= k){
                    mn = min(mn, ps[i-k]);
                }
                if(ps[i] - mn >= 0) ok = true;
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << " ";
        vector<int> ps(n+1);
        pair<int, int> mn = {INF_INT, INF_INT};
        bool ok = false;
        for(int i=1;i<=n;i++){
            if(v[i] < lo) ps[i] = -1;
            else ps[i] = 1;
            ps[i] += ps[i-1];
            if(i >= k){
                mn = min(mn, make_pair(ps[i-k], i-k));
            }
            if(ps[i] - mn.first >= 0){
                cout << mn.second + 1 << " " << i << "\n";
                break;
            }
        }
    }
}   
