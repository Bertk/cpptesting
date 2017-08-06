#ifndef COMPONENT1_HH
#define COMPONENT1_HH

#ifdef SQTEST_EXPORTS
#define SQTEST_API __declspec(dllexport)
#else
#define SQTEST_API __declspec(dllimport)
#endif

class SQTEST_API Bar {
public:

  Bar::Bar() {
  }   
    
  int foo();
  void do_valgrind_errors();
};
#endif
