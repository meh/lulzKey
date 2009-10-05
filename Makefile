VERSION = 0.0.1
NAME    = lulzKey

CXX      = g++
CFLAGS   = -m32 -Os -Wall -Wextra -Wno-long-long -pedantic -ffreestanding -nostartfiles -nostdlib -nodefaultlibs -fno-stack-protector -fno-rtti -fno-exceptions -I./include -I./sources
CXXFLAGS = ${CFLAGS}
LDFLAGS  = -Tlinker.ld -s -melf_i386

KERNEL_FILES = main.cpp sources/Boot/Boot.cpp \
			   sources/DescriptorTables/DescriptorTables.cpp sources/DescriptorTables/Global.cpp sources/DescriptorTables/Interrupt.cpp \
			   sources/Memory/Memory.cpp \
			   sources/Process/Process.cpp sources/Process/State.cpp sources/Process/Context.cpp \
			   sources/Misc/IO.cpp \
			   sources/Tools/Shell/Shell.cpp sources/Tools/Shell/Color.cpp

all: loader kernel
	ld ${LDFLAGS} -o ${NAME} loader.o $(KERNEL_FILES:.cpp=.o)

loader:
	${CXX} ${CFLAGS} -o loader.o -c loader.S

kernel: $(KERNEL_FILES:.cpp=.o)

clean:
	find . | egrep "\.o" | xargs rm -f

