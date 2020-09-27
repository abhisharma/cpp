#include <string.h>
#include <string>
#include <vector>
#include <iostream>

struct Field
{
    Field(const char* n,
          const char* v)
    {
        size_t nlen = strlen(n);
        size_t vlen = strlen(v);
        name = new char[nlen + 1];
        value = new char[vlen + 1];
        strncpy(name, n, nlen + 1);
        strncpy(value, v, vlen + 1);
    }
    char* name;
    char* value;
};

struct Row
{
    uint64_t m_timestamp;
    int m_seqnum;
    std::string m_symbol;
    double m_opnqty;
};

// Function to extract fields into Row struct
Row* extractRow(std::vector<Field> fields)
{
    Row* row = new Row();

    for (auto field: fields)
    {
        size_t vLen = strlen(field.value);
        std::string vStr(field.value, vLen);

        if (strcmp(field.name, "TSTAMP") == 0)
        {
            row->m_timestamp = std::stoull(vStr);
        }
        else if (strcmp(field.name, "SEQNUM") == 0)
        {
            row->m_seqnum = std::stoi(vStr);
        }
        else if (strcmp(field.name, "SYMBOL") == 0)
        {
            row->m_symbol = vStr;
        }
        else if (strcmp(field.name, "OPNQTY") == 0)
        {
            row->m_opnqty = std::stod(vStr);
        }
        else {
            // Log invalid field name
        }

    }
    return row;
}

void driver_extract()
{
    std::vector<Field> fields;
    Field tstamp("TSTAMP", "1001203034");
    Field seqnum("SEQNUM", "10001");
    Field symbol("SYMBOL", "AAPL");
    Field opnqty("OPNQTY", "500");
    fields.push_back(tstamp);
    fields.push_back(seqnum);
    fields.push_back(symbol);
    fields.push_back(opnqty);

    Row* row = extractRow(fields);
    std::cout << row->m_timestamp << ' '
              << row->m_seqnum << ' '
              << row->m_symbol << ' '
              << row->m_opnqty << std::endl;
    delete row;

    for (auto field: fields) {
        delete[] field.name;
        delete[] field.value;
    }
}

