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
        set<pair<int,int>> s;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            s.insert({v[i], i});
        }   
        int lv = 0, li = -1;
        int k;
        cin >> k;
        vector<int> red(n, 0);
        while(s.size()){
            auto p = *s.begin();
            if(p.first - lv <= k && p.second > li){
                if(li != -1){
                    int dif;
                    if(p.first == lv){
                        dif = red[li];
                    }else dif = min(red[li], k/(p.first - lv));
                    red[li] -= dif;
                    red[p.second] += dif;
                    k -= dif * (p.first - lv);
                    li = p.second;
                    lv = p.first;
                }else{
                    //begin
                    li = p.second;
                    red[li] = k / p.first;
                    k -= red[li] * p.first;
                    lv = p.first;
                }
            }
            s.erase(s.begin());
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans += red[i];
        for(int i=0;i<n;i++){
            cout << ans << " ";
            ans -= red[i];
        }
        cout << "\n";
    }
}
