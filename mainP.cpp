#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
    cout << "=== Stack<int> depuis la DLL ===" << endl;
    Stack<int> s;
    for (int i = 1; i <= 10; i++) {
        s.push(i * 10);
        cout << "push " << i * 10
             << " | taille = " << s.getSize()
             << " | capacite = " << s.getCapacity() << endl;
    }
    cout << "Sommet : " << s.top() << endl;
    while (!s.isEmpty()) {
        cout << "pop -> " << s.pop()
             << " | taille = " << s.getSize()
             << " | capacite = " << s.getCapacity() << endl;
    }

    cout << "\n=== Stack<string> depuis la DLL ===" << endl;
    Stack<string> t;
    t.push("bonjour");
    t.push("le");
    t.push("monde");
    while (!t.isEmpty()) cout << "pop -> " << t.pop() << endl;

    cout << "\n=== Stack<double> depuis la DLL ===" << endl;
    Stack<double> d;
    d.push(3.14);
    d.push(2.71);
    cout << "Sommet : " << d.top() << endl;
    cout << "pop -> " << d.pop() << endl;
    cout << "pop -> " << d.pop() << endl;

    cout << "\n=== Test pile vide ===" << endl;
    try {
        d.pop();
    } catch (const exception& e) {
        cout << "Exception : " << e.what() << endl;
    }

    cin.get();   // garde la fenêtre ouverte
    return 0;
}
