#include <stdio.h>

#include "GraalSample.h"
#include "app.h"



inline char* getStringFromJava(graal_isolatethread_t* t, allocFn fn) {
  return EntryPoints__getString__4163a7ca6f61f06f3e122bc4c3e521213d5013fa(t, (void*) fn);
}

void readJavaStringTest(graal_isolatethread_t* graalThread) {
  char * stringFromJava = getStringFromJava(graalThread, operator new);
  fprintf(stdout, "string from graal: %s\n", stringFromJava);
  fflush(stdout);
  operator delete (stringFromJava);
}

void readJavaStringStressTest(graal_isolatethread_t* graalThread) {
  fprintf(stdout, "string stress test 100m strings\n");
  fflush(stdout);
  for (int i = 100; i; --i) {
    for (int i = 1000000; i; --i) {
      char * stringFromJava = getStringFromJava(graalThread, operator new);
      operator delete (stringFromJava);
    }
    fprintf(stdout, "*");fflush(stdout);
  }
}

extern "C" void c_nativeFunction(int value) {
  fprintf(stdout, "We are in a c function value=%d\n", value);
  fflush(stdout);
}

/*int main() {
  graal_isolatethread_t* graalThread = createGraalVM();
  if (graalThread) {
    int add4 = EntryPoints__add__e294c015aa64461959a1b2cb50ba9cc185789b28(graalThread, 4);
    int sub7 = EntryPoints__sub__f889e49a63b079c60481eb876fa6a0a0575f8f04(graalThread, 7);
    fprintf(stdout, "graal results: add(4) = %d, sub(7) = %d\n", add4, sub7);
    fflush(stdout);
    EntryPoints__callCFunction__00e02d1f3e934d5331422dd566e01bfd8eb12964(graalThread, 5);

    readJavaStringTest(graalThread);
    readJavaStringStressTest(graalThread);

    int error = graal_tear_down_isolate(graalThread);
  }
}*/
