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
    int n, k, m;
    cin >> n >> k >> m;
    vector<pair<int, int>> vx(n);
    vector<int> vx2;
    set<int> rem;
    for(int i=0;i<n;i++){
        cin >> vx[i].second >> vx[i].first;
    }
    ll ans = 0;
    sort(vx.begin(), vx.end(), greater<pair<int, int>>());
    int cnt = 0;
    for(auto [val, idx] : vx){
        if(!rem.count(idx) && cnt < m){
            rem.insert(idx);
            cnt++;
            ans += val;
        }else{
            vx2.push_back(val);
        }
    }
    reverse(vx2.begin(), vx2.end());
    while(cnt != k){
        ans += vx2.back();
        vx2.pop_back();
        cnt++;
    }
    cout << ans << "\n";
}       
