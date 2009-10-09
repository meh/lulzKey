VERSION = 0.0.1
NAME    = lulzKey

CXX      = g++
CFLAGS   = -m32 -Os -Wall -Wextra -Wno-long-long -pedantic -ffreestanding -nostartfiles -nostdlib -nodefaultlibs -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-rtti -fno-exceptions -I./include -I./sources
CXXFLAGS = ${CFLAGS}
LDFLAGS  = -Tlinker.ld -s -melf_i386

KERNEL_FILES = sources/main.cpp sources/Boot/Multiboot.cpp sources/Kernel.cpp \
			   sources/Services/Services.cpp \
			   sources/Misc/IO.cpp \
			   sources/Tools/Shell/Shell.cpp sources/Tools/Shell/Color.cpp \
			   sources/Tools/Debug/Debug.cpp

ASM_FILES    = sources/loader.S

ARCH = x86

ifeq ("${ARCH}", "x86")
CFLAGS += -D_LKEY_X86

KERNEL_FILES += sources/Processor/x86/Processor.cpp
ASM_FILES    +=
endif

all: kernel_asm kernel
	ld ${LDFLAGS} -o ${NAME} $(ASM_FILES:.S=_.o) $(KERNEL_FILES:.cpp=.o)

kernel_asm: $(ASM_FILES:.S=_.o)

$(ASM_FILES:.S=_.o): $(ASM_FILES)
	${CXX} ${CFLAGS} -o $*.o -c $(shell echo "$*" | sed 's/_$$//').S

kernel: $(KERNEL_FILES:.cpp=.o)

$(KERNEL_FILES:.cpp=.o): $(KERNEL_FILES)
	${CXX} ${CFLAGS} -o $*.o -c $*.cpp

clean:
	rm -f ${NAME}
	find . | egrep "\.o" | xargs rm -f

