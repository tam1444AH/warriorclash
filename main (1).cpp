#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Warrior {  // a base abstract class that provides the standard features of all Weaponized Warriors.

  public:
    Warrior() { // Default constructor that sets health to 100, name to “unnamed”, weaponHealth to 100, XP to 0, and Level to 1.
      health = 100;
      name = "Unnamed";
      weaponHealth = 100;
    }

    Warrior(string input, int hvalue, int wHvalue) { // Overloaded constructor that sets member variables to the following parameters.
      name = input;
      
      if (hvalue <= 0 || hvalue > 100) {
        health = 100;
      }
      else {
        health = hvalue;
      }
      
      if (wHvalue <= 0 || wHvalue > 100) {
        weaponHealth = 100;
      }
      else {
        weaponHealth = wHvalue;
      }

    }

    void incHealth(int hinc) { // Increases the health of a specific Warrior by a value inputted as a parameter.
      health = health + hinc;
    }

    void decHealth(int hdec) { // Decreases the health of a specific Warrior by a value inputted as a parameter.
      health = health - hdec;
    }

    void setHealth() { // Sets specific Warrior health to 100, default for all Warrior types.
      health = 100;
    } 

    void setHealth(int inHval) {
      
      if (inHval > 100 || inHval <= 0) {
        health = 100;
      }
      else {
        health = inHval;
      }
      
    }

    int getHealth() { // Returns the current Warrior health when called.
      return health;
    }

    void setName(string inName) { // Sets the name of a specific Warrior by a user-defined string inputted as a parameter.
      name = inName;
    }

    string getName() { // When called, returns the user-defined name of a specific Warrior.
      return name;
    }

    void setWeapHealth() { // Sets Warrior Weapon Health to 100, the default for all Warrior types.
      weaponHealth = 100;
    }

    void setWeapHealth(int inweapHealth) { // Sets Warrior Weapon Health to user-defined parameter.
      
      if (inweapHealth <= 0 || inweapHealth > 100) {
        weaponHealth = 100;
      }
      else {
        weaponHealth = inweapHealth;
      }
      
    }

    int getWeaponHealth() { // Returns Warrior Weapon Health.
      return weaponHealth;
    }
    
    void incWeaponHealth(int weapHealthinc) {  // Increases a specific Warrior’s weapon health as defined by a value inputted as a parameter.
      weaponHealth = weaponHealth - weapHealthinc;
    }

    void decWeaponHealth(int weapHealthdec) { // Decreases a specific Warrior’s weapon health as defined by a value passed as a parameter.
      weaponHealth = weaponHealth - weapHealthdec;
    }

    virtual int save(string filename) { // Saves the current attributes (health, name, etc) of a Warrior on a file, named in the parameter value, defined as virtual because every Warrior class will input its own        unique Warrior type, on top of the base variables that are shared by all Warrior types, will be overridden in child classes.
      ofstream outFS;

      outFS.open(filename);

      if (!outFS.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        return 1;
      }

      outFS << name << endl;
      outFS << health << endl;
      outFS << weaponHealth << endl;

      outFS.close();

      cout << getName() << ", the Generic Warrior, was successfully saved." << endl;

      return 0;
      
    }

    virtual int load(string filename) { // Loads from a file, named in the parameter value, a specific Warrior’s attributes, defined as virtual because every Warrior has a unique type which will be loaded from the      file, Warrior class is only abstract. Will be overridden in child classes.

      ifstream inFS;

      inFS.open(filename);

      if (!inFS.is_open()) {
        cout << "Could not open file numFile.txt." << endl;
        return 1; 
      }

      inFS >> name;
      inFS >> health;
      inFS >> weaponHealth;


      inFS.close();

      cout << getName() << ", the Generic Warrior, was successfully loaded." << endl;

      return 0;
    }

    virtual string getWarriorType() = 0;
    
  private:
    string name; // Stores current name of Warrior, inputted by user.
    int health; // Stores the health of a Warrior, which is 100 for all Warriors.
    int weaponHealth; // Stores the weapon health of a Warrior, which is 100 for all Warriors.

};

class Swordman : public Warrior { // Type of a Warrior, child class of Warrior, publicly inherits from Warrior class.

  public:
    Swordman() : Warrior() {
      warriorType = "Swordman";
    }

    Swordman(string inName, int hvalue, int inWeapHealth) : Warrior(inName, hvalue, inWeapHealth)  {
      warriorType = "Swordman";
    }

    void swordStrike() { // Basic Ability available at Level 1, deals 8 damage to the enemy Warrior, whilst using 7 weapon health to use this ability. Earns 5XP by using this ability. Returns a unique message           on its usage by the Warrior.
      
      decWeaponHealth(7);
      
      
      cout << getName() << " , the Swordman, used Basic Ability: Swordstrike! Dealt 8 damage to the opponent! Used 7 Weapon Health by this move!" << endl;

    }

    void defensiveHeal() { // Primary Ability, unlocked at Level 2, Level 2 being attained by earning 10 total XP points. While using this ability you gain 10 health, taking 8 of your weapon health, earn 7 XP.          Returns a unique message on its usage by the Warrior.

      incHealth(10);

      decWeaponHealth(8);

      cout << getName() << ", the Swordman, used Primary Ability: Defensive Heal! Gained 10 health by this move! Used 8 Weapon Health from this move!" << endl;

    }

    void swordTornado() { // Ultimate Ability, unlocks at Level 3. Level 3 is attained by earning a total of 30 XP points. Charges at enemy Warrior in a circular fashion. Deal 20 damage to the enemy, whilst             using 18 weapon health to pull this off. Returns a unique message on its usage by the Warrior.

      decWeaponHealth(18);

      cout << getName() << ", THE SWORDMAN, USED ULTIMATE ABILITY: SWORD TORNADO! DEALT 20 DAMAGE TO THE OPPONENT! USED 18 WEAPON HEALTH TO PULL OFF THIS MOVE!" << endl;

    }

    int save(string filename) { // Saves the current attributes of the Warrior to a file, named in the parameter value.
      
      ofstream outFS;

      outFS.open(filename);

      if (!outFS.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        return 1;
      }

      outFS << getName() << endl;
      outFS << warriorType << endl;
      outFS << getHealth() << endl;
      outFS << getWeaponHealth() << endl;


      outFS.close();

      cout << getName() << ", the Swordman, was successfully saved." << endl;

      return 0;
      
    } 

    int load(string filename) { // Loads the attributes of the Warrior from a file, named in the parameter value, and sets the Warrior attributes equal to the ones in the file.

      ifstream inFS;

      inFS.open(filename);

      if (!inFS.is_open()) {
        cout << "Could not open file numFile.txt." << endl;
        return 1; 
      }

      string warriorName;
      inFS >> warriorName;
      setName(warriorName);

      int warriorHealthVal;
      inFS >> warriorHealthVal;
      setHealth(warriorHealthVal);

      int warriorWeapHVal;
      inFS >> warriorHealthVal;
      setWeapHealth(warriorHealthVal);

      inFS.close();

      cout << getName() << ", the Swordman, was successfully loaded." << endl;

      return 0;
      
    } 

    string getWarriorType() { // Returns the current warrior type which in this case is “Swordman”.
      return warriorType;
    } 

  private:
    string warriorType; // Variable that holds the unique type of the Warrior, cannot be modified by the user.
    
};

class Spearman : public Warrior {

  public:
    Spearman() : Warrior() { // Default constructor that sets health to 100, name to “unnamed”, weaponHealth to 100, XP to 0, and Level to 1, by using the default constructor of the parent class Warrior.
      warriorType = "Spearman";
    }

    Spearman(string inName, int hvalue, int inWeapHealth) : Warrior(inName, hvalue, inWeapHealth) { // Overloaded constructor that sets member variables to the following parameters by using the overloaded constructor of the parent class Warrior.
      warriorType = "Spearname";
    }

    void spearThrow() { // Basic Ability available at Level 1, deals 7 damage to the enemy Warrior, whilst using 5 weapon health to use this ability. Earns 5XP by using this ability. Returns a unique message on         its usage by the Warrior.

      decWeaponHealth(5);

      

      cout << getName() << ", the Spearman, used Basic Ability: Spear Throw! Dealt 7 damage to the opponent! Used 5 Weapon Health by this move!" << endl;
        
    }

    void doubleSpear() { // Primary Ability, unlocked at Level 2, Level 2 being attained by earning 10 total XP points. Throw two spears at once. Deal 10 damage to the enemy. While using this ability you gain 10        health, using 10 of your weapon health, earn 6 XP. Returns a unique message on its usage by the Warrior.

      incHealth(10);

      decWeaponHealth(10);

      

      cout << getName() << ", the Spearman, used Primary Ability: Double Spear! Dealt 10 damage to the opponent! Used 10 Weapon Health by this move!" << endl;
      
    }

    void spearCharge() { // Ultimate Ability, unlocks at Level 3. Level 3 is attained by earning a total of 30 XP points. Charges at enemy Warrior with the spear in hand. Deal 35 damage to the enemy, whilst using       25 weapon health to pull this off. Returns a unique message on its usage by the Warrior.

      decWeaponHealth(25);

      cout << getName() << ", THE SPEARMAN, USED ULITMATE ABILITY: SPEAR CHARGE! DEALT 35 DAMAGE TO THE OPPONENT! USED 25 WEAPON HEALTH BY THIS MOVE!" << endl;

    }

    int save(string filename) { // Saves the current attributes of the Warrior to a file, named in the parameter value.
      
      ofstream outFS;

      outFS.open(filename);

      if (!outFS.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        return 1;
      }

      outFS << getName() << endl;
      outFS << warriorType << endl;
      outFS << getHealth() << endl;
      outFS << getWeaponHealth() << endl;


      outFS.close();

      cout << getName() << ", the Spearman, was successfully saved." << endl;
      
      return 0;
      
    } 

    int load(string filename) { // Loads the attributes of the Warrior from a file, named in the parameter value, and sets the Warrior attributes equal to the ones in the file.
      
      ifstream inFS;

      inFS.open(filename);

      if (!inFS.is_open()) {
        cout << "Could not open file numFile.txt." << endl;
        return 1; 
      }

      string warriorName;
      inFS >> warriorName;
      setName(warriorName);

      int warriorHealthVal;
      inFS >> warriorHealthVal;
      setHealth(warriorHealthVal);

      int warriorWeapHVal;
      inFS >> warriorHealthVal;
      setWeapHealth(warriorHealthVal);


      inFS.close();

      cout << getName() << ", the Spearman, was successfully loaded." << endl;

      return 0;
      
    }

    string getWarriorType() { // Returns the current warrior type which in this case is “Spearman”.
      return warriorType;
    }

  private:
    string warriorType; // Variable that holds the unique type of the Warrior, cannot be modified by the user.
    
};

class Bowman : public Warrior { 

  public:
    Bowman() : Warrior() { // Default constructor that sets health to 100, name to “unnamed”, weaponHealth to 100, XP to 0, and Level to 1, by using the default constructor of the parent class Warrior.
      warriorType = "Bowman";
    }

    Bowman(string inName, int hvalue, int inWeapHealth, int xpVal, int levelVal) : Warrior(inName, hvalue, inWeapHealth) { // Overloaded constructor that sets member variables to the following          parameters by using the overloaded constructor of the parent class Warrior.
      warriorType = "Bowman";
    }

    void arrowShoot() { // Basic Ability available at Level 1, deals 5 damage to the enemy Warrior, whilst using 4 weapon health to use this ability. Earns 10XP by using this ability. Returns a unique message on        its usage by the Warrior.

      decWeaponHealth(4);

      

      cout << getName() << ", the Bowman, used Basic Ability: Arrow Shoot! Dealt 5 damage to the opponent! Used 4 Weapon Health by this move!" << endl;

    }

    void defensiveRepair() { // Primary Ability, unlocked at Level 2, Level 2 being attained by earning 10 total XP points. Bowman repairs his weapon. Increases his weapon health by 10, whilst using 5 weapon health     to do this. Earns 5XP by using this ability. Returns a unique message on its usage by the Warrior.

      incWeaponHealth(10);

      decWeaponHealth(5);

      

      cout << getName() << ", the Bowman, used Primary Ability: Defensive Repair! Increased Weapon Health by 10! Used 5 Weapon Health by this move!" << endl;
      
    }

    void arrowBarrage() { // Ultimate Ability, unlocks at Level 3. Level 3 is attained by earning a total of 30 XP points. Fires a barrage of arrows towards the opponent. Deals 30 damage to the enemy, whilst using      15 weapon health to pull this off. Returns a unique message on its usage by the Warrior.

      decWeaponHealth(15);

      cout << getName() << ", THE BOWMAN, USED ULTIMATE ABILITY: ARROW BARRAGE! DEALT 30 DAMAGE TO THE OPPONENT! USED 15 WEAPON HEALTH BY THIS MOVE!" << endl;
      
    }

    int save(string filename) { // Saves the current attributes of the Warrior to a file, named in the parameter value.
      
      ofstream outFS;

      outFS.open(filename);

      if (!outFS.is_open()) {
        cout << "Could not open file myoutfile.txt." << endl;
        return 1;
      }

      outFS << getName() << endl;
      outFS << warriorType << endl;
      outFS << getHealth() << endl;
      outFS << getWeaponHealth() << endl;


      outFS.close();

      cout << getName() << ", the Bowman, was successfully saved." << endl;
      
      return 0;
      
    } 

    int load(string filename) { // Loads the attributes of the Warrior from a file, named in the parameter value, and sets the Warrior attributes equal to the ones in the file.

      ifstream inFS;

      inFS.open(filename);

      if (!inFS.is_open()) {
        cout << "Could not open file numFile.txt." << endl;
        return 1; 
      }

      string warriorName;
      inFS >> warriorName;
      setName(warriorName);

      int warriorHealthVal;
      inFS >> warriorHealthVal;
      setHealth(warriorHealthVal);

      int warriorWeapHVal;
      inFS >> warriorHealthVal;
      setWeapHealth(warriorHealthVal);



      inFS.close();

      cout << getName() << ", the Bowman, was successfully loaded." << endl;

      return 0;
      
    }

    string getWarriorType() { // Returns the current warrior type which in this case is “Bowman”.
      return warriorType;
    }

  private:
    string warriorType; // Variable that holds the unique type of the Warrior, cannot be modified by the user.
    
};

// Note: The first Warrior to reach 0 health OR insufficient weapon health to use any ability loses.

int main() {

  Swordman player1;
  Spearman player2;
  player1.setName("Bob");
  player2.setName("Rob");

  int input1;
  int input2;
  
  while (input1 != 0 || input2 != 0) {
    cout << "Choose an ability for your Swordman, Player 1!: " << endl;
    cout << "1. Basic Ability: Swordstrike" << endl;
    cout << "2. Primary Ability: Defensive Heal" << endl;
    cout << "3. Ultimate Ability: Sword Tornado" << endl;

    cin >> input1;
    cout << endl;

    if (input1 == 1) {
      player1.swordStrike();
      player2.decHealth(8);
    }

    else if (input1 == 2) {
      player1.defensiveHeal();
    }

    else if (input1 == 3) {
      player1.swordTornado();
      player2.decHealth(20);
    }

    cout << "Choose an ability for your Spearman, Player 2!: " << endl;
    cout << "1. Basic Ability: Spear Throw" << endl;
    cout << "2. Primary Ability: Double Spear" << endl;
    cout << "3. Ultimate Ability: Spear Charge " << endl;

    cin >> input2;
    cout << endl;

    if (input2 == 1) {
      player2.spearThrow();
      player1.decHealth(7);
    }

    else if (input2 == 2) {
      player2.doubleSpear();
      player1.decHealth(10);
    }

    else if (input2 == 3) {
      player2.spearCharge();
      player1.decHealth(35);
    }

    cout << "Player 1 health: " << player1.getHealth() << " . Weapon Health: " << player1.getWeaponHealth() << "." << endl;
    cout << "Player 2 health: " << player2.getHealth() << " . Weapon Health: " << player2.getWeaponHealth() << "." << endl;

    if (player1.getHealth() <= 0 || player1.getWeaponHealth() <= 0) {
      cout << "Player 2 won!" << endl;
      break;
    }

    else if (player2.getHealth() <= 0 || player2.getHealth() <= 0) {
      cout << "Player 1 won!" << endl;
      break;
    } 
  }

  
  return 0;
}                                                                  