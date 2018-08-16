CC=gcc
CFLAGS="-Wall"

#srcdir	 =src/
TARGETS	 = 0

.PHONY: all
all: $(TARGETS)

0: $(srcdir)0.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)

.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true
