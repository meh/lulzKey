#! /bin/sh
STAGE1=`stat -c %s test/stage1`
STAGE2=`stat -c %s test/stage2`
KERNEL=`stat -c %s lulzKey`

TMP=`mktemp`

dd if=/dev/zero of="$TMP" bs=1 count=750 &> /dev/null
cat test/stage1 test/stage2 "$TMP" lulzKey > test/floppy.img
dd if=/dev/zero of="$TMP" bs=1 count=$((1474560-$STAGE1-$STAGE2-$KERNEL-750)) &> /dev/null
cat "$TMP" >> test/floppy.img
rm "$TMP"

echo "Now type:"
echo "kernel 200+$(stat -c %b lulzKey)"
echo "boot"
echo ""
echo "Enjoy."

qemu -fda test/floppy.img
