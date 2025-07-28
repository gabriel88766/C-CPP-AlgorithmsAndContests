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
    vector<tuple<int, int, int>> vt(n);
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        vt[i] = {a, b, i};
    }
    sort(vt.begin(), vt.end());
    vector<pair<int, int>> tst = {{0, n-1}, {1, n-1}, {0, n-2}};
    multiset<tuple<int, int, int>> ms;
    for(auto [a, b] : tst){
        int i1 = get<2>(vt[a]);
        int i2 = get<2>(vt[b]);
        int val = get<0>(vt[b]) - get<0>(vt[a]);
        ms.insert({val, min(i1, i2), max(i1, i2)});
    }
    sort(vt.begin(), vt.end(), [](tuple<int, int, int> a, tuple<int, int, int> b){
        if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        else if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        else return get<2>(a) < get<2>(b);
    });
    for(auto [a, b] : tst){
        int i1 = get<2>(vt[a]);
        int i2 = get<2>(vt[b]);
        int val = get<1>(vt[b]) - get<1>(vt[a]);
        ms.insert({val, min(i1, i2), max(i1, i2)});
    }
    pair<int, int> gr = {get<1>(*prev(ms.end())), get<2>(*prev(ms.end()))};
    ms.erase(prev(ms.end()));
    while(get<1>(*prev(ms.end())) == gr.first && get<2>(*prev(ms.end())) == gr.second) ms.erase(prev(ms.end()));
    cout << get<0>(*prev(ms.end())) << "\n";
}
