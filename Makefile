TARGET	= libmatmult.so
LIBSRCS	= 
LIBOBJS	= Question1.o
OBJECT = main.o
WARN = -Wall
OPT	= -g -O3
PIC	= -fPIC
CFLAGS = $(OPT) $(WARN)


CC	= gcc
CFLAGS= $(OPT) $(PIC) $(XOPTS)

SOFLAGS = -shared -fPIC
XLIBS	= 


$(TARGET): $(LIBOBJS)
	$(CC) -o $@ $(SOFLAGS) $(LIBOBJS) $(XLIBS)


clean:
	@/bin/rm -f core core.* $(LIBOBJS)

Question1.o : Question1.c 
