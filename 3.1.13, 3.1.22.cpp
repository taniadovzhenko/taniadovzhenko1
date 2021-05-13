#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

// 2
bool is_symmetric(const std::string &A) {
    for (int i = 0; i < A.size() / 2 + 1; i++) {
        if (A[i] != A[A.size() - 1 - i]) return false;
    }
    return true;
}

// 3b
std::vector<int> slice(const std::vector<int> &v, int from, int to) {
    std::vector<int> sliced;
    std::copy(std::next(v.begin(), from), std::next(v.begin(), to), std::back_inserter(sliced));

    return sliced;
}

std::vector<std::vector<int>> generate_partitions(int size, int n) {
    std::vector<std::vector<int>> partitions;

    std::vector<int>p(size); // An array to store a partition
    int k = 0; // Index of last element in a partition
    p[k] = size; // Initialize first partition as number itself

    // This loop first prints current partition then generates next
    // partition. The loop stops when the current partition has all 1s
    while (true) {
        // print current partition
        if (k + 1 == n) {
            auto permutation = slice(p, 0, k + 1);
            std::sort(permutation.begin(), permutation.end());

            do {
                partitions.push_back(permutation);
            } while(std::next_permutation(permutation.begin(), permutation.end()));
        }

        // Generate next partition

        // Find the rightmost non-one value in p[]. Also, update the
        // rem_val so that we know how much value can be accommodated
        int rem_val = 0;
        while (k >= 0 && p[k] == 1) {
            rem_val += p[k];
            k--;
        }

        // if k < 0, all the values are 1 so there are no more partitions
        if (k < 0) return partitions;

        // Decrease the p[k] found above and adjust the rem_val
        p[k]--;
        rem_val++;


        // If rem_val is more, then the sorted order is violated. Divide
        // rem_val in different values of size p[k] and copy these values at
        // different positions after p[k]
        while (rem_val > p[k]) {
            p[k + 1] = p[k];
            rem_val = rem_val - p[k];
            k++;
        }

        // Copy rem_val to next position and increment position
        p[k + 1] = rem_val;
        k++;
    }
}

bool is_n_symmetric(const std::string &A, int n) {
    auto partitions = generate_partitions(A.size(), n);
    for (auto &partition : partitions) {
        int last_idx = 0;
        for (auto &el : partition) {
            if (!is_symmetric(A.substr(last_idx, el)))
                continue;

            last_idx += el;
        }

        return true;
    }
    return false;
}

// 3a
bool is_2_symmetric(const std::string &A) {
    return is_n_symmetric(A, 2);
}


int main() {
    std::array<std::string, 4> tests{"abcba", "", "abba", "sadfsdf"};
    for (auto &el : tests) {
        std::cout << el << " is " << (is_symmetric(el) ? "" : "not ") << "symmetric" << std::endl;
    }

    std::cout << "\nTest N-symmetric & 2-symmetric:" << std::endl;
    std::cout << is_n_symmetric("HelleHWoroW", 2) << std::endl;
    std::cout << is_2_symmetric("HelleHWoroW") << std::endl;
}