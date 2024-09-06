#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[10005];
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
        vector<int> v;
        vector<int> po;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        for(auto x : v){
            cnt[x]++;
            if(!(cnt[x] % 2) && cnt[x] <= 4) po.push_back(x);
        }
        sort(po.begin(), po.end());
        pair<int,int> ans = {-1, -1};
        pair<ll, ll> bf = {INF_INT, 1};
        for(int i=1;i<po.size();i++){
            ll a = po[i];
            ll b = po[i-1];
            ll P = 2*a+2*b;
            P *= P;
            ll Q = a*b;
            if(P*bf.second < Q*bf.first){
                bf = {P, Q};
                ans = {a, b};
            }
        }   
        cout << ans.first << " " << ans.first << " " << ans.second << " " << ans.second << "\n";


        for(auto x : v){
            cnt[x]--;
        }
    }
}
