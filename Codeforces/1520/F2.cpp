#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N =1e4+3;
const int blk = 20;
int ps[N];

int query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int sz;
    for(int i=1;i<=n;i+=20){
        // 1 - 20, 21 - 40, ...
        auto qt = min(i+19, n) - i + 1;
        auto ans = qt - query(i, min(i + 19, n));
        ps[i/20 + 1] = ps[i/20] + ans;
        if(i + 20 > n) sz = i/20 + 1;
    }
    for(int i=1;i<=t;i++){
        //do test i
        int lo = 0, hi = sz;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            if(ps[mid] < k) lo = mid+1;
            else hi = mid;
        }
        assert(lo > 0);
        int qt = ps[lo - 1];
        k -= qt;
        int bl = lo;
        lo = (lo-1)*20 + 1;
        hi = min(lo + 19, n);
        int bg = lo;
        while(lo != hi){
            int m = lo + (hi - lo)/2;
            auto ans = (m - bg + 1 ) - query(bg, m);
            if(ans < k) lo = m + 1;
            else hi = m;
        }
        cout << "! " << lo << "\n";
        cout.flush();
        //update ps
        for(int j=bl;j<=sz;j++){
            ps[j]--;
        }
        //read test i+1
        if(i != t) cin >> k;
    }
    
}
