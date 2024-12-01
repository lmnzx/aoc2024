#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// O(nlogn)
unsigned int part_1() {
    std::ifstream f("inputs/day1.txt");
    unsigned int sum = 0;
    std::string s;
    std::vector<int> left, right;

    while (std::getline(f, s)) {
        left.push_back(std::stoi(s.substr(0, 5)));
        right.push_back(std::stoi(s.substr(8, 13)));
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for (int i = 0; i < left.size(); i++) {
        sum += std::abs(left[i] - right[i]);
    }

    return sum;
}

// O(n)
unsigned int part_2() {
    std::ifstream f("inputs/day1.txt");
    unsigned int sum = 0;
    std::string s;
    std::unordered_map<int, int> m;
    std::vector<int> left;

    while (std::getline(f, s)) {
        left.push_back(std::stoi(s.substr(0, 5)));
        int right = std::stoi(s.substr(8, 13));

        m[right]++;
    }

    for (int i : left) {
        auto it = m.find(i);
        if (it != m.end()) {
            sum += i * it->second;
        }
    }

    return sum;
}

int main(void) {
    std::cout << part_1() << "\n";
    std::cout << part_2() << "\n";

    return 0;
}
