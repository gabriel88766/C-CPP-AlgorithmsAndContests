#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7, MOD2 = 2e9+11;
const int N = 1e5+5;
//vector<vector<int>> matrix(row,vector<int>(col));
// cout << std::setprecision(10) << std::fixed << variableLD;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long int i,aux,n,S1,S2,Smin=INF,cur;
    vector<int> v;
    cin >> n;
    int maxint= 1 << n;
    for(i=0;i<n;i++){
        cin >> aux;
        v.push_back(aux);
    }
    for(i=0;i<maxint;i++){
        S1=0;
        S2=0;
        for(int j=0;j<n;j++){
            if(i& (1<<j)) S1+=v[j];
            else S2+=v[j];
        }
        cur = S1-S2;
        if(cur<0) cur=-cur;
        if(cur<Smin) Smin=cur;
    }
    cout << Smin;
  return 0;
}

