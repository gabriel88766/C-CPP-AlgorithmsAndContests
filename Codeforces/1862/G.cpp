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
        map<int,int> mp;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            s.insert({v[i], i});
        }
        for(auto it = s.begin(); it != s.end(); it++){
            if(it == s.begin()) continue;
            if(prev(it)->first != it->first){
                mp[it->first - prev(it)->first]++;
            }
        }
        int q;
        cin >> q;
        for(int i=0;i<q;i++){
            int a, x;
            cin >> x >> a;
            auto it = s.lower_bound({v[x], x});
            if((next(it) == s.end() || next(it)->first != v[x]) && (it == s.begin() || prev(it)->first != v[x])){
                if(next(it) != s.end()){
                    if(--mp[next(it)->first - it->first] == 0){
                        mp.erase(next(it)->first - it->first);
                    }
                }
                if(it != s.begin()){
                    if(--mp[it->first - prev(it)->first] == 0){
                        mp.erase(it->first - prev(it)->first);
                    }
                }
                if(it != s.begin() && next(it) != s.end()){
                    mp[next(it)->first - prev(it)->first]++;
                }
            }
            s.erase(it);
            v[x] = a;
            s.insert({v[x], x});
            it = s.lower_bound({v[x], x});
            if((next(it) == s.end() || next(it)->first != v[x]) && (it == s.begin() || prev(it)->first != v[x])){
                if(next(it) != s.end()){
                    mp[next(it)->first - it->first]++;
                }
                if(it != s.begin()){
                    mp[it->first - prev(it)->first]++;
                }
                if(it != s.begin() && next(it) != s.end()){
                    if(--mp[next(it)->first - prev(it)->first] == 0){
                        mp.erase(next(it)->first - prev(it)->first);
                    }
                }
            }
            int ans = prev(s.end())->first;
            if(mp.size()) ans += prev(mp.end())->first;
            cout << ans << " ";
        }
        cout << "\n";
    }
}
