#include <iostream>
using namespace std;

int main()
{
    float cel, temp, fah;
    int typ;

    cout << "Type 1: convert Fahrenheit to Celcius, \nType 2: convert celcius to Fahrenheit" << endl;
    cin >> typ;

    if (typ == 1)
    {
        cout << "Enter the temprature in Fahrenheit: " << endl;
        cin >> temp;
        cel = (temp - 32) * 5 / 9;
        cout << temp << " Fahrenheit = " << cel << " Celcius" << endl;
    }
    else
    {
        cout << "Enter the temprature in Celcius: " << endl;
        cin >> temp;
        fah = (temp * 9 / 5) + 32;
        cout << temp << " Celcius = " << fah << " Fahrenheit" << endl;
    }

    return 0;
}