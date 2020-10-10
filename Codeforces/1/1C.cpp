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

const ld EPS = 1e-9, PI = acosl(-1.), PI2 = 2*PI;
const int INF = 0x3f3f3f3f, MOD = 1e9+7, MOD2 = 2e9+11;
const int N = 1e5+5;
//vector<vector<int>> matrix(row,vector<int>(col));


int nextInt(ld a){
    int cont=1;
    label:
    ld f = a*cont;
    int b = f;
    ld k = f-b;
    if(cont == 100) return 2;
    if((k<0.001 && k> -0.001)||(k<1.001 && k> 0.999)){
        return (f+0.5);
    }else{
        cont++;
        goto label;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
  ld a1,a2,b1,b2,c1,c2,aux,ans,r,x,y;

  pair <ld,ld> v1,v2,p1,p2;
  long double dif1,dif2;
  int t;
  int m,n;

   ld D1,D2,D3,D4,R1,R2;

  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

  v1.st = -(b2-a2);
  v1.nd = b1-a1;
  v2.st = -(c2-a2);
  v2.nd = c1-a1;
  p1.st = (a1+b1)/2;
  p1.nd = (a2+b2)/2;
  p2.st = (c1+a1)/2;
  p2.nd = (c2+a2)/2;

  R1 = p1.st-p2.st;
  R2 = p1.nd - p2.nd;
  D1 = v2.st;
  D3 = v2.nd;
  D2 = -v1.st;
  D4 = -v1.nd;


  if(D1>0.0001 || D1 < -0.0001){
       if(D3>0.0001 || D3 < -0.0001){
        ld coef = D1/D3;
        D2 -= (D4*coef);
        R1 -= (R2*coef);
        if(D2>0.0001 || D2 < -0.0001) ans = R1/D2;
        else ans = 0;
       }else{
            if(D4>0.0001 || D4< -0.0001) ans = R2/D4;
            else ans = 0;
       }
  }else{
    if(D2>0.0001 || D2 < -0.0001) ans = R1/D2;
    else ans = 0;
  }
  x = p1.st + ans*v1.st;
  y = p1.nd + ans*v1.nd;

  a1-=x;
  a2-=y;
  b1-=x;
  b2-=y;
  c1-=x;
  c2-=y;

    r = sqrtl(a1*a1+a2*a2);

     dif1 = atan2l(b2,b1) - atan2l(a2,a1);
     if(atan2l(b2,b1)< atan2l(a2,a1)) dif1=-dif1;
     if(dif1>PI) dif1 = PI2-dif1;

     dif2 = atan2l(c2,c1) - atan2l(a2,a1);
     if(atan2l(c2,c1) < atan2l(a2,a1)) dif2 = -dif2;
     if(dif2>PI) dif2 = PI2-dif2;



  m= nextInt(PI2/dif1);
  n= nextInt(PI2/dif2);



  t = (m*n)/gcd(m,n);
  ans = r*r/2*sinl((PI2/t));
  ans*=t;
  cout << std::setprecision(10) << std::fixed << ans;
  return 0;
}

