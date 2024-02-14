#include <iostream>

using namespace std;

int main(){

    int *n_ptr1,n_ptr2,num1,num2;

    num1 = 1;
    num2 = 2;

    n_ptr1 = &num1;
    n_ptr1 = &num2;

    cout << num1 << endl << num2 << endl << n_ptr1 << endl << n_ptr2;

    return 0;
}