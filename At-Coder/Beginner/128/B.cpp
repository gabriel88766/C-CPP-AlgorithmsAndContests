#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool cmp(pair<pair<string, int>, int> u, pair<pair<string, int>, int> v){
    if(u.first.first == v.first.first) return u.first.second > v.first.second;
    else return u.first.first < v.first.first;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<pair<pair<string, int>, int>> vp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        int x;
        cin >> s >> x;
        vp.push_back({{s, x}, i+1});
    }
    sort(vp.begin(), vp.end(), cmp);
    for(int i=0;i<n;i++){
        cout << vp[i].second << "\n";
    }
}
