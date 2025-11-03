#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> an(n);
        vector<int> pos(n-1);
        iota(pos.begin(), pos.end(), 1);
        iota(an.begin(), an.end(), 1);
        int cb = 0;
        while(an.size() > 1){
            vector<int> an1, an0;
            vector<int> p1, p0;
            for(auto x : an){
                if(x & (1 << cb)) an1.push_back(x);
                else an0.push_back(x);
            }
            for(auto x : pos){
                if(query(x, 1 << cb)) p1.push_back(x);
                else p0.push_back(x);
            }
            if(p1.size() == an1.size()){
                pos = p0;
                an = an0;
            }else{
                pos = p1;
                an = an1;
            }
            cb++;
        }
        cout << "! " << an[0] << "\n";
        cout.flush();
    }
}
