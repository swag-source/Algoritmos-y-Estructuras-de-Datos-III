#include <iostream>
#include <string>

bool areEqual(std::string a, std::string b) {
    if (a.length() == 1 && b.length() == 1) {
        return a == b;
    } else {
        if (a.length() % 2 == 0) {
            int mid = a.length() / 2;
            std::string a1 = a.substr(0, mid);
            std::string a2 = a.substr(mid);
            std::string b1 = b.substr(0, mid);
            std::string b2 = b.substr(mid);
            return (areEqual(a1, b2) && areEqual(a2, b1)) || (areEqual(a1, b1) && areEqual(a2, b2));
        } else {
            return a == b;
        }
    }
}

int main() {
    std::string palabra1, palabra2;
    std::cin >> palabra1 >> palabra2;

    if (palabra1 == palabra2 || areEqual(palabra1, palabra2)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
