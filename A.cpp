#include <bits/stdc++.h>
using namespace std;

// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
template <typename T, std::size_t N> //custom output stream operator for array
std::ostream& operator<<(std::ostream& os, const T (&arr)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        os << arr[i] << " ";
    }
    return os;
}
