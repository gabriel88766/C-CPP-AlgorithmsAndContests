#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<6000005> bs, cbs;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int lo = 1, hi = n+1;
    while(lo != hi){
        int mid = lo + (hi - lo)/2;
        int x = 0;
        vector<int> vx;
        for(int i=0;i<mid;i++){
            x = (x * 10) % n;
            x = (x + 1) % n;
            vx.push_back(x);
        }
        //check if you can sum it 
    }
}
