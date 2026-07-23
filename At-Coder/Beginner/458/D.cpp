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
    multiset<int> ml, mh;
    int x;
    cin >> x;
    ml.insert(x);
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        ml.insert(a), ml.insert(b);
        if(mh.size() == 0){ 
            mh.insert(*prev(ml.end()));
            ml.erase(prev(ml.end()));
        }else{
            while(*prev(ml.end()) > *mh.begin()){
                mh.insert(*prev(ml.end()));
                ml.erase(prev(ml.end()));
            }
            while(ml.size() < mh.size() + 1){
                ml.insert(*mh.begin());
                mh.erase(mh.begin());
            }
            while(ml.size() > mh.size() + 1){
                mh.insert(*prev(ml.end()));
                ml.erase(prev(ml.end()));
            }
        }
        cout << *prev(ml.end()) << endl;
    }
}
