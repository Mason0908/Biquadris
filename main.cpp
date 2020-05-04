

#include "Core.hpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    int startlevel = 1;
    int seed = 199;
    bool isGraphic = true;
    string file1 = "sequence1.txt" ;
    string file2 = "sequence2.txt" ;
    int temp;
    bool isBonus = false;
    string tempfile;
    for (int i = 1; i < argc; ++i) {
        string curr{argv[i]};
        
        if (curr == "-text"){
            isGraphic = false;
        }
        if (curr == "-startlevel"){
            i++;
            istringstream ss{argv[i]};
            if (ss >> temp){
                startlevel = temp;
            }
        }
        if (curr == "-seed"){
            i++;
            istringstream ss{argv[i]};
            if (ss >> temp){
                seed = temp;
            }
        }
        if (curr == "-scriptfile1"){
            i++;
            istringstream ss{argv[i]};
            if (ss >> tempfile){
                file1 = tempfile;
            }
        }
        if (curr == "-scriptfile2"){
            i++;
            istringstream ss{argv[i]};
            if (ss >> tempfile){
                file2 = tempfile;
            }
        }
	if (curr == "-enablebonus"){
	    isBonus = true;
	}
    }
    
    
    
    Core game{startlevel, file1, file2, isGraphic, isBonus, seed};
    game.Run();
}
