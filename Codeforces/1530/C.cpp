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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int lo = 0, hi = 4*n;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            int tt = n + mid;
            int nd = tt - tt/4;
            vector<int> ca(101, 0), cb(101, 0);
            cb[0] = mid;
            ca[100] = mid;
            for(auto x : a) ca[x]++;
            for(auto x : b) cb[x]++;
            int cca = 0, pa = 0, ccb = 0, pb = 0;
            for(int j=100;j>=0;j--){
                if(cca + ca[j] >= nd){
                    int cur = nd - cca;
                    pa += cur * j;
                    cca += cur;
                }else{
                    pa += ca[j] * j;
                    cca += ca[j];
                }
                if(ccb + cb[j] >= nd){
                    int cur = nd - ccb;
                    pb += cur * j;
                    ccb += cur;
                }else{
                    pb += cb[j] * j;
                    ccb += cb[j];
                }
            }
            if(pa >= pb) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
