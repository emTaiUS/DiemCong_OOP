#ifndef EZTRANS_H
#define EZTRANS_H
#include <string>

using namespace std;

class Captain{
    private :
        std::string dec_to_bin(int x,int n);
    public:
        Captain();
        std ::string encode(std::string time);
};

class Soldier{
    private :
        int id;
        std::string bin_to_dec(std::string x,int n);
        std::string split_bin(std::string x,int l,int r);
    public:
        Soldier();
        Soldier(int id);
        std::string decode(std::string s);
        
};



#endif