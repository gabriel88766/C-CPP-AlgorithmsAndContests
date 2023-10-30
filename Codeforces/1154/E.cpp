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
    int n, k;
    cin >> n >> k;
    set<int> s1;
    set<pair<int,int>> s2;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        s1.insert(i);
        cin >> v[i];
        s2.insert({v[i], i});
    }
    vector<int> ans(n+1);
    int p = 0;
    while(s1.size()){
        int ind = prev(s2.end())->second;
        vector<int> rml;
        auto it = s1.lower_bound(ind);
        int x = 0;
        for(int i=0;i<k;i++){
            if(it != s1.begin()) --it;
            else x++;
        }
        for(int i=0;i<=2*k-x;i++){
            if(!rml.size() || rml.back() != *it){
                ans[*it] = p+1;
                rml.push_back(*it);
            }
            if(next(it) != s1.end()) ++it;
        }
        for(auto x : rml){
            s1.erase(x);
            s2.erase({v[x], x});
        }
        p ^= 1;
    }
    for(int i=1;i<=n;i++) cout << ans[i];
}
