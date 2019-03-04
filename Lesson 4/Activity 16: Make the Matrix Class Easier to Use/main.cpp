#include <array>
#include <iostream>
#include <functional>

// We want a matrix with a fixed size:
// we take the size as non-type template parameters.
// Inside the class we can access the non-type parameters,
// even to perform computations or to pass to other
// expressions which require a compile type value, e.g.:
// the size of the array.
// We take the type after the size and we default it so it's not mandatory to
// provide it.
// Similarly, we default to Multiply as operation.
template<size_t R, size_t C, typename T=int, typename Multiply=std::multiplies<T>>
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
    std::array<T, R> multiply(const std::array<T, C>& vector, Multiply multiply=Multiply()) {
        std::array<T, R> result = {};
        for(size_t r = 0; r < R; r++) {
            for(size_t c = 0; c < C; c++) {
                result[r] += multiply(get(r, c), vector[c]);
            }
        }
        return result;
    }

};

// For convenience we createa a function to print the matrix
template<size_t R, size_t C, typename T, typename Mult>
std::ostream& operator<<(std::ostream& os, const Matrix<R, C, T, Mult>& matrix) {
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
    Matrix<3, 2> matrix;
    matrix.setRow(0, {1,2});
    matrix.setRow(1, {3,4});
    matrix.setRow(2, {5,6});

    std::cout << "Initial matrix:" << matrix << std::endl;

    Matrix<3, 2, int, std::plus<int>> matrixAdd;
    matrixAdd.setRow(0, {1,2});
    matrixAdd.setRow(1, {3,4});
    matrixAdd.setRow(2, {5,6});

    std::array<int, 2> vector = {8, 9};
    std::array<int, 3> result = matrixAdd.multiply(vector);
    std::cout << "Result of multiplication (with plus instead of multiply): [" << result[0] << ", "
              << result[1] << ", " << result[2] << "]" << std::endl;

}

/*

    Output:

    Initial matrix:
    1 2
    3 4
    5 6

    Result of multiplication (with plus instead of multiply): [20, 24, 28]

 */