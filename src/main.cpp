#include <iostream>
#include <string>
#include "../lib/FCLI.hpp"

void App() {
    FCLI::CreateApp app;
    FCLI::logo();
    std::string command;
    std::string mode = app.textQuestion("Are you want to use console mode?(Y/n): ", "Y");
    if (mode == "n" || mode == "N" || (mode != "Y" && mode != "y")) return;
    app.text("white", "FCLI/>");
    while (std::getline(std::cin, command)) {
        if(command == "exit") break;
        FCLI::proccess(command);
        app.text("white", "\nFCLI/>");
    }

}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        App();
    }
    else {
        std::cout << "um..." << '\n';
    }
    return 0;
}