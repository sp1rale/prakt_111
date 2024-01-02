#include <iostream>
#include <string>

class StringIntersection {
private:
    std::string str;

public:
    StringIntersection(const std::string& s) : str(s) {}

    std::string operator*(const StringIntersection& other) const {
        std::string result;

        for (char ch : str) {
            if (other.str.find(ch) != std::string::npos) {
                result += ch;
            }
        }

        return result;
    }

    void display() const {
        std::cout << str;
    }
};

int main() {
    std::string input1, input2;

    std::cout << "Enter the first string: ";
    std::cin >> input1;
    StringIntersection str1(input1);

    std::cout << "Enter the second string: ";
    std::cin >> input2;
    StringIntersection str2(input2);

    char choice;

    std::cout << "Choose an operation (* for intersection): ";
    std::cin >> choice;

    std::string result;

    if (choice == '*') {
        result = str1 * str2;
        std::cout << "Intersection of strings: ";
        for (char ch : result) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    else {
        std::cerr << "Error: Invalid operation." << std::endl;
        return 1;
    }

    return 0;
}
