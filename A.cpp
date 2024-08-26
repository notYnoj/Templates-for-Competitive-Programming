#include <bits/stdc++.h>
using namespace std;

// Everything Else thats new :D
template <typename T> //custom output stream operator
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
