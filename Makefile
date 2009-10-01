VERSION = 0.0.1
NAME    = lulzKey

LINKER_FILE = linker.ld

CXX     = g++
CFLAGS  = -m32 -Os -Wall -Wextra -pedantic -nostartfiles -nostdlib -nodefaultlibs -fno-rtti -fno-exceptions -I./include -I./sources

KERNEL_FILES = main.cpp sources/Memory/Memory.cpp
LOADER_FILE  = loader.cpp

all: loader kernel
	ld -melf_i386 -T ${LINKER_FILE} -o ${NAME} $(LOADER_FILE:.cpp=.o) $(KERNEL_FILES:.cpp=.o)

loader:
	as --32 -o loader.o loader.s

kernel: $(KERNEL_FILES:.cpp=.o)

$(KERNEL_FILES:.cpp=.o): $(KERNEL_FILES)
	${CXX} ${CFLAGS} -fPIC -o $*.o -c $*.cpp

clean:
	find . | egrep "\.o" | xargs rm -f

