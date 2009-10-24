#! /bin/bash

if [ ! -e lulzKey ]; then
    echo "The kernel is missing."
    exit;
fi

STAGE1=`stat -c %s test/stage1`
STAGE2=`stat -c %s test/stage2`
KERNEL=`stat -c %s lulzKey`

TMP=`mktemp`
FLOPPY=`mktemp`

dd if=/dev/zero of="$TMP" bs=1 count=750 &> /dev/null
cat test/stage1 test/stage2 "$TMP" lulzKey > "$FLOPPY"

dd if=/dev/zero of="$TMP" bs=1 count=1024 &> /dev/null
cat "$TMP" >> "$FLOPPY"

# Uncomment these if the emulator whines about it doesn't have enough space.
# dd if=/dev/zero of="$TMP" bs=1 count=$((1474560-$STAGE1-$STAGE2-$KERNEL-750-1024)) &> /dev/null
# cat "$TMP" >> "$FLOPPY"

echo "Now type:"
echo "kernel 200+$(stat -c %b lulzKey)"
echo "boot"
echo ""
echo "Enjoy."

if [ "$1" ]; then
    urxvt -e qemu -curses -d cpu_reset,int -cpu pentium3 -m 32M -fda "$FLOPPY"
else
    qemu -vga std -d cpu_reset,int -cpu pentium3 -m 32M -fda "$FLOPPY"
fi

rm "$TMP"
rm "$FLOPPY"
