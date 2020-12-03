#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int main(){
    long long int n;
    long long int Sum;
    int cont=0;
    vector<char> is(N,false);
    cin >> n;
    Sum = (n*(n+1))/2;
    if(Sum%2){
        cout << "NO";
    }else{
        cout << "YES" << endl;
        Sum/=2;
        int cur= n;
        while(Sum!=0){
            if(cur>=Sum){
                is[Sum]=true;
                Sum=0;
                cont++;
            }else{
                is[cur]=true;
                cont++;
                Sum-=cur--;
            }
        }
        cout << n-cont<< endl;
        for(int i=1;i<=n;i++){
            if(!is[i]) cout << i << " ";
        }
        cout << endl;
        cout << cont<< endl;
        for(int i=1;i<=n;i++){
            if(is[i]) cout << i << " ";
        }
    }


}
