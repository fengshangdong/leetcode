CC= g++
LIB =
LIB_DIR =
LDFLAGS =
CFLAGS = -g

FILE_SUFFIX = cpp
SRCS := $(wildcard *.$(FILE_SUFFIX))
EXES := $(patsubst %.$(FILE_SUFFIX),%,$(SRCS))

all:$(EXES)

$(EXES): % : %.$(FILE_SUFFIX)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	@-rm -rf  $(EXES)
