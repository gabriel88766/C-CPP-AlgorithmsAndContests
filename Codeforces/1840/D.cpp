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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());  
        int lo = 0, hi = 1e9+1, mid;
        while(lo != hi){
            mid = lo + (hi - lo) / 2;
            bool ok;
            int cur = 0;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(cur == 0 || (v[i] - cur) > mid){
                    cur = v[i]+mid;
                    cnt++;
                }
            }


            if(cnt <= 3){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        cout << lo << "\n";
    }
}
