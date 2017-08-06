#ifndef COMPONENT2_HH
#define COMPONENT2_HH

#ifdef SQTEST_EXPORTS
#define SQTEST_API __declspec(dllexport)
#else
#define SQTEST_API __declspec(dllimport)
#endif

class SQTEST_API Foo {
public:
    int foo();
    void do_valgrind_errors();
};
#endif
