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
    int n;
    ll ans = 0;
    cin >> n;
    int grodd = -INF_INT;
    vector<int> odd;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        if(aux % 2){
            odd.push_back(aux);
        }else{
            if(aux >= 0) ans += aux;
        }
    }
    sort(odd.begin(), odd.end(), greater<int>());
    int cnt = 0;
    for(int i=0;i<odd.size();i++){
        if(odd[i] > 0){
            cnt++;
            ans += odd[i];
        }else break;
    }
    if(cnt == 0) ans = ans + odd[0];
    else if(!(cnt % 2)){
        if(cnt != odd.size()) ans = max(ans - odd[cnt-1], ans + odd[cnt]);
        else ans = ans - odd[cnt-1];
    }
    cout << ans << "\n";
}
