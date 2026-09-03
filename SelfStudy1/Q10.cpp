#include<iostream>
using namespace std;

class Matrix
{
private:
    int row;
    int col;
    int mat[10][10];

public:
    Matrix(void): row(0), col(0)
    {
    }

    void acceptRecord(void)
    {
        cout<<"Enter Number of Rows : ";
        cin>>row;

        cout<<"Enter Number of Columns : ";
        cin>>col;

        cout<<"Enter Matrix Elements : "<<endl;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin>>mat[i][j];
            }
        }
    }

    void displayRecord(void)
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cout<<mat[i][j]<<" ";
            }

            cout<<endl;
        }
    }

    // + operator
    Matrix operator+(Matrix m)
    {
        Matrix temp;

        temp.row = this->row;
        temp.col = this->col;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                temp.mat[i][j] = this->mat[i][j] + m.mat[i][j];
            }
        }

        return temp;
    }

    // - operator
    Matrix operator-(Matrix m)
    {
        Matrix temp;

        temp.row = this->row;
        temp.col = this->col;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                temp.mat[i][j] = this->mat[i][j] - m.mat[i][j];
            }
        }

        return temp;
    }

    // * operator
    Matrix operator*(Matrix m)
    {
        Matrix temp;

        temp.row = this->row;
        temp.col = m.col;

        for(int i = 0; i < this->row; i++)
        {
            for(int j = 0; j < m.col; j++)
            {
                temp.mat[i][j] = 0;

                for(int k = 0; k < this->col; k++)
                {
                    temp.mat[i][j] =
                        temp.mat[i][j] +
                        this->mat[i][k] * m.mat[k][j];
                }
            }
        }

        return temp;
    }
};


int main()
{
    Matrix m1, m2, m3;

    cout<<"\nEnter First Matrix"<<endl;
    m1.acceptRecord();

    cout<<"\nEnter Second Matrix"<<endl;
    m2.acceptRecord();

    cout<<"\nFirst Matrix"<<endl;
    m1.displayRecord();

    cout<<"\nSecond Matrix"<<endl;
    m2.displayRecord();


    // Matrix Addition
    if(1)
    {
        m3 = m1 + m2;

        cout<<"\nAddition of Two Matrices"<<endl;
        m3.displayRecord();
    }


    // Matrix Subtraction
    if(1)
    {
        m3 = m1 - m2;

        cout<<"\nSubtraction of Two Matrices"<<endl;
        m3.displayRecord();
    }


    // Matrix Multiplication
    if(1)
    {
        m3 = m1 * m2;

        cout<<"\nMultiplication of Two Matrices"<<endl;
        m3.displayRecord();
    }

    return 0;
}