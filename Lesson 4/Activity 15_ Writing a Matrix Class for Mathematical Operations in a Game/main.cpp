#include <array>
#include <iostream>

// We want a matrix with a fixed size:
// we take the size as non-type template parameters.
// Inside the class we can access the non-type parameters,
// even to perform computations or to pass to other
// expressions which require a compile type value, e.g.:
// the size of the array
template<typename T, size_t R, size_t C>
class Matrix {
    // We store row_1, row_2, ..., row_C
    std::array<T, R*C> data;
public:
    Matrix() : data({}) {}

    // For convenience we allow setting the values of a full row
    void setRow(size_t row, const std::array<T, C>& rowValue) {
        // We need to ensure that we are setting a row which exists
        if (row >= R) {
            // std::abort() terminates the program when it's called
            std::abort();
        }
        for(size_t c = 0; c < C; c++) {
            get(row, c) = rowValue[c];
        }
    }

    T& get(size_t row, size_t col) {
        if (row >= R || col >= C) {
            std::abort();
        }

        return data[row*C + col];
    }

    // This is like get(), but returns a non modifiable reference
    const T& get(size_t row, size_t col) const {
        if (row >= R || col >= C) {
            std::abort();
        }

        return data[row*C + col];
    }

    // A matrix can be multiplied by a vector with a number of elements
    // equal to the number of columns of the matrix.
    std::array<T, R> multiply(const std::array<T, C>& vector) {
        std::array<T, R> result = {};
        for(size_t r = 0; r < R; r++) {
            for(size_t c = 0; c < C; c++) {
                result[r] += get(r, c) * vector[c];
            }
        }
        return result;
    }

};

// For convenience we createa a function to print the matrix
template<typename T, size_t R, size_t C>
std::ostream& operator<<(std::ostream& os, const Matrix<T, R, C>& matrix) {
    os << '\n';
    for(int r=0; r < R; r++) {
        for(int c=0; c < C; c++) {
            os << matrix.get(r, c) << ' ';
        }
        os << "\n";
    }
    return os;
}

int main() {
    Matrix<int, 3, 2> matrix;
    matrix.setRow(0, {1,2});
    matrix.setRow(1, {3,4});
    matrix.setRow(2, {5,6});

    std::cout << "Initial matrix:" << matrix << std::endl;
    std::cout << "Setting matrix[1][1] to 7" << std::endl;

    // Get returns a mutable reference, so we can assign a value to it
    matrix.get(1, 1) = 7;

    std::cout << "Modified matrix:" << matrix << std::endl;

    std::array<int, 2> vector = {8, 9};
    std::array<int, 3> result = matrix.multiply(vector);
    std::cout << "Result of multiplication: [" << result[0] << ", "
              << result[1] << ", " << result[2] << "]" << std::endl;

}

/*
    Output:

    Initial matrix:
    1 2
    3 4
    5 6

    Setting matrix[1][1] to 7
    Modified matrix:
    1 2
    3 7
    5 6

    Result of multiplication: [26, 87, 94]

 */
