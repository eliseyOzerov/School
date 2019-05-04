#include <iostream>
#include <fstream>
#include <vector>
#include "TextFile.h"
void kmpNext(std::string s) {

    int size = s.size();
    std::vector<int> p(size);
    int j = 0; //konec prefixa
    int i; //konec sufixa
    p[0] = -1;
    p[1] = 0;
    for (i = 2; i < size; i++) {
        /*
         * Primerjamo crke na p[j] in p[i-1]
         * V kolikor sta enaki, povecamo oba indeksa
         * V kolikor nista, zmanjsujemo j za 1 dokler ni enak nic
         * (Ker smo ze primerjali vse prejsnje crke, lahko zmanjsujemo j za ena.
         * Tako vidimo, ali je konec trenutnega sufixa enak koncu katerega od prejsnjih prefixov,
         * kar pomeni, da imamo ponavljanje obstojecega prefixa, in zapisemo njegovo dolzino v p[i]
         */
        while (j > 0 && s[j] != s[i-1])
            j = p[j];

        if (s[j] == s[i-1])
            j++;
        p[i] = j;
    }
    for(int i = 0; i<size; i++){
        std::cout << s[i] << ' ';
    }
    std::cout << std::endl;
    for(int i = 0; i<size; i++){
        std::cout << p[i] << ' ';
    }
}
int main(int argc, char* argv[]) {
    if(argc<3){
        std::cout << "Insufficient arguments.\n";
        return 0;
    }
    std::string path = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\kmpSearch\\";
    std::string pattern = argv[1];
    std::string infilename = argv[2];
    std::string outfilename = "out.txt";

    TextFile file(path+infilename);
    std::ofstream ofs(path+outfilename, std::ofstream::trunc);
    if(ofs.is_open()){
        for(unsigned int i : file.kmpSearch(pattern)){
            ofs << std::to_string(i) << '\n';
        }
    }

    return 0;

}