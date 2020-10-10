#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;

long long int pow(int n){
long long int S=1;
while(n){
    n--;
    S*=2;
}
return S;
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
long long int n,S,cont=0,k;
cin >> k;
while(k){
    cont = 0;
    cin >> n;
    S = n*(n+1)/2;
    while(n){
        n/=2;
        S-=2*pow(cont);
        cont++;
    }
    cout << S<<endl;
    k--;
}
}

