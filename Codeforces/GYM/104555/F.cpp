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
    ll d;
    int c, r;
    cin >> d >> c >> r;
    vector<int> v1, v2;
    for(int i=0;i<c;i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for(int i=0;i<r;i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    int cnt = 0;
    while(v1.size() || v2.size()){
        if(v1.size() && v1.back() <= d){
            d -= v1.back();
            v1.pop_back();
            cnt++;
        }else if(v2.size()){
            d += v2.back();
            v2.pop_back();
            cnt++;
        }else break;
    }
    cout << cnt << "\n";
}
