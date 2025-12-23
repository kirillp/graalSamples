cd target

dylib=GraalSample
graal_dylib=$dylib.dylib

otool -L $graal_dylib

clang++ -O1 -I./ -g -c ../App.cpp -o App.o

#clang++ -O1 -I./ -o App.exe ../App.cpp $graal_dylib
clang++ -O1 -I./ -o main.exe ../main.cpp App.o $graal_dylib
otool -L main.exe
./main.exe