cd target

dylib=GraalSample
graal_dylib=$dylib.dylib

otool -L $graal_dylib

clang++ -O1 -I./ -o App.exe ../App.cpp $graal_dylib
otool -L App.exe

