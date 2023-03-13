#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

set<int> rem;
ll K;

bitset<100005> bs[51];

int test(){
    bs[0][0] = 1;
    for(int i=1;i<50;i++){
        for(auto x : rem){
            bs[i] |= (bs[i-1] << x) & bs[50]; 
            bs[i] |= (bs[i-1] >> (K-x)) & bs[50];
        }
        if(bs[i][0]) break;
    }
    for(int i=1;i<50;i++){
        if(bs[i][0]) return i;
    }
    return 51;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> K;
    int cur = 1;
    for(int i=0;i<K;i++) bs[50][i] = 1;
    while(!rem.count(cur)){
        rem.insert(cur);
        cur = (cur * 10) % K;
    }
    cout << test(); //~O(K^2/64)
}
