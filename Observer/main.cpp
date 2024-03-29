#include <iostream>
#include <vector>
using namespace std;

//OBSERVER IMPLEMENTATION WITH DIVISION
//The one which has linked the observers
class Subject {
    //The one who is receiving data from the observer
    
    //The vector will store the created observers
    vector < class Observer * > views;
    int value;
  public:
    
    //If there are observers they will be add into the vector
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    
    //Add a value to operate
    void setVal(int val) {
        value = val;
        notify();
    }
    
    //Get the enter value
    int getVal() {
        return value;
    }
    
    //Notify of any change
    void notify();
};

//The Observers
class Observer {

    Subject *model;
    int denom;
  public:
    
    //Recievin data to operate 
    Observer(Subject *mod, int div) {
        
        //Getting the variables to perate
        model = mod;
        denom = div;
        //Observers register themselves with the Subject messages
        model->attach(this);
    }
    virtual void update() = 0;
  protected:
    
    //Getting teh data from the subject 
    Subject *getSubject() {
        return model;
    }
    int getDivisor() {
        return denom;
    }
};

void Subject::notify() {
  //Update the data from the observer
    //It passes through all created observers
  for (int i = 0; i < views.size(); i++)
      //Update teh data
    views[i]->update();
}

//Thep purpose of this class is to make an operation over the created observers
class DivObserver: public Observer {
  public:
    //Make the division process
    DivObserver(Subject *mod, int div): Observer(mod, div){}
    //Will send the data
    void update() {
        //"Pull" information of interest
        int v = getSubject()->getVal(), d = getDivisor();
        //Printing the data
        cout << v << " div " << d << " is " << v / d << '\n';
    }
};

//Class to update
class ModObserver: public Observer {
  public:
    ModObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        //"Pull" information of interest
        int v = getSubject()->getVal(), d = getDivisor();
        //Printing the data
        cout << v << " mod " << d << " is " << v % d << '\n';
    }
};

int main() {
   //Subject in order to process messages
  Subject subj;
  //Three observers as an example
  DivObserver divObs1(&subj, 4); //  Client configures the number and
  DivObserver divObs2(&subj, 3); //    type of Observers
  ModObserver modObs3(&subj, 3);
  subj.setVal(14);
}
//CODE TAKEN AND ADAPTED FROM https://sourcemaking.com/design_patterns/observer/cpp/3
