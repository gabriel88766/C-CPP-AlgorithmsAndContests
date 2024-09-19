#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char ask(int a, int b, int c, int d){
    cout << "? " << a << " " << b << " " << c << " " << d << "\n";
    cout.flush();
    char ans;
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
        if(n == 2){
            cout << "! 0 1\n";
            cout.flush();
            continue;
        }
        int gr = 0;
        for(int i=1;i<n;i++){
            char ans = ask(gr, gr, i, i);
            if(ans == '<') gr = i;
        }
        //now i know v[bi] = n-1
        vector<int> bi = {0};
        for(int i=1;i<n;i++){
            char ans = ask(gr, bi[0], gr, i);
            if(ans == '=') bi.push_back(i);
            else if(ans == '<'){
                bi = {i};
            }
        }
        //among them, find the lowest
        int lw = bi[0];
        for(int i=1;i<bi.size();i++){
            char ans = ask(lw, lw, bi[i], bi[i]);
            if(ans == '>') lw = bi[i];
        }
        cout << "! " << gr << " " << lw << "\n";
        cout.flush();
    }
}   
