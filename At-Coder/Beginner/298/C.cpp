#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
set<int> contain[N];
multiset<int>  cards[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            contain[b].insert(c);
            cards[c].insert(b);
        }else if(a == 2){
            cin >> b;
            for(auto x : cards[b]) cout << x << " ";
            cout << "\n";
        }else{
            cin >> b;
            for(auto x : contain[b]) cout << x << " ";
            cout << "\n";
        }
    }
}
