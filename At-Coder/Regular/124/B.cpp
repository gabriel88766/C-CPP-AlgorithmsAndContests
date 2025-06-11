#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //test it all
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<int> ps;
    for(int i=0;i<n;i++){
        ps.push_back(a[0] ^ b[i]);
    }
    sort(ps.begin(), ps.end());
    ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
    sort(b.begin(), b.end());
    vector<int> ans;
    for(auto &x : ps){
        vector<int> cv;
        for(int j=0;j<n;j++){
            cv.push_back(a[j]^x);
        }
        sort(cv.begin(), cv.end());
        if(cv == b) ans.push_back(x);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << "\n";

}
