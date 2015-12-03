

class lock
{
  private:
   friend class A;
   lock() {}
   lock(const lock&) {}
};

class A : public virtual lock
{
  public:
  private:
};



class B : public A
{
  public:
};

int main()
{
   A a;

//   B b;
}
