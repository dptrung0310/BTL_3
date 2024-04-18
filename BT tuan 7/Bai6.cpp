#include <iostream>
#include <cstring>

using namespace std;

int countSubstring(const char* str, const char* substr) {
    int count = 0;
    int len_str = strlen(str);
    int len_substr = strlen(substr);

    for (int i = 0; i <= len_str - len_substr; ++i) {
        if (strncmp(str + i, substr, len_substr) == 0) {
            ++count;
        }
    }

    return count;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <string1> <string2>" << endl;
        return 1;
    }

    const char* str1 = argv[1];
    const char* str2 = argv[2];

    int occurrences = countSubstring(str2, str1);

    cout << "The substring \"" << str1 << "\" occurs " << occurrences << " times in \"" << str2 << "\"." << endl;

    return 0;
}