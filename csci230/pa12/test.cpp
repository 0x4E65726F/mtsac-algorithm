#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> vec;
    ifstream file;
    file.open("filetoSort.bin", ios::binary);

    if (!file)
    {
        cout << "err\n";
        return 1;
    }

    file.unsetf(std::ios::skipws);
    std::streampos fileSize;
    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    while (file.gcount() != 0)
    {
        int n;
        file.read((char *)&n, sizeof(int));
        vec.push_back(n);
    }

    for (int i : vec)
    {
        cout << i << endl;
    }

    return 0;
}