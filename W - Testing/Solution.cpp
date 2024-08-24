#include <stdexcept>
#include <cassert>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    size_t min_idx = 0; // Use size_t instead of int
    for (size_t i = 1; i < seq.size(); ++i) { // Use size_t instead of int
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        vector<int> vect{};
        return vect;
    }
};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        vector<int> vect{ 23, 5, 8, 12, 7 };
        return vect;
    }

    static int get_expected_result() {
        return 1;
    }
};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        vector<int> vect{ 9, 23, 3, 8, 12, 3, 7 };
        return vect;
    }

    static int get_expected_result() {
        return 2;
    }
};

void runTests() {
    try {
        auto emptyArray = TestDataEmptyArray::get_array();
        auto result = minimum_index(emptyArray); // Should throw an exception
        assert(false); // If it does not throw, the test fails
    } catch (invalid_argument& e) {
        // Expected behavior, pass the test
    }

    auto uniqueValues = TestDataUniqueValues::get_array();
    auto uniqueResult = minimum_index(uniqueValues);
    assert(uniqueResult == TestDataUniqueValues::get_expected_result());

    auto twoMinValues = TestDataExactlyTwoDifferentMinimums::get_array();
    auto twoMinResult = minimum_index(twoMinValues);
    assert(twoMinResult == TestDataExactlyTwoDifferentMinimums::get_expected_result());
}

int main() {
    runTests();
    cout << "OK" << endl;
    return 0;
}
