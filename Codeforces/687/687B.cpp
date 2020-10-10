#include <bits/stdc++.h>

using namespace std;

long long int lcm(long long int a,long long int b){
    return (a*b)/gcd(a,b);
}

long long int gcd(long long int a,long long int b){
    if(b) return gcd(b,a%b);
    else return a;
}


int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
long long int n,aux,k,curlcd=1;
cin >> n >> k;
while(n--){
    cin >> aux;
    curlcd = gcd(lcm(curlcd,aux),k);
}
if(curlcd == k) cout << "Yes";
else cout << "No";
}
