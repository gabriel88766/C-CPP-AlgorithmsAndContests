#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string cur;
vector<string> av;
int n;
vector<string> inp;
void gen_all(int k, int sz = 0){
    if(sz == k){
        av.push_back(cur);
        return;
    }
    for(int i=0;i<n;i++){
        auto old = cur;
        cur += inp[i];
        gen_all(k, sz+1);
        cur = old;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k, x;
    cin >> n >> k >> x;
    inp.resize(n);
    for(int i=0;i<n;i++) cin >> inp[i];
    gen_all(k);
    sort(av.begin(), av.end());
    cout << av[x-1] << "\n";
}
