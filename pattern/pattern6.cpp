/*              1 2 3 4 5
                1 2 3 4 
                1 2 3 
                1 2
                1

*/ 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = n ; i > 0 ; i--){
        for(int j = i ; j > 0 ; j--)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
