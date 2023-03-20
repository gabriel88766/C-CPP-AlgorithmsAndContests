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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int lo = 0, hi = 1e9+1;
    for(int i=hi;i >= 1; i /= 2){
        while(true){
            int nxt = lo + i;
            int cnt = 1;
            int last = v[0];
            for(int i=1;i<n;i++){
                if(v[i] - last >= nxt){
                    cnt++;
                    last = v[i];
                }
            }
            if(cnt >= k) lo = nxt;
            else break;
        }
    }
    cout << lo;
}
