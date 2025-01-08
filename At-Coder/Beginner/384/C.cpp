#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<string> v;
void genAll(string cs = "", char cl = 'A'){
    if(cl == 'F'){
        if(cs != "") v.push_back(cs);
        return;
    }
    genAll(cs + cl, cl+1);
    genAll(cs, cl+1);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    genAll();
    vector<int> pt(5);
    for(int i=0;i<5;i++) cin >> pt[i];
    sort(v.begin(), v.end(), [&](string &a, string &b){
        int pa = 0, pb = 0;
        for(auto c : a) pa += pt[c-'A'];
        for(auto c : b) pb += pt[c-'A'];
        if(pa != pb) return pa > pb;
        else return a < b;
    });
    for(auto x : v) cout << x << "\n";
}
