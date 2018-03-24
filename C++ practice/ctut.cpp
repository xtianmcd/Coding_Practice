// this is a comment
/*
Multiline comment
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal{
  private: // these can only be changed by functions inside of this class
    int height;
    int weight;
    string name;

    static int numOfAnimals; // this variables value is shared by all objects of this class
  public:
    int getHeight(){ return height; }
    int getWeight(){ return weight; }
    string getName(){return name; }
    void setHeight(int cm){ height = cm; }
    void setWeight(int km){ weight = km; }
    void setName(string animalName){ name = animalName; }

    //void setAll(int, int, string); // prototype function; made to act exaactly like constructor
    Animal(int, int, string); // constructor (same name as class); called whenever object created
    ~Animal(); // destructor
    Animal(); // another constructor (overloading -> diff attributes)

    static int getNumOfAnimals() { return numOfAnimals; } // static method, only applies to static variables

    void toString();
  //Attributes : height weight // variables
  //Capabilities : Run Eat // functions/ methods
}; // note the ; after the curly

// delcare everything
int Animal::numOfAnimals = 0; // declare static var
// setAll does the same thing the constructor does
/*
void Animal::setAll(int height, int weight, string name){ // define prototype method for set all
  this -> height = height; // refer to object's specific height with this ->
  this -> weight = weight;
  this -> name = name;
  Animal::numOfAnimals++;
}
*/
// below is the constructor - called every time an Animal object is created
Animal::Animal(int height, int weight, string name){
  this -> height = height; // refer to object's specific height with this ->
  this -> weight = weight;
  this -> name = name;
  Animal::numOfAnimals++;
}

Animal::~Animal(){ // deconstuctor
  cout << "Animal " << this -> name << " destroyed" << endl;

}

Animal::Animal(){ // overloaded animal
  Animal::numOfAnimals++;
}

void Animal::toString(){
  cout << this -> name << " is " << this -> height <<
  " cms tall and " << this -> weight << " kgs in weight" << endl;
}

class Dog : public Animal{ //inherit Animal class

private:
  string sound = "Woof";
public:
  void getSound() { cout << sound << endl; }

  Dog(int, int, string, string); // custom contstructor
  Dog() : Animal(){}; // default constructor and default superclass constructor
  void toString();

} ; // Dog

Dog::Dog(int height, int weight, string name, string bark) :
Animal(height, weight, name){ // animal constructor handles h, w, n
  this -> sound = bark;
}

void Dog::toString(){
  cout << this -> getName() << " is " << this -> getHeight() << // get method is used for private attributes
      " cms tall and " << this -> getWeight() << " kgs in weight and says"
      << this -> sound;
}

class Danimal{
public:
  void getFamily() { cout << "We are Danimals" << endl; }
  virtual void getClass() {cout << "I'm a Danimal" << endl; }
  virtual void makeSound(){ cout << "The Danimal says grr" << endl; }
}; // mark method as virtual if this class may be overwritten by subclass}

class Adog : public Danimal{
public:
  void getClass() {cout << "I'm Adog" << endl; }
  void makeSound() { cout << "The Adog says woof" << endl; }
};
void whatClassAreYou(Danimal *animal){
  animal -> getClass(); // if virtual not written before Danimal's getClass(), it will
  // always use supercalass's getClass.

}


class GermanShepard : public Adog{
public:
  void getClass() { cout << "I'm a German Shepard" << endl; }
  void getDerived() { cout << "I'm an Animal and a dog" << endl;}
};

class Cat : public Danimal{
public:
  void makeSound() { cout << "The Cat says meow" << endl; }
} ; //Cat

// could also create a Capability class - only to be derived from

// class Car{
// public:
//   virtual int getNumWheels() = 0;
//   virtual int getNumDoors() = 0;
// }; // Car
//
// class StationWagon : public Car{
// public:
//   int getNumWheels() { cout << "Station wagon has 4 wheel" << endl; }
//   int getNumbDoors() { cout << "Station wagon has 4 doors" << endl; }
//   StationWagon() {};
//   ~StationWagon();
// }; // StationWagon

int addNumbers(int firstNum, int secondNum = 0){ // function type would be void if nothing returned
  int combinedValue = firstNum + secondNum;
  return combinedValue;
}

int addNumbers(int firstNum, int secondNum, int thirdNum){ // can overload functions, must have diff attributes
  return firstNum + secondNum + thirdNum;
}

int getFactorial(int number){
  int sum;
  if(number == 1) sum = 1;
  else sum = getFactorial(number - 1) * number;
  return sum;

}

void makeMeYoung(int* age){
  cout << "I used to be " << *age << endl;
  *age = 21;
}

void actYourAge(int& age){
  age = 25;
}

int main(){

     cout  <<  "Hello World" << endl; // output to screen the statements with a carriage return

     const double PI = 3.1415926535;

     char myGrade = 'A'; // 1 byte in memory

     bool isHappy = true; // true = 1; false = 0

     int myAge = 25;

     float favNum = 32.123456;

     double otherfavNum = 5.123456789012345;

     cout << "Favorite Number " << favNum << endl;

     // Other types include
     //  short int :     At least 16 bits
     //  long int :      At least 32 bits
     //  long long int : At least 64 bits
     //  unsigned int :  Same size as signed version
     //  long double :   Not less than double

     cout << "Size of int " << sizeof(myAge) << endl;

     int largestInt = 2147483647;
     cout << "largest int " << largestInt << endl;
     cout << "still largest int " << largestInt++ << endl;
     cout << "largerest int " << ++largestInt << endl;

     int num = 5;
     num += 5; num = num - 5; // statements on same line separated by ;
     cout << "num" << num << endl;

     cout << "4 / 5 = " << 4 / 5 << endl;
     cout << "4 / 5 = " << (float) 4 / 5 << endl; // casting

     // operations: +, -, *, /, %, ++, --, +=

     // if statement comparisons: ==, !=, >, <, >=, <=, &&, ||, ! (not)
     int age = 70;
     int ageAtLastExam = 16;
     bool isNotIntoxicated = true;

     if((age >= 1) && (age < 16)){

       cout << "You can't drive" << endl;

     } else if(! isNotIntoxicated){

       cout << "You can't drive!" << endl;

     } else if(age >= 80 && ((age > 100) || ((age - ageAtLastExam) > 5))){

       cout << "You can't drive!" << endl;
     } else {

       cout << "You can drive" << endl;

     }

     int greetingOption = 2;

     switch(greetingOption){

       case 1 :
          cout << "bonjour" << endl;
          break;

       case 2 :
          cout << "hola" << endl;
          break;

       default :
          cout << "Hello" << endl;

     }

     // variable = (condition) ? true : false
     int largestNum = (5>2) ? 5 : 2;
     cout << "Which is larger, 5 or 2? " << largestNum << endl;

     // Arrays
     int myFavNums[5];
     int badNums[5] = {4, 13, 15, 26, 86};
     // think of arrays as boxes; need to define number of spaces needed
     cout << "Bad Number 1: " << badNums[0] << endl;

     char myName[3][5] = {{'X', 't', 'i', 'a', 'n'},
                          {'M', 'c', 'D'}};
     cout << "2nd letter in 2nd array " << myName[1][1] << endl;
     myName[0][2] = 'y';
     cout << "New Value " << myName[0][2] << endl;

     // For loops
     for(int i = 1; i <= 10; i++){
       cout << i << endl;
     }

     for(int j = 0; j < 3; j++){
       for(int k = 0; k < 5; k++){
         cout << myName[j][k];
       }
       cout << endl;
     }

     // while loops (for when don't know ahead of time when loop will end)
     int randNum = (rand() % 100) + 1; // generates random number from 1 to 100
     while(randNum != 100){
       cout << randNum << ',';
       randNum = (rand() % 100) + 1;
     }

     // simulate for loop with while loop
     int index = 1;
     while(index <= 10){
       cout << index << endl;
       index ++;
     }

     // do while loops - execute whats in the loop at least one time
     // also, user input, strings
     string numberGuessed;
     int intNumberGuessed = 0;
     do {
       cout << "Guess between 1 and 10: ";
       getline(cin, numberGuessed); // gets input from keyboard and stores in string variable
       intNumberGuessed = stoi(numberGuessed); // convert string into int
       cout << intNumberGuessed << endl;
     } while(intNumberGuessed != 4); //this loop will continue until 4 is guessed

     cout << "You win" << endl;

     char happyArray[6] = {'H', 'a', 'p', 'p', 'y', '\0'}; // how you make a string in C
     string birthdayString = " Birthday";
     cout << happyArray + birthdayString << endl;
     string yourName;
     cout << "What is your name ";
     getline(cin, yourName);

     cout << "hello " << yourName << endl;

     double eulersConstant = .57721;
     string eulerGuess;
     double eulerGuessDouble;

     cout << "What is Eurler's Constant? ";
     getline(cin, eulerGuess);

     eulerGuessDouble = stod(eulerGuess);

     if(eulerGuessDouble == eulersConstant){
       cout << "You are right" << endl;
     } else {
       cout << "You are wrong" << endl;
     }

     cout << "Size of String " << eulerGuess.size() << endl;
     cout << "Is string empty " << eulerGuess.empty() << endl;
     cout << eulerGuess.append(" was your guess") << endl;

     string dogString = "dog";
     string catString = "cat";

     cout << dogString.compare(catString) << endl;
     cout << dogString.compare(dogString) << endl;
     cout << catString.compare(dogString) << endl; // comparison based on alphabetical

     string wholeName = yourName.assign(yourName);
     cout << wholeName << endl;

     string firstName = wholeName.assign(wholeName, 0, 5);
     cout << firstName << endl;

     int lastNameIndex = yourName.find("McD", 0);
     cout << "Index for last name " << lastNameIndex << endl;

     yourName.insert(5, " Jobin");
     cout << yourName << endl;

     yourName.erase(6,7);
     cout << yourName << endl;

     yourName.replace(6, 5, "Baller");
     cout << yourName << endl;

     // vectors - like arrays; size can change
     vector <int> lotteryNumVect(10); // initial size 10
     int lotteryNumArray[5] = {4, 13, 14, 24, 34};
     lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);
     cout << lotteryNumVect.at(2) << endl;
     lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);
     cout << lotteryNumVect.at(5) << endl;
     lotteryNumVect.push_back(64); // add value at end
     cout << "Final Value " << lotteryNumVect.back() << endl; // returns final Value
     lotteryNumVect.pop_back();
     cout << "First Value " << lotteryNumVect.front() << endl; // prints first value
     cout << "Is empty? " << lotteryNumVect.empty() << endl;
     cout << "Size " << lotteryNumVect.size() << endl;

     // call functions
     cout << addNumbers(1) << endl;
     cout << addNumbers(1, 5, 6) << endl;

     cout << "The factorial of 3 is " << getFactorial(3) << endl;


     // file io
     string steveQuote = "A day without sunshine is like, you know, night";
     ofstream writer("stevequote.txt"); // output file stream
     if(! writer){
       cout << "Error opening file" << endl;
       return -1;
     } else {
       writer << steveQuote << endl;
       writer.close();
     }

     ofstream writer2("stevequote.txt", ios::app);
     if(! writer2){
       cout << "Error opening file" << endl;
       return -1;
     } else {
       writer2 << "\n -Steve Martin" << endl;
       writer2.close();
     }

     // Open a stream to append to whats there with ios::ap
     // ios::binary : Treat the file as binary
     // ios::in : Open a file to read input
     // ios::trunc : Default
     // ios::out : Open a file to write output

     char letter;
     ifstream reader("stevequote.txt"); // input file stream
     if(! reader){
       cout << "Error opening file" << endl;
       return -1;

     } else {
       for(int i = 0; ! reader.eof(); i++){
          reader.get(letter);
          cout << letter;
       }
       cout << endl;
       reader.close();
     }

     // Exception Handling
     int number = 0;
     try{
       if(number != 0){
         cout << 2/number << endl;

       } else throw(number);

     }
      catch(int number){
        cout << number << " is not valid" << endl;
      }


     // pointers
     // sizeof returns size of container
     // can reference a memory address with reference operator &
     // create a pointer with datatype*
     cout << "Size of int " << sizeof(myAge) << endl;
     cout << "Size of char " << sizeof(myGrade) << endl;
     cout << "myAge is located at " << &myAge << endl;
     int* agePtr = &myAge; // * creates a pointer
     cout << "Address of pointer " << agePtr << endl;
     cout << "Data at memory address " << *agePtr << endl; // de-references the pointer

     int goodNums[5] = {4, 14, 13, 24, 43};
     int* numArrayPtr = goodNums;
     // increment through array
     cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;
     numArrayPtr++;
     cout << "Address " << goodNums << " Value " << *goodNums << endl; // array is a pointer to an address

     makeMeYoung(&myAge); // changes the value at myAge address
     cout << "I'm " << myAge << " years old now" << endl;
     int& ageRef = myAge;
     cout << "myAge : " << myAge << endl;
     ageRef++;
     cout << "myAge : " << myAge << endl;
     actYourAge(ageRef);
     cout << "myAge : " << myAge << endl;

     // should use pointers IF you don't want to have to initialize at the time of creation
     // also, pointers can be assigned multiple things
     // otherwise, use reference

     Animal fred;

     fred.setHeight(33);
     fred.setWeight(10);
     fred.setName("Fred");

     cout << fred.getName() << " is " << fred.getHeight() <<
         " cms tall and " << fred.getWeight() << " kgs in weight" << endl;

     Animal tom(36, 15, "Tom");

     cout << tom.getName() << " is " << tom.getHeight() <<
         " cms tall and " << tom.getWeight() << " kgs in weight" << endl;

     Dog spot(38, 16, "Spot", "Woof");
     cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;
     spot.getSound();
     spot.Animal::toString();

     Danimal *animal = new Danimal;
     Adog *dog = new Adog;

     animal->getClass(); // uses the getClass in Animal (virtual not needed; but IS needed if called from function)
     dog->getClass();

     whatClassAreYou(animal);
     whatClassAreYou(dog);

     // polymorphism: whenever an animal object is passed, polymorphism will find which method to call
     Adog rocco;
     GermanShepard max;
     Danimal* ptrAdog = &rocco;
     Danimal* ptrGermanShepard = &max;

     ptrAdog -> getFamily();
     ptrAdog -> getClass();

     ptrGermanShepard -> getFamily();
     ptrGermanShepard -> getClass();

     Danimal* pCat = new Cat;
     Danimal* pDog = new Adog;
     pCat -> makeSound();
     pDog -> makeSound();

    //  Car* stationWagon = new StationWagon();
    //  stationWagon -> getNumWheels();
     return 0; // execution went perfectly fine
}
