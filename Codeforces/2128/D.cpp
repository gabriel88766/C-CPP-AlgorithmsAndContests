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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int mx = 0;
        ll ans = 0;
        ll sum = 0;
        vector<int> lds;
        for(int i=1;i<=n;i++){
            if(i == 1) lds.push_back(1);
            else{
                if(lds.size() == 1){
                    if(v[lds[0]] > v[i]) lds.push_back(i);
                    else{
                        lds.pop_back();
                        lds.push_back(i);
                    }
                }else{
                    int k = lds.size();
                    if(v[lds[k-1]] > v[i]) lds.push_back(i);
                    else if(v[lds[k-2]] > v[i]){
                        lds.pop_back();
                        lds.push_back(i);
                    }
                }
            }
            sum += lds.size();
        }
        ans += sum;
        int p = 0;
        for(int i=1;i<=n;i++){
            if(p < lds.size() && lds[p] == i){
                sum -= (n - i + 1);
                p++;
            }else sum -= 1;
            ans += sum;
        }
        cout << ans << "\n";
    }
}
