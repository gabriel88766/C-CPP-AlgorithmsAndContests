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
        int cur = 0, maxv = 0;
        vector<int> pot(31,0);
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            int aux2 = aux;
            while(!(aux2 % 2)){
                aux2 /= 2;
                cur++;
            }
            aux2 = i;
            int cnt = 0;
            while(!(aux2 % 2)){
                aux2 /= 2;
                cnt++;
            }
            pot[cnt]++;
            maxv = max(maxv,cnt);
        }
        if(cur >= n) cout << "0\n";
        else{
            int ans = 0;
            for(int i=maxv; i>= 1; i--){
                bool ok = false;
                for(int j=0;j<pot[i];j++){
                    cur += i;
                    ans++;
                    if(cur >= n){
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(cur >= n) cout << ans << "\n";
            else cout << "-1\n";
        }
    }
}
