CC=gcc
CFLAGS=-Wall -Wextra -O2
TARGET=STNM3K

all: $(TARGET)

$(TARGET): stnm3k.c
	$(CC) $(CFLAGS) -o $(TARGET) stnm3k.c

clean:
	rm -f $(TARGET)
