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
        if(n == 1) cout << "1\n";
        else if(n % 2) cout << "-1\n";
        else{
            vector<int> aux = {0};
            set<int> aux2;
            for(int i=1;i<n;i++){
                aux2.insert(i);
            } 
            for(int i=1;i<n;i++){
                if(i%2){
                    aux.push_back(*prev(aux2.end()));
                    aux2.erase(*prev(aux2.end()));
                }else{
                    aux.push_back(*aux2.begin());
                    aux2.erase(*aux2.begin());
                }
            }
            int cur = n;
            cout << cur << " ";
            for(int i=1;i<n;i++){
                int diff = aux[i] - aux[i-1];
                if(diff < 0) diff += n;
                cout << diff << " ";
            }
            cout << "\n";
        }
    }
}
