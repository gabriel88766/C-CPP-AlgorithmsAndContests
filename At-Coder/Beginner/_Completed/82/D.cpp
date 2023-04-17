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
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    vector<int> v;
    int l = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'T'){
            v.push_back(i-l);
            l = i+1;
        }
    }
    v.push_back(s.size()-l);
    x -= v[0];
    vector<int> xm, ym;
    for(int i=1;i<v.size();i++){
        if(i%2){
            if(v[i]) ym.push_back(v[i]);
        }else if(v[i]) xm.push_back(v[i]);
    }
    bool ok = true;
    set<int> dp = {0};
    for(int i=0;i<xm.size();i++){
        set<int> newv;
        for(auto x : dp){
            newv.insert(x + xm[i]);
            newv.insert(x - xm[i]);
        }
        dp = newv;
    }
    if(!dp.count(x)) ok = false;
    dp = {0};
    for(int i=0;i<ym.size();i++){
        set<int> newv;
        for(auto x : dp){
            newv.insert(x + ym[i]);
            newv.insert(x - ym[i]);
        }
        dp = newv;
    }
    if(!dp.count(y)) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
