#include <iostream>
#include <vector>

using namespace std;

class Block
{
public:

    // Simple constructor that initializes the resource.
    explicit Block(size_t length);

    // Destructor.
    ~Block();

    // Copy constructor.
    Block(const Block& other);

    // Copy assignment operator.
    Block& operator=(const Block& other);

    // Move constructor.
    Block(Block&& other) noexcept;

    // Move assignment operator.
    Block& operator=(Block&& other) noexcept;

    // Retrieves the length of the data resource.
    size_t Length() const { return _length; };

private:
    size_t _length; // The length of the resource.
    int* _data; // The resource.
};

// Simple constructor that initializes the resource.
Block::Block(size_t length) : _length(length), _data(new int[length])
{
    cout << "In Block(size_t). length = " << _length << "." << endl;
}

// Destructor.
Block::~Block()
{
    cout << "In ~Block(). length = " << _length << ".";

    if (_data != nullptr) {
        cout << " Deleting resource.\n";
        // Delete the resource.
        delete[] _data;
    }
}

// Copy constructor.
Block::Block(const Block& other) : _length(other._length), _data(new int[other._length])
{
    cout << "In Block(const Block&). length = " << other._length << ". Copying resource." << endl;

    copy(other._data, other._data + _length, _data);
}

// Copy assignment operator.
Block& Block::operator=(const Block& other)
{
    cout << "In operator=(const Block&). length = " << other._length << ". Copying resource." << endl;

    if (this != &other) {
        // Free the existing resource.
        delete[] _data;

        _length = other._length;
        _data = new int[_length];
        copy(other._data, other._data + _length, _data);
    }

    return *this;
}

// Move constructor.
Block::Block(Block&& other) noexcept
{
    cout << "In Block(Block&&). length = " << other._length << ". Moving resource." << endl;

    // Copy the data pointer and its length from the source object.
    _data = other._data;
    _length = other._length;

    // Release the data pointer from the source object so that
    // the destructor does not free the memory multiple times.
    other._data = nullptr;
    other._length = 0;
}


// Move assignment operator.
Block& Block::operator=(Block&& other) noexcept
{
    cout << "In operator=(Block&&). length = " << other._length << "." << endl;

    if (this != &other) {
        // Free the existing resource.
        delete[] _data;

        // Copy the data pointer and its length from the
        // source object.
        _data = other._data;
        _length = other._length;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other._data = nullptr;
        other._length = 0;
    }
    return *this;
}

void driver_block() {
    vector<Block> v;
    v.push_back(Block(25));
    v.push_back(Block(75));

    // Insert a new element into the second position of the vector.
    v.insert(v.begin() + 1, Block(50));

    cout << endl;
    for (auto const& item : v) {
        cout << item.Length() << endl;
    }
}