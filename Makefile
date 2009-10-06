VERSION = 0.0.1
NAME    = lulzKey

CXX      = g++
CFLAGS   = -m32 -Os -Wall -Wextra -Wno-long-long -pedantic -ffreestanding -nostartfiles -nostdlib -nodefaultlibs -fno-stack-protector -fno-rtti -fno-exceptions -I./include -I./sources
CXXFLAGS = ${CFLAGS}
LDFLAGS  = -Tlinker.ld -s -melf_i386

KERNEL_FILES = main.cpp sources/Boot/Boot.cpp \
			   sources/DescriptorTables/DescriptorTables.cpp sources/DescriptorTables/Global.cpp sources/DescriptorTables/Interrupt.cpp \
			   sources/Interrupt/Interrupt.cpp \
			   sources/Memory/Memory.cpp \
			   sources/Process/Process.cpp sources/Process/State.cpp sources/Process/Context.cpp \
			   sources/Misc/IO.cpp \
			   sources/Tools/Shell/Shell.cpp sources/Tools/Shell/Color.cpp

ASM_FILES = loader.S sources/DescriptorTables/Global.S sources/Interrupt/ServiceRoutine.S

all: kernel_asm kernel
	ld ${LDFLAGS} -o ${NAME} $(ASM_FILES:.S=_.o) $(KERNEL_FILES:.cpp=.o)

kernel_asm: $(ASM_FILES:.S=_.o)

$(ASM_FILES:.S=_.o): $(ASM_FILES)
	${CXX} ${CFLAGS} -o $*.o -c $(shell echo "$*" | sed 's/_$$//').S

kernel: $(KERNEL_FILES:.cpp=.o)

$(KERNEL_FILES:.cpp=.o): $(KERNEL_FILES)
	${CXX} ${CFLAGS} -o $*.o -c $*.cpp

clean:
	find . | egrep "\.o" | xargs rm -f

