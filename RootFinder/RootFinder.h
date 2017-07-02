// sample header 

#ifdef CROOTFINDER_EXPORTS
#define CROOTFINDER_API __declspec(dllexport)
#else
#define CROOTFINDER_API __declspec(dllimport)
#endif

// This class is exported from the Sample1.dll
class CROOTFINDER_API CRootFinder {
public:

    double CRootFinder::SquareRoot(double v);
};


