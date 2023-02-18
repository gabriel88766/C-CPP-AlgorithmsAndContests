#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int qt[101];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        qt[aux%k]++;
    }
    int ans = 0;
    for(int i=0;i<=k/2;i++){
        if(i == 0){
            ans += qt[0]/2;
            continue;
        }
        if(i == (k-i)){
            ans += qt[i]/2;
        }else{
            ans += min(qt[i], qt[k-i]);
        }
    }
    cout << 2*ans;
}
