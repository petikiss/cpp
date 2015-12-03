class Usable;

class Usable_lock
{
   friend class Usable;
  private:
   Usable_lock() {}
   Usable_lock(const Usable_lock&) {}
};

// class Usable : private virtual Usable_lock
class Usable : private Usable_lock
{
  public:
   Usable() {};
   Usable(char*) {};
};


class DD : public Usable
{
};


int main()
{
   Usable a;


   DD dd;  // error: DD::DD() cannot access
           // Usable_lock::Usable_lock(): private  member
}
