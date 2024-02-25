CC = gcc
TARGET = dns_reverse_app
OBJS = main.o dns_reverse.o
DEPS = dns_reverse.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o:  %.c $(DEPS)
	$(CC) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJS)
