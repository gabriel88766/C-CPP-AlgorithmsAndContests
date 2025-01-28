#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+1;
int ord[N];
ll ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        ord[v[i]] = i+1;
    } 
    for(int i=1;i<N;i++){
        ll tn = 0, sx = 0, S = 0, ln = -1;
        for(int j=i;j<N;j+=i){
            if(ord[j]){
                if(ln == -1){
                    ln = ord[j];
                    tn = 1;
                }else{
                    sx += tn * (ord[j] - ln);
                    S += sx;
                    tn++;
                    ln = ord[j];
                }
            }
        }
        S -= (tn * (tn - 1))/2;
        ans[i] = S;
    }
    //inclusion exclusion
    for(int i=N-1;i>=1;i--){
        for(int j=2*i;j<N;j+=i){
            ans[i] -= ans[j];
        }
    }
    cout << ans[1] << "\n";
}
