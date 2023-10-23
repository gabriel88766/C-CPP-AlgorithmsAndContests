#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> v = {0};
void makeNum(ll curn, int p10, int qt){
    if(p10 == qt){
        v.push_back(curn);
        return;
    }
    if(p10 == 0){
        for(int i=1;i<=9;i++) makeNum(i, 1, qt);
    }else{
        for(int i=0;i<(curn%10);i++) makeNum(10*curn+i, p10+1, qt);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=10;i++){
        makeNum(0, 0, i);
    }
    int k;
    cin >> k;
    cout << v[k] << "\n";
}
