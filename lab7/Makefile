CC_PTHREAD_FLAGS = -lpthread
CC_FLAGS         = -c
CC_OUTPUT_FLAGS  = -o
CC_DEBUG_FLAGS   = -g
CC               = gcc
TARGET           = test
OBJS             = linktable.o menu.o test.o
RM               = rm
RM_FLAGS         = -f
all:    $(OBJS)
	$(CC)    $(CC_OUTPUT_FLAGS)    $(TARGET)    $(OBJS)
.c.o:
	$(CC)    $(CC_FLAGS)    $<
clean:
	$(RM)    $(RM_FLAGS)    $(OBJS)    $(TARGET)    *.bak
