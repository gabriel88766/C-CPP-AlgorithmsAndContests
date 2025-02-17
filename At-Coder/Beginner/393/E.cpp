#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int cnt[N], hit[N], v[2*N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k, n;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    for(int i=1;i<N;i++){
        for(int j=2*i;j<N;j+=i) cnt[i] += cnt[j];
        if(cnt[i] >= k){
            for(int j=i;j<N;j+=i){
                hit[j] = i; 
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << hit[v[i]] << "\n";
    }
}
