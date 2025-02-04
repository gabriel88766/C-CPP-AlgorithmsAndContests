#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> cur;
int n, m;
void gen_all(){
    if(cur.size() == n){
        for(auto &x: cur) cout << x << " ";
        cout << "\n";
        return;
    }
    int fs = cur.size() ? cur.back() + 1 : 1;
    for(int i=fs;i<=m;i++){
        cur.push_back(i);
        gen_all();
        cur.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m;
    gen_all();
}
