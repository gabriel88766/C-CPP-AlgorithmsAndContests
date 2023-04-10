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
        k = n-k;
        vector<int> v(n);
        vector<pair<int,int>> aux;
        for(int i=0;i<n;i++){
            cin >> v[i];
            aux.push_back({v[i]-(n-i-1), i});
        }
        sort(aux.begin(), aux.end());
        ll ans = 0;
        vector<int> aux2;
        for(int i=0;i<k;i++){
            aux2.push_back(aux[i].second);
        }
        sort(aux2.begin(), aux2.end());
        for(int i=0;i<k;i++){
            ans += v[aux2[i]] + aux2[i] - i;
        }
        cout << ans << "\n";
    }
}
