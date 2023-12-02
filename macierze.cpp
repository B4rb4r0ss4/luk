#include <iostream>
#include <vector>
using namespace std;
struct Matrix {
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

    // Constructor to initialize the matrix
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // Operator * to perform matrix multiplication
    Matrix operator*(const Matrix& other) {
        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    // Example matrices using the Matrix struct
    Matrix A(2, 2);
    cout<<"Podaj macierz 1: "<<'\n';
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    A.data = {{a,b}, {c,d}};
    cout<<"Podaj macierz 2: "<<'\n';
    cin>>a>>b>>c>>d;
    Matrix B(2, 2);
    B.data = {{a,b}, {c, d}};

    // Perform matrix multiplication using the operator *
    Matrix result = A * B;

    // Display the result
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            std::cout << result.data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

