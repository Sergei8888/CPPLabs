#include <iostream>
#include <string>

class MyVectorBool {
private:
    static const int baseVectorSize = 100;
    bool boolVector[baseVectorSize]{};
public:
    explicit MyVectorBool(int n) {
        if (n < 0) {
            std::throw_with_nested(new std::invalid_argument("N can not be below zero"));
        }

        // n to binary and save it to the end of boolVector and reverse
        int i = baseVectorSize - 1;
        while (n > 0) {
            this->boolVector[i] = n % 2;
            n /= 2;
            i--;
        }

    }

    // Overload assignment operator
    MyVectorBool &operator=(const MyVectorBool &vector) {
        for (int i = 0; i < baseVectorSize; i++) {
            this->boolVector[i] = vector.boolVector[i];
        }
        return *this;
    }

    // Overload print operator
    friend std::ostream &operator<<(std::ostream &os, const MyVectorBool &vector) {
        bool isZero = true;
        for (bool i: vector.boolVector) {
            if (i == 1) {
                isZero = false;
            }
            if (!isZero) {
                os << i;
            }
        }
        return os;
    }

    void addStart(bool k) {
        for (int i = 0; i < baseVectorSize - 1; i++) {
            if (boolVector[i] == 1) {
                boolVector[i - 1] = k;
                return;
            }
        }
    }

    void addEnd(bool k) {
        // Shift vector to left
        for (int i = 0; i < baseVectorSize - 1; i++) {
            boolVector[i] = boolVector[i + 1];
        }
        boolVector[baseVectorSize - 1] = k;
    }

    int size() {
        int size = 0;
        bool countingStated = false;
        for (bool i: boolVector) {
            if (i == 1) {
                countingStated = true;
            }

            if (countingStated) {
                size++;
            }
        }
        return size;
    }

    void erase(int i) {
        for (int j = 0; j < baseVectorSize - 1; j++) {
            if (boolVector[j] == 1) {
                boolVector[j + i] = false;
                return;
            }
        }
    }

    // Sum two boolVectors as binary numbers to one boolVector
    MyVectorBool operator+(MyVectorBool &vector) {
        MyVectorBool resultVector = MyVectorBool(0);
        int carry = 0;
        for (int i = baseVectorSize - 1; i > 0; i--) {
            int sum = this->boolVector[i] + vector.boolVector[i] + carry;
            if (sum == 0) {
                resultVector.boolVector[i] = 0;
                carry = 0;
            } else if (sum == 1) {
                resultVector.boolVector[i] = 1;
                carry = 0;
            } else if (sum == 2) {
                resultVector.boolVector[i] = 0;
                carry = 1;
            } else if (sum == 3) {
                resultVector.boolVector[i] = 1;
                carry = 1;
            }
        }
        return resultVector;
    }

    // Overload [] operator
    bool &operator[](int i) {
        for (int j = 0; j < baseVectorSize - 1; j++) {
            if (boolVector[j] == 1) {
                return boolVector[j + i];
            }
        }

        std::throw_with_nested(new std::invalid_argument("Index out of range"));
    }

    
};

int main() {
    bool k = true;
    bool m = false;

    auto a = MyVectorBool(8);
    auto b = MyVectorBool(3);

    a.addStart(k);
    b.addEnd(m);

    auto c = a + b;
    auto d = b + b;

    int i;
    std::cin >> i;

    c[i] = !c[i];
    c.erase(i);

    for (int j = 0; j <= b.size(); j++) {
        std::cout << "Hello world" << std::endl;
    }
    return 0;
}
