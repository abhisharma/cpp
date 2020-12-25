#include <iostream>
#include <optional>

using namespace std;

optional<string> create(bool b) {
    if (b) return "Godzilla";
    return {};
}

optional<string> create2(bool b) {
    return b ? optional<string>{"Godzilla"} : nullopt;
}

auto create_ref(bool b) {
    static string value = "Godzilla";
    return b ? optional<reference_wrapper<string>>{value}  : nullopt;
}

void driver_optionals()
{
    cout << "create(false) returned "
              << create(false).value_or("empty") << endl;

    // optional-returning factory functions are usable as conditions of while and if
    if (auto str = create2(true)) {
        cout << "create2(true) returned " << *str << endl;
        cout << "create2(true) returned " << str.value_or("empty") << endl;
    }

    if (auto str = create_ref(true)) {
        // using get() to access the reference_wrapper's value
        cout << "create_ref(true) returned " << str->get() << endl;
        str->get() = "Mothra";
        cout << "modifying it changed it to " << str->get() << endl;
    }
}