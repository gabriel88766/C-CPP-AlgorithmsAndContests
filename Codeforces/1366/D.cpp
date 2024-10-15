#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+5;
int lp[N]; 
const int M = 5e5+3;
pair<int, int> ans[M];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!lp[i]){
            for(ll j = i; j < N; j += i){
                if(!lp[j]) lp[j] = i;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        int lf = lp[x];
        int aux = 1;
        while(!(x % lf)){
            x /= lf;
            aux *= lf;
        }
        //aux * x is original x
        if(x != 1){
            ans[i] = {aux, x};
        }else{
            ans[i] = {-1, -1};
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i].first << " ";
    cout << "\n";
    for(int i=1;i<=n;i++) cout << ans[i].second << " ";
    cout << "\n";
}
