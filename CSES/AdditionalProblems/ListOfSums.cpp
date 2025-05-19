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
    cin >> n;
    vector<int> sm;
    for(int i=1;i<=(n*(n-1))/2;i++){
        int x;
        cin >> x;
        sm.push_back(x);
    }
    sort(sm.begin(), sm.end());
    auto test = [&](int val){
        vector<int> ans = {val};
        multiset<ll> as; //O(n^2 log n)
        for(auto &x : sm) as.insert(x);
        while(as.size()){
            bool ok = true;
            int ne = *as.begin() - ans[0];
            for(int i=0;i<ans.size();i++){
                if(as.count(ans[i] + ne)) as.erase(as.find(ans[i] + ne));
                else{
                    ok = false;
                    break;
                }
            }
            if(!ok){
                ans.clear();
                break;
            }else ans.push_back(ne);
        }
        return ans;
    };
    
    for(int i=2;;i++){ //at most n-3 sums less than a2 + a3 
        ll a = sm[0]; //a1 + a2
        ll b = sm[1]; //a1 + a3;
        ll c = sm[i]; //a2 + a3;
        assert(a + b > c); //else something is really wrong!!1
        ll fe = a + b - c;
        if(fe % 2) continue;
        fe /= 2;
        auto ans = test(fe);
        if(ans.size() == n){
            for(auto &x : ans) cout << x << " ";
            cout << "\n";
            break;
        }
    }
}
