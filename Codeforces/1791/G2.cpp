#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<pair<int,int>> minc;
        vector<int> val;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            minc.push_back({min(i+1+aux, n-i+aux), i}); // min from 0 and n+1
            val.push_back(i+1+aux); //from 0
        }
        sort(minc.begin(), minc.end());
        vector<ll> ps(n+2,0);
        vector<int> pos(n);
        int ans = 0;
        for(int i=1;i<=n;i++){
            ps[i] = ps[i-1] + minc[i-1].first;
            pos[minc[i-1].second] = i; //pos in ps
        }
        ps[n+1] = ps[n] + (int)1e9+1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            ll sum = val[i];
            if(sum > c) continue;
            cnt++;
            if(sum == c){
                ans = max(ans, 1);
                continue;
            }
            int posc = lower_bound(ps.begin(), ps.end(), c - sum) - ps.begin();
            if(ps[posc] != (c - sum)) {posc--; }
            if(posc >= pos[i]){
                sum -= minc[pos[i]-1].first;
                cnt = 0;
                posc = lower_bound(ps.begin(), ps.end(), c - sum) - ps.begin();
                if(ps[posc] != (c - sum)) posc--;
            }
            cnt += posc;
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
}
