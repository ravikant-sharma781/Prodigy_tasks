#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()

{
    srand((unsigned int)time(NULL));
    int number = (rand() % 100) + 1;

    int guess = 0;

    do
    {

        cout << "Enter the number: " << endl;
        cin >> guess;
        if (guess < number)
        {
            cout << "Please Enter the larger number: " << endl;
        }
        else if (guess > number)
        {
            cout << "Please Enter the smaller number: " << endl;
        }
        else
        {
            cout << "You won!";
        }
    } while (guess != number);

    return 0;
}