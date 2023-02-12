#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string aux[] = {"RGB", "RBG", "BGR", "BRG", "GBR", "GRB"};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    string s;
    cin >> n >> s;
    vector<string> pos(6);
    vector<int> diff(6, 0);
    //init
    for(int i=0;i<6;i++){
        for(int j=0;j<100000;j++){
            pos[i] += aux[i];
        }
    }
    int minv = 2e5+3, mini;
    for(int i=0;i<6;i++){
        int cur = 0;
        for(int j=0;j<n;j++){
            if(pos[i][j] != s[j]) cur++;
        }
        if(cur < minv){
            minv = cur;
            mini = i;
        }
    }
    cout << minv << "\n";
    for(int i=0;i<n;i++){
        cout << pos[mini][i];
    }

}
