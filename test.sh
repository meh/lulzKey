#! /bin/sh
cat test/stage1 test/stage2 test/pad lulzKey > test/floppy.img
qemu -fda test/floppy.img
