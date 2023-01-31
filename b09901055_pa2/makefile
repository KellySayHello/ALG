# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c -mcmodel=large
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O2

all	: bin/mps
	@echo -n ""

# optimized version
bin/mps	: maxPlanarSubset_opt.o main_opt.o 
			$(CC) $(OPTFLAGS) maxPlanarSubset_opt.o main_opt.o -o bin/mps
main_opt.o 	   	: src/main.cpp 
			$(CC) $(CFLAGS) $< -o $@
maxPlanarSubset_opt.o	: src/maxPlanarSubset.cpp src/maxPlanarSubset.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@

# DEBUG Version
dbg : bin/MaxPlanarSubset_dbg
	@echo -n ""

bin/mps_dbg	: maxPlanarSubset_dbg.o main_dbg.o 
			$(CC) $(DBGFLAGS) maxPlanarSubset_dbg.o main_dbg.o  -o bin/maxPlanarSubset_dbg
main_dbg.o 	   	: src/main.cpp lib/tm_usage.h
			$(CC) $(CFLAGS) $< -Ilib -o $@
maxPlanarSubset_dbg.o	: src/maxPlanarSubset.cpp src/maxPlanarSubset_tool.h
			$(CC) $(CFLAGS) $(DBGFLAGS) $< -o $@

lib: lib/libtm_usage.a

lib/libtm_usage.a: tm_usage.o
	$(AR) $(ARFLAGS) $@ $<
tm_usage.o: lib/tm_usage.cpp lib/tm_usage.h
	$(CC) $(CFLAGS) $<

# clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*

