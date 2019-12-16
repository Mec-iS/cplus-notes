#include <vector>
#include <assert.h>
#include <iostream>

class Matrix {
public:
    Matrix(int r, int c): rows_(r), columns_(c), values_(r*c, 0) {
        try {
            assert (r == c);
        } catch (...) {
            throw "only square matrices";
        };
    };
    int rows_size() { return this->rows_; }
    int columns_size() { return this->columns_; }
    int get_value_at(int p) { return this->values_[p]; };

    // friend std::ostream& operator<<(std::ostream &strm, const Matrix &m) {
    //     // override << for stream to have a to_string method
    //     return strm << "Matrix[" << m.values_ << "]";
    // }
    
    // overload () to return matrix elements
    int& operator()(int r, int c) {
        return this->values_[r*this->rows_+c];
    }

    int operator()(int r, int c) const {
        return this->values_[r*this->rows_+c];
    }

    // setter
    void set(int r, int c, int value) {
        //set by row/column
        this->values_[r*this->rows_+c] = value;
    }
    void set_p(int p, int value) {
        //set by position
        this->values_[p] = value;
    }

    // overload +
    Matrix operator+(Matrix m) {
        assert (this->rows_size() == m.rows_size());

        Matrix result(this->rows_size(), this->rows_size());
        
        int i = 0;
        for (auto value: this->values_) {
            result.set_p(i, value + m.get_value_at(i));
            i++;
        }

        return result;
    }

private:
    int rows_;
    int columns_;
    std::vector<int> values_;
};

int main() {
    Matrix m1(4,4);
    assert (m1.rows_size() == 4);
    m1.set(1,1,2);
    assert (m1(1,1) == 2);

    Matrix m2(4,4);
    m2.set(1,1,4);

    Matrix m3 = m1 + m2;
    assert (m3(1,1) == 6);
}