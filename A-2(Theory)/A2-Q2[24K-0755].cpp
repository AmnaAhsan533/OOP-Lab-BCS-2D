#include <iostream>
#include <random>

using namespace std;

class Visitor {
private:
    string name;
    int bravery;

public:
    Visitor(string name, int bravery) : name(name), bravery(bravery) {}

    void reactToHaunt(int scareLevel) const {
        if (scareLevel > bravery + 2) {
            cout << name << " screams and runs away!" << endl;
        } else if (scareLevel < bravery - 2) {
            cout << name << " laughs and taunts the ghost!" << endl;
        } else {
            cout << name << " has a shaky voice!" << endl;
        }
    }
};

class Ghost {
protected:
    string worker;
    int scareLevel;

public:
    Ghost(string worker) : worker(worker), scareLevel(rand() % 10 + 1) {}

    virtual ~Ghost() = default;

    virtual void haunt() const {
        cout << worker << " (Generic Ghost) makes eerie noises!" << endl;
    }

    friend ostream& operator<<(ostream& os, const Ghost& ghost) {
        os<<"Ghost played by: "<<ghost.worker<<", Scare Level: "<<ghost.scareLevel;
        return os;
    }

    virtual int getScareLevel() const { return scareLevel; }

    Ghost* operator+(const Ghost& other) const {
        Ghost* newGhost = new Ghost(worker + " & " + other.worker);
        newGhost->scareLevel = this->scareLevel + other.scareLevel;  
        return newGhost;
    }
    
};

class Poltergeist : virtual public Ghost {
public:
    Poltergeist(string worker) : Ghost(worker) {}

    void haunt() const override {
        cout <<"\n"<< worker << " (Poltergeist) moves objects around!" << endl;
    }
};

class ShadowGhost : virtual public Ghost {
public:
    ShadowGhost(string worker) : Ghost(worker) {}

    void haunt() const override {
        cout <<"\n"<< worker << " (ShadowGhost) whispers creepily!" << endl;
    }
};

class Banshee : public Ghost {
public:
    Banshee(string worker) : Ghost(worker) {}

    void haunt() const override {
        cout <<"\n"<< worker << " (Banshee) screams loudly!" << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost {
public:
    ShadowPoltergeist(string worker) : 
        Ghost(worker), Poltergeist(worker), ShadowGhost(worker) {}

    void haunt() const override {
        Poltergeist::haunt();
        ShadowGhost::haunt();
    }
};

class HauntedHouse {
private:
    string name;
    Ghost** ghosts;
    int ghostCount;
    int capacity;

public:
    HauntedHouse(string name) : name(name), ghostCount(0), capacity(2) {
        ghosts = new Ghost*[capacity];
    }

    ~HauntedHouse() {
        for (int i = 0; i < ghostCount; ++i) {
            delete ghosts[i];
        }
        delete[] ghosts;
    }

    void addGhost(Ghost* ghost) {
        if (ghostCount == capacity) {
            capacity *= 2;
            Ghost** newGhosts = new Ghost*[capacity];
            for (int i = 0; i < ghostCount; ++i) {
                newGhosts[i] = ghosts[i];
            }
            delete[] ghosts;
            ghosts = newGhosts;
        }
        ghosts[ghostCount++] = ghost;
    }

    string getName() const { return name; }

    void hauntVisitors(const Visitor visitors[], int visitorCount) const {
        cout << "Visitors are entering " << name << "...\n";
        for (int i = 0; i < ghostCount; ++i) {
            ghosts[i]->haunt();
            cout<<endl;
            for (int j = 0; j < visitorCount; ++j) {
                visitors[j].reactToHaunt(ghosts[i]->getScareLevel());
                
            }
        }
    }
};

void visit(const Visitor visitors[], int visitorCount, const HauntedHouse& house) {
    house.hauntVisitors(visitors, visitorCount);
}

int main() {
    cout<<"Amna Ahan\nID: 24K-0755\n";
    srand(time(0));

    // Creating ghosts
    Ghost* ghost1 = new Poltergeist("Jake");
    Ghost* ghost2 = new ShadowGhost("Lucas");

    // Combine the two ghosts using the operator+
    Ghost* combinedGhost = *ghost1 + *ghost2;

    cout << "Combined Ghost: " << *combinedGhost << endl;
    delete ghost1;
    delete ghost2;
    delete combinedGhost;
    cout<<endl;

    HauntedHouse house1("Error 404: SOUL NOT FOUND");
    house1.addGhost(new Poltergeist("Digital Demon"));
    house1.addGhost(new Banshee("Codeyy"));
    house1.addGhost(new ShadowGhost("Glitch"));

    HauntedHouse house2("The Dark Side of the CODE");
    house2.addGhost(new ShadowPoltergeist("Anna"));

    Visitor visitors[] = {
        Visitor("Aisha", 2),
        Visitor("Asma", 6),
        Visitor("Amna", 9)
    };

    int visitorCount = sizeof(visitors) / sizeof(visitors[0]);

    visit(visitors, visitorCount, house1);
    cout<<endl;
    visit(visitors, visitorCount, house2);

    return 0;
}
