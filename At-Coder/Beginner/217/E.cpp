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
    int q;
    cin >> q;
    deque<int> vn;
    multiset<int> sn;
    for(int i=1;i<=q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            vn.push_back(x);
        }else if(t == 2){
            if(sn.size()){
                cout << *sn.begin() << "\n";
                sn.erase(sn.begin());
            }else{
                cout << vn.front() << "\n";
                vn.pop_front();
            }
        }else{
            for(auto x : vn) sn.insert(x);
            vn.clear();
        }
    }
}
