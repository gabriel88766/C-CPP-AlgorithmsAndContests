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
        int val = -1, cnt = 0, maxcnt = 0, num = -1, dif = 0;
        for(int i=0;i<n;i++){
            if(val != v[i]){
                val = v[i];
                cnt = 1;
                dif++;
            }else cnt++;
            if(cnt > maxcnt){
                maxcnt = cnt;
                num = val;
            }
        }
        //opt1, dif-1 and maxcnt
        //opt2, dif and maxcnt-1;
        cout << max(min(dif-1, maxcnt), min(dif, maxcnt-1)) << "\n";
        
    }
}
