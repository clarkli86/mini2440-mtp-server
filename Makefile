# Clark Li <clark.li86@gmail.com>
# Jul 2013

PROJECT := mtp

PREFIX = /opt/OSELAS.Toolchain-2012.12.0/arm-v4t-linux-gnueabi/gcc-4.7.2-glibc-2.16.0-binutils-2.22-kernel-3.6-sanitized/bin/arm-v4t-linux-gnueabi-
CXX := $(PREFIX)g++
CC := $(PREFIX)gcc

BUILDTYPE := debug
# Name of the build directory.
builddir_name ?= build
# Directory that the build goes into.
builddir ?= $(builddir_name)/$(BUILDTYPE)
objdir := $(builddir)/obj

#PROGRAM := $(builddir)/lib$(PROJECT).so
PROGRAM := $(builddir)/$(PROJECT)

C_SOURCE := \

CXX_SOURCE += \
	src/Main.cpp                              \
	src/MtpDataPacket.cpp                     \
	src/MtpDebug.cpp                          \
	src/MtpEventPacket.cpp                    \
	src/MtpObjectInfo.cpp                     \
	src/MtpPacket.cpp                         \
	src/MtpProperty.cpp                       \
	src/MtpRequestPacket.cpp                  \
	src/MtpResponsePacket.cpp                 \
	src/MtpServer.cpp                         \
	src/MtpStringBuffer.cpp                   \
	src/MtpUtils.cpp                          \
	src/MtpStorage.cpp                        \
	src/utils/VectorImpl.cpp                  \
	src/utils/SharedBuffer.cpp                \
	src/utils/String8.cpp                     \
	src/utils/Unicode.cpp                     \
#	src/MtpDevice.cpp                         \
	src/MtpDeviceInfo.cpp                     \
	src/MtpStorageInfo.cpp                    \

INCLUDES += \
	-Isrc \
	-I/home/clark/work/mini2440/platform-mini2440/sysroot-target/include/ \
	-I/home/clark/work/mini2440/platform-mini2440/sysroot-target/kernel-headers/include/ \
#	-I/home/clark/OSELAS.Toolchain-2012.12.0/platform-arm-v4t-linux-gnueabi-gcc-4.7.2-glibc-2.16.0-binutils-2.22-kernel-3.6-sanitized/build-target/linux-3.6/include/ \
	-I/home/clark/OSELAS.Toolchain-2012.12.0/platform-arm-v4t-linux-gnueabi-gcc-4.7.2-glibc-2.16.0-binutils-2.22-kernel-3.6-sanitized/build-target/linux-3.6/arch/x86/include/ \

OBJECTS := $(addprefix $(objdir)/,$(C_SOURCE:.c=.o)) $(addprefix $(objdir)/,$(CXX_SOURCE:.cpp=.o))

CFLAGS += -Wall -Wextra -g -fPIC -DMTP_DEVICE -DHAVE_PTHREADS#-Werror
#LIBFLAGS = -Wl,-soname,lib$(PROJECT).so
LIBS = -lpthread
#LDFLAGS := -shared
all: $(PROGRAM)

#linking
$(PROGRAM): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OUTPUT_OPTION) $^ $(LIBFLAGS) $(LIBS)

#compiling
$(objdir)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $(INCLUDES) $< -o $@ $(CFLAGS)

$(objdir)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(INCLUDES) $< -o $@ $(CFLAGS)

clean:
	$(RM) $(PROGRAM) $(OBJECTS) $(OBJECTS:.o=.d)

.PHONY: all clean run doc
