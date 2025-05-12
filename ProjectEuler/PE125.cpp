#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 10001;
const int M = 1e8;
int sq[10001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<int> okn;
    for(int i=1;i<N;i++){
        int cs = i*i;
        for(int j=i+1;j<N;j+=1){
            cs += j*j;
            if(cs > M) break;
            string s = to_string(cs);
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(rev == s) okn.push_back(cs);
        }
    }
    sort(okn.begin(), okn.end());
    okn.resize(unique(okn.begin(), okn.end()) - okn.begin());
    ll sum = 0;
    for(auto &x : okn) sum += x;
    cout << sum << "\n";
}
