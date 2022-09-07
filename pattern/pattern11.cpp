/*          1 
            0 1 
            1 0 1 
            0 1 0 1 
            1 0 1 0 1 

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(i%2 == 0 && j%2 == 0)
                cout << "1 ";
            else if(i%2 == 0 && j%2 == 1)
                cout << "0 ";
            else if(i%2 == 1 && j%2 == 0)
                cout << "0 ";
            else
                cout << "1 ";
        }cout << endl;
    }

    return 0;
}
