#include <stdio.h>

#include "GraalSample.h"

static graal_isolatethread_t * createGraalVM() {
  return EntryPoints__createIsolate__c6314d4f8cb5e822b953f5789ae2050531cad635();
}

typedef void* (*allocFn)(size_t length);

inline char* getStringFromJava(graal_isolatethread_t* t, allocFn fn) {
  return EntryPoints__getString__4163a7ca6f61f06f3e122bc4c3e521213d5013fa(t, fn);
}

int main() {
  graal_isolatethread_t* graalThread = createGraalVM();
  if (graalThread) {
    int add4 = EntryPoints__add__e294c015aa64461959a1b2cb50ba9cc185789b28(graalThread, 4);
    int sub7 = EntryPoints__sub__f889e49a63b079c60481eb876fa6a0a0575f8f04(graalThread, 7);
    fprintf(stdout, "graal results: add(4) = %d, sub(7) = %d\n", add4, sub7);
    fflush(stdout);

    allocFn fn = operator new;
    char * stringFromJava = getStringFromJava(graalThread, fn);
    fprintf(stdout, "string from graal: %s\n", stringFromJava);
    fflush(stdout);
    operator delete (stringFromJava);

    for (int i = 100; i; --i) {
      for (int i = 1000000; i; --i) {
        char * stringFromJava = getStringFromJava(graalThread, fn);
        operator delete (stringFromJava);
      }
      fprintf(stdout, "*");fflush(stdout);
    }

    int error = graal_tear_down_isolate(graalThread);
  }
}
