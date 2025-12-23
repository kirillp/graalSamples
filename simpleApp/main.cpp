#include <stdio.h>

#include "GraalSample.h"
#include "app.h"


int main() {
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
  }