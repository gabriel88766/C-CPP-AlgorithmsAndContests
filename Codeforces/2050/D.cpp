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
        string s;
        cin >> s;
        int n = s.size();
        deque<int> aux;
        for(int i=0;i<n;i++) aux.push_back(i);
        for(int i=0;i<n;i++){
            int bi = 0, bn = -1;
            for(int j=0;j<min(9, (int)(aux.size())); j++){
                int cn = s[aux[j]] - '0' - j;
                if(cn > bn){
                    bn = cn;
                    bi = j;
                }
            }
            cout << bn;
            for(int j=bi-1;j>=0;j--){
                swap(aux[j], aux[j+1]);
            }
            aux.pop_front();
        }
        cout << "\n";
    }
}
