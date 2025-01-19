#include <iostream>
#include <string>

using namespace std;

// Base class
class Instrument {
protected:
    string name;
    string type;
public:
    // Constructor to initialize the instrument's name and type
    Instrument(string n, string t) : name(n), type(t) {}

    virtual ~Instrument() {}

    // Virtual function to play a generic sound
    virtual void playSound() const {
        cout << "Playing a generic sound." << endl;
    }

    // Static binding function: Displays a generic instrument type
    void instrumentType() const {
        cout << "This is a musical instrument." << endl;
    }

    // Pure virtual function to get the instrument's details
    virtual string getInstrumentDetails() const = 0; 
};

// Derived class for Guitar
class Guitar : public Instrument {
private:
    double stringCount; // Number of strings
public:
    // Constructor to initialize the name, type, and string count
    Guitar(string n, double s) : Instrument(n, "String"), stringCount(s) {}

    // Override playSound to simulate the guitar sound
    void playSound() const override {
        cout << "Strumming guitar sound!" << endl;
    }

    // Override getInstrumentDetails to return specific details for Guitar
    string getInstrumentDetails() const override {
        return "Guitar: " + name + " (Type: " + type + ", Strings: " + to_string(stringCount) + ")";
    }

    // Static binding method for instrument type (Guitar)
    void instrumentType() const {
        cout << "This is a Guitar." << endl;
    }
};

// Derived class for Piano
class Piano : public Instrument {
private:
    int keyCount; // Number of keys
public:
    // Constructor to initialize the name, type, and key count
    Piano(string n, int k) : Instrument(n, "Percussion"), keyCount(k) {}

    // Override playSound to simulate the piano sound
    void playSound() const override {
        cout << "Piano sound with keys!" << endl;
    }

    // Override getInstrumentDetails to return specific details for Piano
    string getInstrumentDetails() const override {
        return "Piano: " + name + " (Type: " + type + ", Keys: " + to_string(keyCount) + ")";
    }

    // Static binding method for instrument type (Piano)
    void instrumentType() const {
        cout << "This is a Piano." << endl;
    }
};


int main() {
    // Static Binding
    Instrument* instrument = new Instrument("Generic", "Unknown");
    instrument->instrumentType(); // Calls base class method (Static Binding)

    Guitar guitar("Fender Stratocaster", 6);
    guitar.instrumentType(); // Calls Guitar's method (Static Binding)

    Piano piano("Yamaha Grand", 88);
    piano.instrumentType(); // Calls Piano's method (Static Binding)


    // Dynamic Binding
    Instrument* i1 = new Guitar("Gibson Les Paul", 6);
    Instrument* i2 = new Piano("Steinway", 88);

    cout << "Instrument 1 Details: " << i1->getInstrumentDetails() << endl;
    i1->playSound();

    cout << "Instrument 2 Details: " << i2->getInstrumentDetails() << endl;
    i2->playSound();
}
