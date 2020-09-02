#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define ll long long
using namespace std;

int gcd(int A, int B){ /* A>B */
    if(B!=0) return gcd(B,A%B);
    else return A;
}

void euclid(ll a, ll b, ll &x, ll &y, ll &d) {
  if (b) euclid(b, a%b, y, x, d), y -= x*(a/b);
  else x = 1, y = 0, d = a;
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
ll X=0,Y=0,A,B,C,D;
cin >>  A >> B >> C;
if(C%gcd(A,B)){
        cout << -1;
}else{
    if(A!=0 && B!=0){
        euclid(A,B,X,Y,D);
        ll d = -C/D;
        X*=d;
        Y*=d;
        cout << X << " " << Y;
    }
    if(A==0){
        Y=-C/B;
        cout << X << " " << Y;
    }
    if(B==0){
        X=-C/A;
        cout << X  << " "<< Y;
    }
}

}
