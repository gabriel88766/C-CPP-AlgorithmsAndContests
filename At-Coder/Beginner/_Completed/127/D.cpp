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
    multiset<ll> v;
    map<int,int> mp;
    set<pair<int,int>> st;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.insert(x);
    }
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        mp[b] += a;
    }
    
    for(auto x : mp) st.insert({x.first, x.second});
    auto it = st.end();
    do{
        --it;
        auto x = *it;
        for(int i=0;i<x.second;i++){
            if(x.first <= *v.begin()) break;
            v.erase(v.begin());
            v.insert(x.first);
        }
    }while(it != st.begin());
    ll sum = 0;
    for(auto x : v){
        sum += x;
    }
    cout << sum;
}
