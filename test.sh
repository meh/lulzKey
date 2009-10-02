#! /bin/sh
STAGE1=`stat -c %s test/stage1`
STAGE2=`stat -c %s test/stage2`
KERNEL=`stat -c %s lulzKey`

TMP=`mktemp`
FLOPPY=`mktemp`

dd if=/dev/zero of="$TMP" bs=1 count=750 &> /dev/null
cat test/stage1 test/stage2 "$TMP" lulzKey > "$FLOPPY"
dd if=/dev/zero of="$TMP" bs=1 count=$((1474560-$STAGE1-$STAGE2-$KERNEL-750)) &> /dev/null
cat "$TMP" >> "$FLOPPY"

echo "Now type:"
echo "kernel 200+$(stat -c %b lulzKey)"
echo "boot"
echo ""
echo "Enjoy."

qemu -fda "$FLOPPY" &> /dev/null

rm "$TMP"
rm "$FLOPPY"
