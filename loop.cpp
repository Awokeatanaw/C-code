#include <iostream>
using namespace std;

string getEnglishRepresentation(int num) {
    string numWords[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return numWords[num];
}

int main() {
    int start, end;
    cin >> start >> end;
    
    for (int i = start; i <= end; i++) {
        if (i >= 1 && i <= 9) {
            cout << getEnglishRepresentation(i) << endl;
        } else if (i % 2 == 0) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }
    
    return 0;
}
