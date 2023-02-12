#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// a and b index to sort
int cnt = 0;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        cout << v[i];
        if(i != (n-1)) cout << " ";
        else cout << "\n";
    }
    for(int i=1;i<n;i++){
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
        //print
        for(j = 0; j<n;j++){
            cout << v[j];
            if(j != (n-1)) cout << " ";
            else cout << "\n";
        }
    }
}