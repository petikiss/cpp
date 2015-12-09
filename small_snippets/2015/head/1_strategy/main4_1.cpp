#include <iostream>


class WeaponBehaviour
{
  public:
   virtual void useWeapon() = 0;
  protected:
};

class KnifeBehaviour : public WeaponBehaviour
{
  public:
   void useWeapon() {std::cout << "Fight with a knife!\n"; }
  protected:
};

class SwordBehaviour : public WeaponBehaviour
{
  public:
   void useWeapon() {std::cout << "Fight with a sword!\n"; }
};

class Character
{
  public:
   virtual void fight() = 0;
   void setWeapon(WeaponBehaviour* wb) { weaponBehaviour = wb; }
  protected:
   WeaponBehaviour* weaponBehaviour;
};


class Queen : public Character
{
  public:
   void fight() { weaponBehaviour->useWeapon(); }
};


int main()
{
   WeaponBehaviour* knife = new KnifeBehaviour();
   Queen q;
   q.setWeapon(knife);
   q.fight();

   WeaponBehaviour* sword = new SwordBehaviour();
   q.setWeapon(sword);
   q.fight();
}
