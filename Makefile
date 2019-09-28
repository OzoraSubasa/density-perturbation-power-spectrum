exec=cos_model

objs=main.o cosmology.o math.o

incl=allvars.h proto.h Makefile

CC=gcc

$(exec):$(objs)
	$(CC) $(objs) -o $(exec) -lm

$(objs):$(incl)

.PHONY:clean

clean:
	rm -f $(exec) $(objs)
