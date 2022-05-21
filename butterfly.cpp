#include <iostream>
#include <string>
#include <list>
using namespace std;

class Butterfly{
    private:
    int wingSpan;
    int antennaeLength;
    int proboscisLength;
    string thoraxColor;
    string abdomenColor;
    string foreWingColor;
    string hindWingColor;

    int randomGenes(int butterfly1, int butterfly2){
        //Takes the stats of two butterflies and "randomly" combines them
        
        int randomInt = rand() % 10;
        int mutation;

        switch (randomInt)
        {
        case 1:
            mutation = butterfly1;
            break;
        case 2:
            mutation = butterfly2;
            break;
        case 3:
            mutation = butterfly1 - 1;
            break;
        case 4:
            mutation = butterfly1 + 1;
            break;
        case 5:
            mutation = butterfly2 - 1;
            break;
        case 6:
            mutation = butterfly2 + 1;
            break;
        case 7:
            mutation = ((butterfly1 + butterfly2) / 2 ) - 1;
            break;
        case 8:
            mutation = ((butterfly1 + butterfly2) / 2) + 1;
            break;
        default:
            mutation = (butterfly1 + butterfly2) / 2;
        }

        if (mutation <= 0){
            mutation = 1;
        }

        return mutation;
    }

    string randomGenes(string butterfly1, string butterfly2){
        //Takes the color of two butterflies and randamizes the color of the child
        //There is a higher chance that the child will get a color from the parent

        int randomInt = rand() % 20 + 1;
        string mutation;
        string colors[10] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "PURPLE", "PINK", "WHITE", "GRAY", "BLACK"};


        if (randomInt < 10){
            mutation = butterfly1;
        } else if ( randomInt < 18){
            mutation = butterfly2;
        } else{
            int randomColor = rand() % 10;
            mutation = colors[randomColor];
        }

        return mutation;
    }

    public:
        void DefaultButterfly(){
            wingSpan = 4;
            antennaeLength = 2;
            proboscisLength = 3;
            thoraxColor = "BLACK";
            abdomenColor = "GRAY";
            foreWingColor = "ORANGE";
            hindWingColor = "ORANGE";
        }

        void BreedButterfly(Butterfly butterfly1, Butterfly butterfly2){
            wingSpan = randomGenes(butterfly1.getWingSpan(), butterfly2.getWingSpan());
            antennaeLength = randomGenes(butterfly1.getAntennaeLength(), butterfly2.getAntennaeLength());
            proboscisLength = randomGenes(butterfly1.getProboscisLength(), butterfly2.getProboscisLength());
            thoraxColor = randomGenes(butterfly1.getThoraxColor(), butterfly2.getThoraxColor());
            abdomenColor = randomGenes(butterfly1.getAbdomenColor(), butterfly2.getAbdomenColor());
            foreWingColor = randomGenes(butterfly1.getForeWingColor(), butterfly2.getForeWingColor());
            hindWingColor = randomGenes(butterfly1.getHindWingColor(), butterfly2.getHindWingColor());
        }

        void DisplayButterfly(){
            cout << "Wing Span: " << wingSpan << "\n";
            cout << "Antennae Length: " << antennaeLength << "\n";
            cout << "Proboscis Length: " << proboscisLength << "\n";
            cout << "Thorax Color: " << thoraxColor << "\n";
            cout << "Abdomen Color: " << abdomenColor << "\n";
            cout << "ForeWing Color: " << foreWingColor << "\n";
            cout << "HindWing Color: " << hindWingColor << "\n";
        }

        int getWingSpan(){
            return wingSpan;
        }

        int getAntennaeLength(){
            return antennaeLength;
        }

        int getProboscisLength(){
            return proboscisLength;
        }

        string getThoraxColor(){
            return thoraxColor;
        }

        string getAbdomenColor(){
            return abdomenColor;
        }

        string getForeWingColor(){
            return foreWingColor;
        }

        string getHindWingColor(){
            return hindWingColor;
        }
        
};

class User{

    public:

    User(){
        Butterfly butterfly1, butterfly2, butterfly3, butterfly4;
        butterfly1.DefaultButterfly();
        butterfly2.DefaultButterfly();
        butterfly3.DefaultButterfly();
        butterfly4.DefaultButterfly();

        flutter.push_back(butterfly1);
        flutter.push_back(butterfly2);
        flutter.push_back(butterfly3);
        flutter.push_back(butterfly4);
    }

    void printFlutter(){
        //prints out the stats for all butterflies in the flutter
        int num = 0;
        cout << "================================\n";
        for (Butterfly i : flutter){
            num ++;
            cout << "Butterfly " + to_string(num) + "\n";
            i.DisplayButterfly();
            cout << "================================\n";
        }
    }

    static int input(int max_input, string prompt){
        //Runs till the user enters in a valid input

        //Users input is placed into a string and changed into an int if valid
        string hold = "Blank";

        while (true)
        {
            cout << prompt;
            getline(cin, hold);

            //Will try to change hold into an int
            try
            {
                int choice = stoi(hold);

                //if hold was a number then it is changed to an int and checked here to see if it is below the
                //max_input and greater then zero 
                if( choice > 0 && choice <= max_input){
                    return choice;
                }
                //if hold was a number but less than zero or greater then max_input then it is invalid
                cout << "Invalid input.\n\n"; 
            }
            catch(const std::exception& e)
            {
                //hold was not a number and therefore not valid
                cout << "Invalid input.\n\n";
            }
            
        }
        
    }

    void addDefaultButterfly(){
        // adds a default butterfly to the flutter

        Butterfly defaultButterfly;
        defaultButterfly.DefaultButterfly();

        flutter.push_back(defaultButterfly);
        cout << "Default Butterfly added!\n";
    }

    void breedButterflies(){
        //breds the current flutter members

        int num = 0;
        int flutterSize = flutter.size();
        Butterfly hold;
        for (Butterfly i : flutter){
            num++;
            if (num % 2 == 0){
                Butterfly child;
                child.BreedButterfly(i,hold);

                flutter.push_back(child);

            }else{
                hold = i;
            }

            if (num == flutterSize){
                cout << "You got " + to_string(flutterSize / 2) + " more butterflies!\n";
                return;
            }
        }


    }

    void removeButterfly(){
    // displays remove options

    /*
    int wingSpan;
    int antennaeLength;
    int proboscisLength;
    string thoraxColor;
    string abdomenColor;
    string foreWingColor;
    string hindWingColor;
    */

    string prompt = "Which aspect do you want to remove on\n1. wing span\n2. antennae length\n3. proboscis length\n4. thorax color\n5. abdomen color\n6. forewing color\n7. hindwing color\n8. stop removing\n";
    int choice = 0;
    int size;
    string color;

    while(choice != 8){
        choice = input(8, prompt);

    if (choice < 4){
        removeInt(choice);
        
    } else if (choice < 8){
        removeColor(choice);
    }
    }
    }

    void removeInt(int partChoice){
        //removes butterflies based on size

        string prompt = "Remove butterflies that are\n1. > greater than number\n2. < less than number\n3. = equal to number\n";
        string prompt2 = "What number are we using? (max: 1,000,000)\n";
        int choice = input(3, prompt);
        int num = input(1000000, prompt2);
        int butterfliesRemoved = 0;


        list<Butterfly>::iterator it = flutter.begin();
        switch (choice)
        {
        case 1:
            // if butterfly part is greater than number remove butterfly
            while ( it != flutter.end())
            {
                if( partSelectionInt( (*it), partChoice) > num){
                    it = flutter.erase(it);
                    butterfliesRemoved++;
                }else{
                    it++;
                }
            }
            cout << to_string(butterfliesRemoved) + " Butterflies removed.\n\n";
            break;
        case 2:
        // if butterfly part is less than number remove butterfly
            while ( it != flutter.end())
            {
                if( partSelectionInt( (*it), partChoice) < num){
                    it = flutter.erase(it);
                    butterfliesRemoved++;
                }else{
                    it++;
                }
            }
            cout << to_string(butterfliesRemoved) + " Butterflies removed.\n\n";
            break;
        default:
        // if butterfly part is equal to number remove butterfly
            while ( it != flutter.end())
            {
                if( partSelectionInt( (*it), partChoice) == num){
                    it = flutter.erase(it);
                    butterfliesRemoved++;
                }else{
                    it++;
                }
            }
            cout << to_string(butterfliesRemoved) + " Butterflies removed.\n\n";
        }
    }

    void removeColor(int partChoice){
        //removes butterflies based on color

        string colors[10] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "PURPLE", "PINK", "WHITE", "GRAY", "BLACK"};
        string prompt = "Which color are we removing?\n1. red\n2. orange\n3. yellow\n4. green\n5. blue\n6. purple\n7. pink\n8. white\n9. gray\n10. black\n";
        int choice = input(10, prompt);
        int butterfliesRemoved = 0;

        list<Butterfly>:: iterator it = flutter.begin();

        while ( it != flutter.end())
        {
            if( partSelectionColor((*it), partChoice) == colors[choice - 1]){
                it = flutter.erase(it);
                butterfliesRemoved++;
            } else{
                it++;
            }
        }
        cout << to_string(butterfliesRemoved) + " Butterflies removed.\n\n";
        

    }

    int partSelectionInt(Butterfly butterfly, int partChoice){
        // Selects the int part of a butterfly and returns it.
        // This function is ment to be used with the removeInt function
        // partChoice will be 1-3

        switch (partChoice)
        {
        case 1:
            return butterfly.getWingSpan();
        case 2:
            return butterfly.getAntennaeLength();
        default:
            return butterfly.getProboscisLength();
        }
    }

    string partSelectionColor(Butterfly butterfly, int partChoice){
        // Selects the string part of a butterfly and returns it.
        // This function is ment to be used with the removeColor function
        // partChoice will be 4-7

        switch (partChoice)
        {
        case 1:
            return butterfly.getThoraxColor();
        case 2:
            return butterfly.getAbdomenColor();
        case 3:
            return butterfly.getForeWingColor();        
        default:
            return butterfly.getHindWingColor();
        }
    }

    private:
        list<Butterfly> flutter;

};

int main(){
  int choice = 0;
  cout << "Welcome to butterfly gen!\n";
  cout << "We will give you 4 butterflies to start with.\n";

  string prompt = "1. see butterflies\n2. breed butterflies\n3. remove butterflies\n4. add default butterfly\n5. close program\n";

  User user;

  while(choice != 5){
  choice = user.input(5, prompt);

  switch (choice)
  {
  case 1:
      user.printFlutter();
      break;
  case 2:
      user.breedButterflies();
      break;
  case 3:
      user.removeButterfly();
      break;
  case 4:
      user.addDefaultButterfly();
      break;
  case 5:
      cout << "Good Bye!";
      break;
  }

  }
  return 0;
}