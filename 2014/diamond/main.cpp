
class Base
{
  public:
  protected:
    int data_;
};

class Der1 : virtual public Base {  };

class Der2 : virtual public Base {  };

class Join : public Der1, public Der2 {
public:
  void method()
  {
      data_ = 1;  // ← bad: this is ambiguous; see below
  }
};

int main()
{
  Join* j = new Join();
  Base* b = j;  //  ← bad: this is ambiguous; see below
}
