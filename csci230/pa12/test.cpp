#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    ifstream fin;
    fin.open("filetoSort.bin", ios::binary);

    if (!fin)
    {
        cout << "err\n";
        return 1;
    }

    while (fin.gcount() != 0)
    {
        int n;
        fin.read((char *)&n, sizeof(int));
        vec.push_back(n);
    }

    for (int i : vec)
    {
        cout << i << endl;
    }

    return 0;
}