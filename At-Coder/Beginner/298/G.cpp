#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n, m, t;
ll v[6][6];
pair<ll, ll> divide(int x1, int y1, int x2, int y2, int qt){
    if(qt == 0){
        ll sum = 0;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                sum += v[i][j];
            }
        }
        return make_pair(sum, sum);
    }
    if(x1 != x2){

    }
    if(y1 != y2){
        
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    auto ans = divide(0, 0, n-1, m-1, t);
}
