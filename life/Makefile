VERSION = 0.0.1
NAME    = life

CXX      = g++
CFLAGS   = -m32 -Wall -Wextra -Wno-long-long -pedantic -nostdlib -nodefaultlibs -fno-builtin -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -fno-rtti -fno-exceptions -D___VERSION___='"${VERSION}"' -I./include -I./sources -I../../lolibc/include -I../lib
CXXFLAGS = ${CFLAGS}
LDFLAGS  = -s -L../../lolibc -static -llolibc

ifdef OPTIMIZED
CFLAGS   += -Os
CXXFLAGS += -Os
endif

DIR         = sources
MEMORY_DIR  = ${DIR}/Memory
PROCESS_DIR = ${DIR}/Process
SYSTEM_DIR  = ${DIR}/System

FILES = ${DIR}/main.cpp

all: life
	gcc ${CFLAGS} -o ${NAME} $(FILES:.cpp=.o) ${LDFLAGS}

life: $(FILES:.cpp=.o)

$(FILES:.cpp=.o): $(FILES)
	${CXX} ${CFLAGS} -o $*.o -c $*.cpp

clean:
	rm -f ${NAME}
	find sources | egrep "\.o" | xargs rm -f
