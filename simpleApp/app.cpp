#include <stdio.h>

#include "GraalSample.h"

static graal_isolatethread_t * createGraalVM() {
  return EntryPoints__createIsolate__c6314d4f8cb5e822b953f5789ae2050531cad635();
}

int main() {
  graal_isolatethread_t* graalThread = createGraalVM();
  if (graalThread) {
    int add4 = EntryPoints__add__e294c015aa64461959a1b2cb50ba9cc185789b28(graalThread, 4);
    int sub7 = EntryPoints__sub__f889e49a63b079c60481eb876fa6a0a0575f8f04(graalThread, 7);

    fprintf(stdout, "graal results: add(4) = %d, sub(7) = %d\n", add4, sub7);
    fprintf(stdout, "now kotlin ...\n", add4, sub7);
    fflush(stdout);

    EntryPoints__kotlin__d74231f5a3340d7eea0a6dba15e808ab52954adb(graalThread);
    int error = graal_tear_down_isolate(graalThread);
  }
}
