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
    string s;
    cin >> n >> s;
    vector<char> v;
    for(auto c : s){
        v.push_back(c);
        if(v.size() >= 3){
            int r = v.size() - 1;
            if(v[r-2] == 'f' && v[r-1] == 'o' && v[r] == 'x'){
                v.pop_back();
                v.pop_back();
                v.pop_back();
            }
        }
    }
    cout << v.size() << "\n";
}
