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
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        vector<int> aux(n);
        int cnt = 0, cur = -1;
        for(int i=0;i<n;i++){
            if(v[i].first == cur) aux[v[i].second] = cnt;
            else{
                aux[v[i].second] = ++cnt;
                cur = v[i].first;
            }
        }
        int best = 0;
        for(int i=1;i<=n;i++){
            int p = i;
            for(int j=0;j<n;j++){
                if(aux[j] == p) ++p;
            }
            best = max(best, p-i);
        }
        cout << n-best << "\n";
    }
}
