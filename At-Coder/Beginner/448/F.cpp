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
    const int X = 81633;
    int n;
    cin >> n;
    vector<tuple<int, int, int>> vp(n);
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b, i+1};
    }
    sort(vp.begin(), vp.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
        if(get<0>(a) / X != get<0>(b) / X) return get<0>(a) / X < get<0>(b) / X;
        else{
            if((get<0>(a) / X) % 2 == 0) return get<1>(a) < get<1>(b);
            else return get<1>(a) > get<1>(b);
        }
    });
    cout << "1 ";
    for(auto [a, b, c] : vp){
        if(c != 1) cout << c << " ";
    }
    cout << "\n";
}
