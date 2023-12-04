#pragma GCC optimize("O2")
#include <iostream>

using namespace std;

int main()
{
   long long cnt = 0;
   for (long long i = 0; i < 1e10; ++i)
       cnt += i;

   cout << cnt;
   return 0;
}