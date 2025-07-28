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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<tuple<char,int,char,int>> op;
        vector<pair<int, int>> mt;
        vector<int> l(n+1);
        for(int i=0;i<n;i++){
            char o1, o2;
            int p1, p2;
            cin >> o1 >> p1 >> o2 >> p2;
            op.push_back({o1, p1, o2, p2});
            int m1 = 1, m2 = 1;
            if(o1 == 'x') m1 = p1;
            if(o2 == 'x') m2 = p2;
            mt.push_back({m1, m2});
        }
        l[n-1] = 1;
        for(int i=n-1;i>0;i--){
            if(mt[i].first == mt[i].second) l[i-1] = l[i];
            else{
                if(mt[i].first > mt[i].second) l[i-1] = 1;
                else l[i-1] = 2;
            }
        }
        ll m1 = 1, m2 = 1;
        for(int i=0;i<n;i++){
            auto [a, b, c, d] = op[i];
            ll ep = 0;
            if(a == '+') ep += b;
            else ep += (b-1)*m1;
            if(c == '+') ep += d;
            else ep += (d-1)*m2;
            if(l[i] == 1) m1 += ep;
            else m2 += ep;
        }
        cout << m1 + m2 << "\n";
    }
}
