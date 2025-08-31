#include <fstream>
using namespace std;
int main()
{

    ifstream ifs("filehandlingInput.txt");
    ofstream ofs("filehandlingOutput.txt", ios::trunc); //:app = append
    //or
    // ifstream ifs;
    // ofstream ofs;
    // ifs.open("filehandlingInput.txt");
    // ofs.open("filehandlingOutput.txt");
    //Manupulator
    ofs << hex << 162 << endl;               //oct , dec
    ofs << scientific << 123.123456 << endl; //fixed , float, scientific
                                             // set(), left , right , s
    ifs.close();
    ofs.close();
    return 0;
}