ROOTDIR = $(N64_INST)
GCCN64PREFIX = $(ROOTDIR)/bin/mips64-elf-
CHKSUM64PATH = $(ROOTDIR)/bin/chksum64
MKDFSPATH = $(ROOTDIR)/bin/mkdfs
MKSPRITE = $(ROOTDIR)/bin/mksprite
N64TOOL = $(ROOTDIR)/bin/n64tool
LINK_FLAGS = -L$(ROOTDIR)/lib -L$(ROOTDIR)/mips64-elf/lib -ldragon -lc -lm -ldragonsys -Tn64.ld
PROG_NAME = Memory64
CFLAGS = -std=gnu99 -march=vr4300 -mtune=vr4300 -O2 -Wall -Werror -I$(ROOTDIR)/mips64-elf/include -Iinclude -I/usr/local/include/
ASFLAGS = -mtune=vr4300 -march=vr4300
CC = $(GCCN64PREFIX)gcc
AS = $(GCCN64PREFIX)as
LD = $(GCCN64PREFIX)ld
OBJCOPY = $(GCCN64PREFIX)objcopy

all: $(PROG_NAME).z64

$(PROG_NAME).z64: $(PROG_NAME).bin $(PROG_NAME).dfs
	@rm -f $@
	$(N64TOOL) -l 2M -t "$(PROG_NAME)" -h $(ROOTDIR)/mips64-elf/lib/header -o $(PROG_NAME).z64 $(PROG_NAME).bin -s 1M $(PROG_NAME).dfs
	$(CHKSUM64PATH) $@

$(PROG_NAME).bin : $(PROG_NAME).elf
	$(OBJCOPY) -O binary $< $@

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
$(PROG_NAME).elf : $(OBJS)
	$(LD) -o $@ $^ $(LINK_FLAGS)


sprites:
	mkdir -p filesystem/gfx/
	$(MKSPRITE) 16 1 9 resources/gfx/logo.png filesystem/gfx/logo.sprite

sounds:
	mkdir -p filesystem/sfx/
	sox resources/sfx/A.aiff -b 16 -e signed-integer -B -r 44100 filesystem/sfx/A.raw remix -
	sox resources/sfx/B.aiff -b 16 -e signed-integer -B -r 44100 filesystem/sfx/B.raw remix -
	sox resources/sfx/C.aiff -b 16 -e signed-integer -B -r 44100 filesystem/sfx/C.raw remix -
	sox resources/sfx/start.aiff -b 16 -e signed-integer -B -r 44100 filesystem/sfx/start.raw remix -


$(PROG_NAME).dfs: sprites sounds
	$(MKDFSPATH) $@ ./filesystem/


cen64:
	$(CEN64_DIR)/cen64 $(CEN64_DIR)/pifdata.bin $(PROG_NAME).z64

docker:
	docker build -t build .
	docker run --rm build cat $(PROG_NAME).z64 > $(PROG_NAME).z64

clean:
	rm -f *.z64 *.elf src/*.o *.bin *.dfs
