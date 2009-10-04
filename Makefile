VERSION = 0.0.1
NAME    = lulzKey

LINKER_FILE = linker.ld

CXX     = g++
CFLAGS  = -m32 -Os -Wall -Wextra -pedantic -ffreestanding -nostartfiles -nostdlib -nodefaultlibs -fno-rtti -fno-exceptions -I./include -I./sources

KERNEL_FILES = main.cpp sources/Boot/Boot.cpp \
			   sources/Memory/Memory.cpp \
			   sources/Process/Process.cpp sources/Process/State.cpp sources/Process/Context.cpp \
			   sources/Misc/IO.cpp \
			   sources/Tools/Shell/Shell.cpp sources/Tools/Shell/Color.cpp

all: loader kernel
	ld -s -melf_i386 -T ${LINKER_FILE} -o ${NAME} loader.o $(KERNEL_FILES:.cpp=.o)

loader:
	${CXX} ${CFLAGS} -o loader.o -c loader.s

kernel: $(KERNEL_FILES:.cpp=.o)

$(KERNEL_FILES:.cpp=.o): $(KERNEL_FILES)
	${CXX} ${CFLAGS} -fPIC -o $*.o -c $*.cpp

clean:
	find . | egrep "\.o" | xargs rm -f

