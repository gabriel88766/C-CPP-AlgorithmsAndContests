#include <bits/stdc++.h>

using namespace std;

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
string s;
int cont=0,prime;
for(int i=0;i<primes.size();i++){
    cout << primes[i] << endl;
    fflush(stdout);
    cin >> s;
    if(s=="yes") cont++,prime=primes[i];
}
if(cont>=2) cout << "composite";
else if(cont == 0) cout << "prime";
else{
    if(prime<10){
        cout << prime*prime << endl;
        fflush(stdout);
        cin >> s;
        if(s=="yes") cout << "composite";
        else cout << "prime";
    } else{
        cout << "prime";
    }
}

}
