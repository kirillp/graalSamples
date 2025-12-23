#ifndef __APPSAMPLE_H
#define __APPSAMPLE_H

static graal_isolatethread_t * createGraalVM() {
  return EntryPoints__createIsolate__c6314d4f8cb5e822b953f5789ae2050531cad635();
}

typedef void* (*allocFn)(size_t length);

void readJavaStringTest(graal_isolatethread_t* graalThread);

void readJavaStringStressTest(graal_isolatethread_t* graalThread);

#endif

