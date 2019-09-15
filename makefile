CC= g++
LIB =
LIB_DIR =
LDFLAGS =
CFLAGS = -g -std=gnu++0x

FILE_SUFFIX = cpp
SRCS := $(wildcard *.$(FILE_SUFFIX))
EXES := $(patsubst %.$(FILE_SUFFIX),%,$(SRCS))

all:$(EXES)

$(EXES): % : %.$(FILE_SUFFIX)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	@-rm -rf  $(EXES)
