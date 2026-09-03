#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double val[1'000'005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> mx(n+1, -1); //max allowed.
    int cnt = 0;
    int lx = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == 'o') cnt++;
        if(cnt > k){
            while(cnt > k){
                lx++;
                if(s[lx] == 'o') cnt--;
            }
        }
        if(cnt == k){
            while(s[lx + 1] == 'x') lx++;
            mx[i] = lx;
        }
    }
    double lo = 0, hi = 1;
    while(hi - lo > 1e-7){
        double mid = (hi + lo)/2;
        double mn = 1e30;
        val[0] = 0;
        int pt = 0;
        bool ok = false;
        for(int i=1;i<=n;i++){
            val[i] = val[i-1] - mid;
            if(s[i] == 'o') val[i] += 1;
            while(pt <= mx[i]){
                mn = min(mn, val[pt++]);
            }
            if(val[i] >= mn){
                ok = true;
                break;
            }
        }
        if(ok) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(10) << lo << "\n";
}
