#include <iostream>
#include <cstring>

#define MAX_LENGHT 128
//we can also use const int MAX_LENGHT = 128;

using namespace std;

/*
we use struct to represent data with elements that are different type
*/

enum SaberType {SINGLEBLADED, DOUBLE_BLADED_LIGHTSABER, CROSSGUARD_LIGHTSABER};

struct LightSaber {
  char* saberColor;
  SaberType saberType;
};


struct Jedi {
    //char pointer represents the name component and will be dynamically created
    char* name;
    int age;
    LightSaber *lightSaber;
    double strength;
};

void initializeSaber(Jedi& j) {
  char input[MAX_LENGHT];
  cout << "Input " << j.name << "'s saber color:";
  cin >> input;
  j.lightSaber->saberColor = new char[strlen(input)];
  strcpy(j.lightSaber->saberColor, input);

  int tmp;
  cout << "Input " << j.name << "'s saber type (singlebladed - 0, double-bladed - 1, crossguard - 2):";
  cin >> tmp;
  j.lightSaber->saberType = (SaberType)tmp;
}

//initialize jedi's components
void initializeJedi(Jedi &j) {
    char input[MAX_LENGHT];
    cout << "Input jedi name:";
    cin >> input;

    j.name = new char[strlen(input)];
    strcpy(j.name, input);

    cout << "Input " << j.name << "'s age:";
    cin >> j.age;


    j.lightSaber = new LightSaber;
    initializeSaber(j);

    cout << "Input " << j.name << "'s strength:";
    cin >> j.strength;
}

void printSaber(LightSaber *ls) {
  cout << "Saber color: " << ls->saberColor << endl;

  cout << "Saber type: ";
  switch (ls->saberType) {
    case 0: cout << "Single-bladed saber" << '\n'; break;
    case 1: cout << "Double-bladed saber" << '\n'; break;
    case 2: cout << "Crossguard saber" << '\n';
  }
}

void printJedi(Jedi &j) {
    cout << "-----------Jedi-----------\n";
    cout << "Name: " << j.name << endl;
    cout << "Age: " << j.age << endl;
    printSaber(j.lightSaber);
    cout << "Strength: " << j.strength << endl;
}

//function to delete the dynamic memory
void killJedi(Jedi &j) {
    delete[] j.name;
    delete[] j.lightSaber->saberColor;
    delete j.lightSaber;
}

int main() {
    Jedi jedi01;

    initializeJedi(jedi01);
    printJedi(jedi01);

    //clear the dynamic memory!!!
    killJedi(jedi01);
    return 0;
}
