/*Koteneva Elena*/

#include <iostream>

int Prime(unsigned long a, unsigned long i);

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

   //Task 1

    int a,b,s;
    cout << "Enter 2 integer numbers" << endl;
    cin >> a;
    cin >> b;
    s = a + b;
    if ((s <= 20) && (s >= 10)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    // Task 2

    unsigned long c;
    cout << "Enter natural number" << "\n";
    cin>>c;
    while (c < 0) {
        cout << "Enter natural number" << endl;
        cin >> c;
        }
    if (!Prime(c,2)) cout<<"Not simple number"<<"\n";
    else cout<<"Simple number"<<"\n";

    // Task 3

    const int x = 10;
    const int y = 16;

    if (((x == 10) && (y == 10)) || ((x + y) == 10)) cout << "True\n";
    else cout << "False\n";

    // Task 4

    unsigned int year;

    cout << "Enter an year" << "\n";
    cin>>year;
    while (year < 0) {
        cout << "Enter an year" << endl;
        cin >> year;
        }
    if (year % 400 == 0) cout << "Leap year\n";
    else if (year % 100 == 0) cout << "Not leap year\n";
    else if (year % 4 == 0) cout  << "Leap year\n";
    else cout << "Not Leap year\n"; 

return 0;

}

int Prime(unsigned long a, unsigned long i){
    return i*i <= a ? (a%i) && Prime(a, i + 1) : 1;
}
