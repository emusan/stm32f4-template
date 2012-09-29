include ../Makefile.common

OBJS+=startup_stm32f4xx.o
OBJS+=main.o

all: src

src: app.a

app.a: $(OBJS)
	$(AR) cr app.a $(OBJS)

.PHONY:src clean

clean:
	rm -f app.a $(OBJS)
