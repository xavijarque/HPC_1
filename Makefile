TARGET	= libmatmult.so
LIBSRCS	= 
LIBOBJS	= Question1.c
OBJECT = main.o
WARN = -Wall
OPT	= -g 
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

main.o : main.c 
