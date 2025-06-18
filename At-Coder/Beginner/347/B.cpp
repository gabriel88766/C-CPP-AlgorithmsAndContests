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
    vector<string> vs;
    for(int i=0;i<s.size();i++){
        for(int j=1;i+j<=s.size();j++){
            vs.push_back(s.substr(i, j));
        }
    }
    sort(vs.begin(), vs.end());
    vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
    cout << vs.size() << "\n";
}
