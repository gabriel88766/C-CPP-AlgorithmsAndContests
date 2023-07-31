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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        if(v[0] == v[n-1]){
            int cnt = 0;
            for(int i=0;i<n;i++) if(v[i] == v[0]) cnt++;
            if(cnt >= k) cout << "YES\n";
            else cout << "NO\n";
        }else{
            int cnt = 0, il = -1, ir = -1;
            for(int i=0;i<n;i++){
                if(v[i] == v[0]){
                    cnt++;
                    if(cnt == k) il = i;
                }
            }
            cnt = 0;
            for(int i=n-1;i>=0;i--){
                if(v[i] == v[n-1]){
                    cnt++;
                    if(cnt == k) ir = i;
                }
            }
            if(il != -1 && ir != -1 && ir > il) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
