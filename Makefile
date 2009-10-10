VERSION = 0.0.1
NAME    = lulzKey

CXX      = g++
CFLAGS   = -Os -m32 -Wall -Wextra -Wno-long-long -pedantic -ffreestanding -nostartfiles -nostdlib -nodefaultlibs -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-rtti -fno-exceptions -D___VERSION___='"${VERSION}"' -I./include -I./sources
CXXFLAGS = ${CFLAGS}
LDFLAGS  = -Tlinker.ld -s -melf_i386

DIR = sources

KERNEL_FILES = ${DIR}/main.cpp ${DIR}/Boot/Multiboot.cpp ${DIR}/Kernel.cpp \
			   ${DIR}/Memory/Memory.cpp \
			   ${DIR}/Services/Services.cpp \
			   ${DIR}/Interrupt/Interrupt.cpp \
			   ${DIR}/Misc/IO.cpp \
			   ${DIR}/Tools/Shell/Shell.cpp ${DIR}/Tools/Shell/Color.cpp \
			   ${DIR}/Tools/Debug/Debug.cpp

ASM_FILES    = ${DIR}/loader.S

ARCH = x86

ifeq ("${ARCH}", "x86")
CFLAGS += -D_LKEY_X86

x86_DIR = sources/Processor/x86

KERNEL_FILES += ${x86_DIR}/Processor.cpp ${DIR}/Format/ELF.cpp \
				${x86_DIR}/DescriptorTables/DescriptorTables.cpp ${x86_DIR}/DescriptorTables/Global.cpp ${x86_DIR}/DescriptorTables/Interrupt.cpp

ASM_FILES    += ${x86_DIR}/DescriptorTables/Global.S ${x86_DIR}/DescriptorTables/Interrupt.S \
				${x86_DIR}/Interrupt/ServiceRoutine.S ${x86_DIR}/Interrupt/Request.S
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

