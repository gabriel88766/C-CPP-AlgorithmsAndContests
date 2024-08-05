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
        set<int> s;
        vector<int> v(n);
        for(int i=0;i<2*k;i++) s.insert(i);
        for(int i=0;i<n;i++){
            cin >> v[i];
            int l = v[i] % (2*k);
            int r = (v[i] + k - 1) % (2*k);
            if(r >= l){
                while(s.size() && *s.begin() < l) s.erase(s.begin());
                while(s.size() && *prev(s.end()) > r) s.erase(prev(s.end()));
            }else{
                //r < l
                vector<int> rml;
                for(auto it = s.upper_bound(r); it != s.end() && *it < l; ++it){
                    rml.push_back(*it);
                }
                for(auto x : rml) s.erase(x);
            }
        }
        if(s.size()){
            int mv = 0;
            for(int i=0;i<n;i++) mv = max(mv, v[i]);
            while(!s.count(mv%(2*k))) mv++;
            cout << mv << "\n";
        }else cout << "-1\n";
    }
}
