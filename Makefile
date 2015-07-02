CXX_FLAGS = -std=c++11 -O3 -Wall -Wextra -Wpedantic
LD_FLAGS  = -s

.PHONY : demo
demo : dll demo.exe

.PHONY : dll
dll : mtm.dll

.PHONY : clean
clean :
	rm -f *.o & \
	rm -f *.a & \
	rm -f *.def & \
	rm -f *.dll & \
	rm -f *.exe


# link everything into the dll
# these steps ensure full MSVC compatibility on Win32
mtm.dll: mtm.o stuff.o
	g++ -o mtm.dll \
           mtm.o stuff.o \
           -shared $(LD_FLAGS) -Wl,--subsystem,windows,--output-def,mtm.def & \
	g++ -o mtm.dll \
           mtm.o stuff.o \
	       -shared $(LD_FLAGS) -Wl,--subsystem,windows,--kill-at & \
	dlltool --kill-at -d mtm.def -D mtm.dll -l libmtm.a


# compile the code that goes into the dll; note the export macro
mtm.o : mtm.h mtm.cpp stuff.h
	g++ -c -D MTM_EXPORT $(CXX_FLAGS) mtm.cpp


# compile some other cpp code that goes into the dll
stuff.o : stuff.h stuff.cpp
	g++ -c $(CXX_FLAGS) stuff.cpp


# demo that uses the dll
demo.exe : mtm.dll demo.o
	g++ -o demo.exe $(LD_FLAGS) demo.o -L. -lmtm

demo.o : demo.cpp mtm.h
	g++ -c $(CXX_FLAGS) demo.cpp


