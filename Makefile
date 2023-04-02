CC = gcc
TARGET = stk_main.out
SRCS = stk_main.c
CFLAGS = -framework AudioToolbox -framework CoreFoundation


$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)
