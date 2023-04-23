CONFIG_MODULE_SIG=n

FNAME_c := fp_printk

PWD := $(shell pwd)
obj-m += ${FNAME_c}.o
EXTRA_CFLAGS += -DDEBUG
KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	@echo
	@echo '--- Building : KDIR=${KDIR} EXTRA_CFLAGS=${EXTRA_CFLAGS} ---'
	@echo
	make -C $(KDIR) M=$(PWD) modules
install:
	@echo
	@echo "--- installing ---"
	@echo " [First, invoke the 'make' ]"
	make
	@echo
	@echo " [Now for the 'sudo make install' ]"
	sudo make -C $(KDIR) M=$(PWD) modules_install
	sudo depmod

clean:
	@echo
	@echo "--- cleaning ---"
	@echo
	make -C $(KDIR) M=$(PWD) clean
	rm -f *~   # from 'indent'

INDENT := indent
code-style:
	make indent

indent:
	@echo
	@echo "--- applying kernel code style indentation with indent ---"
	@echo
	mkdir bkp 2> /dev/null; cp -f *.[chsS] bkp/
	${INDENT} -linux --line-length95 *.[chsS]
sa:
	make sa_sparse
	make sa_gcc
	make sa_flawfinder
	make sa_cppcheck