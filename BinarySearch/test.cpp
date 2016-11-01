#include <iostream>
#include <functional>
using namespace std;

int f(int a, int b) {
    return a+b;
}

int main() {
    int(*p)(int, int) = f;
    cout << (void*)p << ' ' << (void*)&f << endl;
    return 0;
}
