VERSION = 0.0.1
NAME    = lulzKey

CXX      = g++
CFLAGS   = -m32 -Wall -Wextra -Wno-long-long -pedantic -ffreestanding -nostartfiles -nostdlib -nodefaultlibs -fno-builtin -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-rtti -fno-exceptions -D___VERSION___='"${VERSION}"' -I./include -I./sources -I./lolibc/include
CXXFLAGS = ${CFLAGS}
LDFLAGS  = -T linker.ld -s -L./lolibc -static -llolibc

ifdef OPTIMIZED
CFLAGS   += -Os
CXXFLAGS += -Os
endif

ifdef PANIC
CFLAGS += -D_${PANIC}
else
CFLAGS += -D_NAZI
endif

DIR        = sources
FORMAT_DIR = ${DIR}/Format

KERNEL_FILES = ${DIR}/main.cpp ${DIR}/Boot/Multiboot.cpp ${DIR}/Kernel.cpp \
			   ${DIR}/Memory/Memory.cpp \
			   ${DIR}/Services/Services.cpp \
			   ${DIR}/Interrupt/Interrupt.cpp \
			   ${DIR}/Misc/IO.cpp \
			   ${DIR}/Tools/Shell/Shell.cpp ${DIR}/Tools/Shell/Color.cpp \
			   ${DIR}/Tools/Debug/Debug.cpp

ASM_FILES = ${DIR}/loader.S

ELF_FILES = ${FORMAT_DIR}/ELF/ELF.cpp \
			${FORMAT_DIR}/ELF/Header.cpp ${FORMAT_DIR}/ELF/ProgramHeader.cpp ${FORMAT_DIR}/ELF/SectionHeader.cpp \
			${FORMAT_DIR}/ELF/Symbol.cpp ${FORMAT_DIR}/ELF/Relocation.cpp ${FORMAT_DIR}/ELF/Dynamic.cpp

ARCH = x86

ifeq ("${ARCH}", "x86")
CFLAGS += -D_LKEY_X86 -D_LOLIBC_X86

x86_DIR = sources/Processor/x86

KERNEL_FILES += ${x86_DIR}/Processor.cpp \
				${x86_DIR}/DescriptorTables/DescriptorTables.cpp ${x86_DIR}/DescriptorTables/Global.cpp ${x86_DIR}/DescriptorTables/Interrupt.cpp \
				${x86_DIR}/Interrupt/Interrupts.cpp \
				${x86_DIR}/Memory/Memory.cpp ${x86_DIR}/Memory/Paging.cpp ${x86_DIR}/Memory/Frame.cpp

ASM_FILES    += ${x86_DIR}/DescriptorTables/Global.S ${x86_DIR}/DescriptorTables/Interrupt.S \
				${x86_DIR}/Interrupt/ServiceRoutine.S ${x86_DIR}/Interrupt/Request.S

KERNEL_FILES += ${ELF_FILES}
endif

all: kernel_asm kernel
	gcc ${CFLAGS} -o ${NAME} $(ASM_FILES:.S=_.o) $(KERNEL_FILES:.cpp=.o) ${LDFLAGS} 

kernel_asm: $(ASM_FILES:.S=_.o)

$(ASM_FILES:.S=_.o): $(ASM_FILES)
	${CXX} ${CFLAGS} -o $*.o -c $(shell echo "$*" | sed 's/_$$//').S

kernel: $(KERNEL_FILES:.cpp=.o)

$(KERNEL_FILES:.cpp=.o): $(KERNEL_FILES)
	${CXX} ${CFLAGS} -o $*.o -c $*.cpp

clean:
	rm -f ${NAME}
	find sources | egrep "\.o" | xargs rm -f

