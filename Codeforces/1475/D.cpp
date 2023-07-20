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
        ll sum = 0;
        vector<ll> mem(n), il(n);
        for(int i=0;i<n;i++){
            cin >> mem[i];
            sum += mem[i];
        }
        for(int i=0;i<n;i++) cin >> il[i];
        if(sum < m) cout << "-1\n";
        else{
            //solve.
            vector<ll> m2[3], ps[3];
            for(int i=0;i<n;i++){
                if(il[i] == 1){
                    m2[1].push_back(mem[i]);
                }else{
                    m2[2].push_back(mem[i]);
                }
            }
            sort(m2[1].begin(), m2[1].end(), greater<ll>());
            sort(m2[2].begin(), m2[2].end(), greater<ll>());
            ps[1] = {0};
            ps[2] = {0};
            for(int i=0;i<m2[1].size();i++){
                ps[1].push_back(ps[1].back()+m2[1][i]);
            }
            for(int i=0;i<m2[2].size();i++){
                ps[2].push_back(ps[2].back()+m2[2][i]);
            }
            int lo = 1, hi = 2*n, mid;
            while(lo != hi){
                mid = lo+(hi-lo)/2;
                bool ok = false;
                for(int i=0;i<=m2[2].size();i++){
                    int rem = mid - 2*i;
                    if(rem < 0) break;
                    ll sum = ps[2][i];
                    sum += ps[1][min(rem, (int)m2[1].size())];
                    if(sum >= m){
                        ok = true;
                        break;
                    }
                }



                if(ok) hi = mid;
                else lo = mid+1;
            }
            cout << lo << "\n";
        }

    }
}
