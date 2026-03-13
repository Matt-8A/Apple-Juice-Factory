#include <iostream>
#include <string>
#include <map>

using namespace std;

class mainMenu{
    public:
    //Main menu of the whole factory, or machine in this case...
    int menuPage = 1;
        void display(){
            
            cout << "-----------------------------------\n" << endl;
            cout << "Welcome to the Apple Juice Factory!\n" << endl;
            cout << "-----------------------------------\n" << endl;
            cout << "\n" << endl;
            cout << "System Status: \n" << endl;
        }
    };

class userCommands{
    public:

    //here's a database of different user commands that 
    string usrCommand;

    void userinputCommand(){
        cout << "User Command: " << endl;
        cin >> usrCommand;

        map<string, int> commandSet = {
            {"main", 1},
            {"filler", 2}
        };

        int commandcheck = commandSet.count(usrCommand) ? commandSet[usrCommand] : -1;

    }
    


};

class Filler {
    public:

    string fillerStatus;
    int bowlLevel;
    int fillerRunIdle;
    int bottlesFilled;
    bool fillerStart;
    bool fillerEStop;


};


int main(){
    
    int menuPage = 1;
    //always set special functions menu to 1 otherwise it'll conflict with
    //the menu page setup.
    int specialFunctionsMenu = 1;
    userCommands command;
    mainMenu menu;

// remember to always include user command controls if not well ummm shit won't work
   while(true){
    switch(menuPage){
        case 1: 
        menu.display();
        command.userinputCommand();
        break;
    }
}

    

    return 0;
}