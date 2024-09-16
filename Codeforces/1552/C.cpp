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
        vector<bool> used(2*n+1, false);
        vector<pair<int,int>> vp;
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            if(a > b) swap(a, b);
            vp.push_back({a, b});
            used[a] = used[b] = true;
        }
        vector<int> aux;
        for(int i=1;i<=2*n;i++){
            if(!used[i]) aux.push_back(i);
        }
        int x = n-k;
        for(int i=0;i<x;i++){
            vp.push_back({aux[i], aux[i+x]});
        }
        int ans = 0;
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp.size();j++){
                if(vp[i].first > vp[j].first && vp[i].second > vp[j].second && vp[i].first < vp[j].second){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}
