#include <iostream>
#include <string>
#include <map> // Need ts for the map function twin
#include <cstdlib> //So I can clear the terminal after every page 
#include <chrono> // for my timers n' shit
#include <thread>
#include <vector> // for my lazy ass making arrays

//g++ Filler.cpp -o Filler && ./Filler
//use that to run the cpp file on the terminal.

using namespace std;

class mainMenu{
    public:
    //Main menu of the whole factory, or machine in this case...
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
    int commandcheck;

    int userinputCommand(){
        cout << "User Command: " << endl;
        cin >> usrCommand;

        map<string, int> commandSet = {
            {"main", 1},
            {"filler", 2}
        };

        return commandSet.count(usrCommand) ? commandSet[usrCommand] : -1;

    }
    


};

class Filler {
    public:

    // reminder to use the command control

    userCommands command;

    string fillerStatus;
    int bowlLevel;
    int fillerRunIdle;
    int bottlesFilled;
    bool fillerStart;
    bool fillerEStop;
    bool timerComplete;

    // The CIP phases will be set within this array
    // 0 = Idle, 1 = initializing 2 = Running 3 = Chemical Clean
    // 4 = Rinsing, 5 = Hot water Clean, 6 = Finalizing 70 = CIP Complete
    // 8 = ABORTED, 9 = Faulted

    vector<bool> fillerCIPPhases; 
    // using a vector for the phases because too lazy to type type shit
    // Im not writing out {true , true, false} that's cringe
    // Surely this won't bite me in the ass in the future... hopefully...
    

    int cipPhaseValue;
    int fillerProductionSteps[10];

    //Filler IO Setup
    bool fillerOutIO_1[100];
    bool fillerInIO_1[100];



    //I made one timer for all filler setpoints because Im lazy af...
    void fillerTimer(int seconds){
        string setNameTimer;
        
        for (int i = seconds; i > 0; i--){
            cout << "Time remaining: "<< i << "  \r";
            cout.flush();
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << setNameTimer << endl;
        bool timerComplete = true;
    }
    
    void fillerAttributes(){

        //first check if the filler is either in CIP,
        //HAACP, Maintenance or in production

        // In order to start the filler a few things must undergo first

        // 1. A Hot water and CIP must be done before production
        // 2. After CIP and hot water a Finish Juice setting must be met 
        // 3. Finish Juice must recieve the Filler OK signal.
        // 4. Once Finish Juice recieves the Ok signal start Juice pump

        // First check if CIP has been done


        // let's be real, you'll always have to start with CIP being false
        fillerCIPPhases.push_back(false);
        // self rule of thumb: ALWAYS SET NEW BOOLS TO BE FALSE 
        // UNLESS IT'S AN INITIALIZER FOR ANYTHING!!!!!

        if (fillerCIPPhases[0] == false)
        {
            string fillerStatus = "Need to start CIP\n";
            cout << "Start CIP? (Y/N)\n" << endl;

            command.userinputCommand();


            if (command.usrCommand == "Y" || command.usrCommand == "y")
            {
                cout << "Starting CIP\n" << endl;
                string fillerStatus = "In CIP...\n";
                fillerCIPPhases.push_back(false);
                fillerCIPPhases[1] = true;

                // timer set for CIP of 2 Minutes
                
                fillerTimer(120);
                if (timerComplete == true)
                {
                    // Set the first set of the CIP to be true
                    fillerCIPPhases[0] = true;
                }
                
            }
            
            
        }
        

        cout << "Filler Current Status: " << fillerStatus << "\n" << endl;
    }


};


int main(){
    
    int menuPage = 1;
    //always set special functions menu to 1 otherwise it'll conflict with
    //the menu page setup.
    int specialFunctionsMenu = 1;
    userCommands command;
    mainMenu menu;
    Filler fillerpage;
    
    


// remember to always include user command controls if not well ummm shit won't work
   while(true){
    switch(menuPage){
        case 1: 
        system("clear"); // always include this so it doesn't clutter the terminal.
        menu.display();
        menuPage = command.userinputCommand();
        break;

        case 2:
        system("clear");
        fillerpage.fillerAttributes();
        menuPage = command.userinputCommand();
        break;

        default:
        cout << "invalid command" << endl;
        menuPage = command.userinputCommand();
        break;
    }
}

    

    return 0;
}