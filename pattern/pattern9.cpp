/*                              *
                               * *
                              * * * 
                             * * * *
                            * * * * *
                            * * * * * 
                             * * * *
                              * * *
                               * *
                                *

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    n /=2;
    int n_copy = n,n_copy1 = n;
    
    for(int i = 0 ; i < n_copy ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            cout << " ";
        }for(int k = 0 ; k <=i  ; k++){
            cout << "* ";
        }n--;
        cout << endl;
    }
    for(int i = 0 ; i < n_copy ; i++){
        for(int j = 0 ; j < i ; j++){
            cout << " ";
        }for(int k = 0 ; k < n_copy1 ; k++){
            cout << "* ";
        }n_copy1--;
        cout << endl;
    }
    

    return 0;
}
