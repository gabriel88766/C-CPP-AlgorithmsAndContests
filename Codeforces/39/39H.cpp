#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

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
int pow10[] = { 1,10,100,1000,10000};
int tobase(int base,int num){
    int result=0,cont=0;
    while(num!=0){
        result+=(pow10[cont]*(num%base));
        num/=base;
        cont++;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
  int k;
  cin >> k;
  for(int i=0;i<(k-1);i++){
    for(int j=0;j<(k-1);j++){
        cout << tobase(k,(i+1)*(j+1)) << " ";
    }
    cout << endl;
  }

  return 0;
}
