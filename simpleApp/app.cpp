#include <stdio.h>

#include "GraalSample.h"

static graal_isolatethread_t * createGraalVM() {
  return EntryPoints__createIsolate__c6314d4f8cb5e822b953f5789ae2050531cad635();
}

int main(int argc, char** argv) {
  graal_isolatethread_t* graalThread = createGraalVM();
  return run_main(argc, argv);
}
