#include <iostream>

// Debug版本带日志，Release版本不带日志
#ifdef  Debug
#define log(str)  std::cout << str;
#else
#define log(str)
#endif

const char *getAnimal() {
#if defined(CAT)
    return "cat";
#elif defined(DOG)
    return "dog";
#else
    return "unknown";
#endif
}

int main() {

#if defined(Debug)
    std::cout << "debug mode" << std::endl;
#elif  defined(Release)
    std::cout << "release mode" << std::endl;
#endif

#ifdef PLATFORM
    log("platform is ")
    log(PLATFORM)
    log(std::endl)
#endif
    log(getAnimal())
    return 0;
}