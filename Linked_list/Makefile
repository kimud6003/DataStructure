CC = gcc
TARGET = test.out
OBJS = main.o func.o
CFLAGS = -Wall
LDFLAGS = -lc
all : $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
clean :
	rm -f $(OBJS) $(TARGET)

