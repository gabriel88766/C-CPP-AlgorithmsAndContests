#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

double inv[105][105]; //expected value, i, j

void init(){
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
           for(int k=2;k<=i;k++){
                double aux = 1/(double)i;
                aux *= (double)min((k-1), j);
                aux /= (double)j;
                inv[i][j] += aux;
           }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<int> v;
    int n;
    double ans = 0;
    init();
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    for(int i=0;i<n;i++){
        for(int j=(i+1);j<n;j++){
            ans += inv[v[i]][v[j]];
        }
    }
    cout << fixed << setprecision(6) << ans;
}
