#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <fstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      
#define RED     "\033[31m"  
#define GREEN   "\033[32m" 
#define YELLOW  "\033[33m"   
#define BLUE    "\033[34m"      
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"      
#define WHITE   "\033[37m"   
#define BOLDBLACK   "\033[1m\033[30m"

class func {
public:
    static void openFile(std::string file) {
        std::string line;
        std::ifstream myFile;
        myFile.open(file);
        while (getline(myFile, line)) {
            std::cout << line << '\n';
        }

        myFile.close();
    }
};

namespace FCLI {
    class CreateApp {
    public:
        void text(char const* color, std::string text) {
            if (color == "green") std::cout << GREEN << text << RESET;
            else if (color == "red") std::cout << RED << text << RESET;
            else if (color == "blue") std::cout << BLUE << text << RESET;
            else if (color == "yellow") std::cout << YELLOW << text << RESET;
            else if (color == "maganta") std::cout << MAGENTA << text << RESET;
            else if (color == "cyan") std::cout << CYAN << text << RESET;
            else if (color == "white") std::cout << WHITE << text << RESET;
            else std::cout << WHITE << text << RESET;
        }

        std::string textQuestion(char const* question, char const* defult) {
            std::cout << question << "(" << defult << ") ";
            std::string answer;
            std::getline(std::cin, answer);
            if (answer == "") return defult;
            else return answer;
        }

    };

    void logo() {
        printf("****************    ******************     *****              ************* \n");
        printf("****************    ******************     *****              ************* \n");
        printf("*****               ******************     *****                  ***** \n");
        printf("****************    ********               *****                  ***** \n");
        printf("****************    ********               *****                  ***** \n");
        printf("*****               ********               *****                  ***** \n");
        printf("*****               ********               *****                  ***** \n");
        printf("*****               ******************     ***************        ***** \n");
        printf("*****               ******************     ***************     ************ \n");
        printf("*****               ******************     ***************     ************ \n\n\n");
    };

    void proccess(std::string command) {
        std::string tool = "";
        std::string args = "";
        char delimiter = ' ';

        std::istringstream sstream(command);
        std::string word;
        int i = 0;
        int IS_ARG = 0;
        for (int i = 0; i < command.length(); i++) {
            if (IS_ARG == 1) {
                args += command[i];
            }
            else {
                if (command[i] != ' ') {
                    tool += command[i];
                }
                else {
                    IS_ARG = 1;
                    continue;
                }
            }

        }
        if (tool == "open") {
            func::openFile(args);
        }
    }
}