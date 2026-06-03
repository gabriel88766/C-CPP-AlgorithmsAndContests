#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<1'000'000'000> bs;
vector<string> vs;
vector<int> alln;
void concatall(string s){
    if(s.size() >= 10) return;
    if(s != ""){
        int cn = stoi(s);
        if(!bs[cn]){
            bs[cn] = true;
            alln.push_back(cn);
        }
    }
    for(auto cs : vs){
        concatall(s + cs);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;(1 << i) < 1e9; i++){
        vs.push_back(to_string(1 << i));
    }
    concatall("");
    sort(alln.begin(), alln.end());
    int n;
    cin >> n;
    cout << alln[n-1] << "\n";
}
