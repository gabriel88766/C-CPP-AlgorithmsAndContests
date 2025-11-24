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
    int n, k, a, m;
    cin >> n >> k >> a >> m;
    auto check = [&](vector<int> mv){
        //feed a sorted array
        mv.push_back(n+1);
        int lv = 0, ans = 0;
        for(auto x : mv){
            ans += (x - lv) / (a + 1);
            lv = x;
        }
        return ans;
    };
    vector<int> vx(m);
    for(int i=0;i<m;i++) cin >> vx[i];
    auto xx = vx;
    sort(xx.begin(), xx.end());
    int val = check(xx);
    if(val < k){
        int lo = 0, hi = m-1;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            vector<bool> cv(n+1, false);
            for(int i=0;i<=mid;i++) cv[vx[i]] = true;
            vector<int> rv;
            for(int i=1;i<=n;i++) if(cv[i]) rv.push_back(i);
            int cval = check(rv);
            if(cval < k) hi = mid;
            else lo = mid + 1;
        }   
        cout << lo + 1 << "\n"; 
    }else cout << "-1\n";   
}
