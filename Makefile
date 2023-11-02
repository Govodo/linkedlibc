CC = gcc
CCFLAGS = -Wall -c -o

SRCDIR = src
BINDIR = bin
OUTDIR = target

OBJS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(wildcard $(SRCDIR)/*.c))

LIB = $(OUTDIR)/linkedlibc.a

LINKER = ar
LINKERFLAGS = rcs

DLL = $(OUTDIR)/linkedlibc.dll

DLLLINKER = gcc
DLLLINKERFLAGS = -shared -Wall -o $(DLL)

$(LIB): $(OUTDIR) $(BINDIR) $(OBJS)
	$(LINKER) $(LINKERFLAGS) $(LIB) $(OBJS)

$(DLL): $(OUTDIR) $(BINDIR) $(OBJS)
	$(DLLLINKER) $(DLLLINKERFLAGS) $(OBJS)

$(BINDIR):
	mkdir $(BINDIR)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $< $(CCFLAGS) $@

clean:
	rm -rf $(LIB)
	rm -rf $(DLL)
	rm -rf $(BINDIR)

all: $(LIB) $(DLL) headers

$(OUTDIR):
	mkdir $(OUTDIR)

headers: $(OUTDIR)
	cp $(wildcard $(SRCDIR)/include/*.h) $(OUTDIR)

.PHONY: all clean headers
.DEFAULT_GOAL = all
