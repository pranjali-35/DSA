/*              1 
                2 2 
                3 3 3 
                4 4 4 4
                5 5 5 5 5

*/ 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 0 ; j < i ; j++)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
