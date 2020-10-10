
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+3;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int aux,n,pos1;
long long int S=0;
string s;
int v[N];
cin >> n;
for(int i=1;i<=n;i++){
    cin >> aux;
    v[aux] = i;
}
for(int i=1;i<n;i++){
    S+=abs(v[i+1]-v[i]);
}
cout << S;

}
