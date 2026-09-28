#include <iostream>
using namespace std;

int main()
{
    
    cout << "Hey! Welcome to the calculator \n Choose your operation \n 1. Addition \n 2. Subraction \n 3. Multiplication \n 4. Division" << endl;
    int operation;
    cin >> operation;
    
    int a,b;

    cout << "Enter the two digits A & B separated by space" << endl;
    cin >> a >> b;

    if (operation == 1){
        cout << "Answer is "<< a+b << endl;
    }

    else if (operation == 2) {
        cout << "Answer is " << a - b << endl;
    }

    else if (operation == 3) {
        cout << "Answer is " << a*b << endl;
    }

    else if (operation == 4) {
        if(b == 0){
            cout << "Cannot divide by Zero" << endl;
        }
        else {
            cout << "Answer is " << a/b << endl;}
    }

    else {
        cout << "Invalid Operation" << endl;
    }



    return 0;
}