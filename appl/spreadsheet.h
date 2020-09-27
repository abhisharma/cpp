//
// Created by Abhishek Sharma on 9/28/19.
//

#ifndef CPP_SPREADSHEET_H
#define CPP_SPREADSHEET_H

#include <string>

using namespace std;

class spreadsheet {
public:
    spreadsheet(size_t rowCount, size_t colCount);

    void updateCell(size_t row, size_t col, const string& s);
    void print();
    void prettyPrint();
    ~spreadsheet();
private:
    string** data;
    size_t rowCount;
    size_t colCount;
};

#endif //CPP_SPREADSHEET_H
