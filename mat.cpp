//
// Created by shira on 06/03/2022.
//
#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
//using namespace ariel;

string ariel::mat(int c, int r, char c1, char c2) {

    int const min_ascii = 33;
    int const max_ascii = 126;

    if (r <= 0 || c <= 0) { //0 can not be a valid input for mat
        throw invalid_argument("zero or negative input error ");
    }
    if (r % 2 == 0 || c % 2 == 0) { //negative number can not be a valid input for mat
        throw invalid_argument("Mat size is always odd");
    }
    if (c1 < min_ascii || c2  < min_ascii ) { //characters under 33 ascii can not be a valid input for mat
        throw invalid_argument("invalid character");
    }
    if (c1 > max_ascii || c2  > max_ascii ) { //characters over 126 ascii can not be a valid input for mat
        throw invalid_argument("invalid character");
    }

//    char **my_mat = new char *[r];
//    for (int i = 0; i < r; i++) {
//        my_mat[i] = new char[c];
//    }

vector<vector<char>> my_mat(r,vector<char>(c)); //vector of vectors in order to complete the mat

    int start = 0;
    int row = r-1;
    int col = c-1 ;
    char sign = c1;

    while (start <= row && start <= col) {
        //stop condition (when start is bigger than row or col it will override previous rows and cols

        for (int i = start; i <= row; i++) {
            //for columns
            my_mat[i][start] = sign;
            my_mat[i][col]= sign;
        }

        for (int j = start; j <= col; j++) {
            //for rows
            my_mat[start][j] = sign;
            my_mat[row][j] = sign;
        }
        row = row - 1;
        col = col - 1;
        start = start + 1;

        //changing char:
        if (sign == c1) {
            sign = c2;
        } else {
            sign = c1;
        }
    }
    string str_mat;
    //from vector to string:
    bool flag = true;
    for (int i = 0; i < r; i++) {
        if (i == r - 1) {
            flag = false;
        }
        for (int j = 0; j < c; j++) {
            str_mat += my_mat[i][j];
        }
        if (flag) {
            str_mat += "\n";
        }

    }

    return str_mat;
}


