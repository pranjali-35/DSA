/*                              *
                               * *
                              * * *
                             * * * *
                            * * * * *

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int n_copy = n;
    for(int i = 0 ; i < n_copy ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            cout << " ";
        }for(int k = 0 ; k <=i  ; k++){
            cout << "* ";
        }n--;
        cout << endl;
    }
    

    return 0;
}
