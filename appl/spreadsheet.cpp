#include "spreadsheet.h"

#include <iostream>
#include <iomanip>
#include <sstream>

spreadsheet::spreadsheet(size_t r, size_t c) : rowCount(r), colCount(c) {
    data = new string*[rowCount];
    for(size_t i = 0; i < rowCount; ++i) {
        data[i] = new string[colCount];
    }
}

spreadsheet::~spreadsheet() {
    for(size_t i = 0; i < rowCount; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

void spreadsheet::updateCell(size_t row, size_t col, const string& s) {
    if (row < rowCount && row >= 0 && col < colCount && col >=0) {
        data[row][col] = s;
    }
}

void spreadsheet::print() {
    for(size_t i = 0; i < rowCount; ++i) {
        for(size_t j = 0; j < colCount; ++j) {
            cout << data[i][j] << (j < colCount-1 ? "|" : "");
        }
        cout << endl;
    }
}

void spreadsheet::prettyPrint() {
    int width = 5;
    for(size_t j = 0; j < colCount; ++j) {
        cout << std::right << std::setw(width) << std::string(width+1, '-');
    }
    cout << endl;
    for(size_t i = 0; i < rowCount; ++i) {
        cout << std::left << "|" ;
        for(size_t j = 0; j < colCount; ++j) {
            cout << std::left << std::setw(width) << data[i][j] << "|";
        }
        cout << endl;
        for(size_t j = 0; j < colCount; ++j) {
            cout << std::right << std::setw(width) << std::string(width+1, '-');
        }
        cout << endl;
    }
}

void driver_spreadsheet() {
    size_t rowCount = 5, colCount = 5;
    spreadsheet s(rowCount,colCount);

    for(size_t i = 0; i < rowCount; ++i) {
        for (size_t j = 0; j < colCount; ++j) {
            stringstream ss;
            ss << " " << i << "," << j;
            s.updateCell(i, j, ss.str());
        }
    }
    s.updateCell(2,3,"hello");

    s.print();
    s.prettyPrint();
}