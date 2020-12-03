#include <bits/stdc++.h>
using namespace std;

vector<int> powerof5;
void mkpowers(){
    long long int k=1;
    while(k<1e9){
        k*=5;
        powerof5.push_back(k);
    }

}
int main(){
mkpowers();
int n,S=0;
cin >> n;
for(int i=0;i<powerof5.size();i++){
    S+= n/powerof5[i];
}
cout << S;
}
