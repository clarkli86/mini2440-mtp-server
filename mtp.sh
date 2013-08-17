modprobe s3c2410_udc
modprobe g_android
echo mtp > /sys/class/android_usb/android0/functions
echo 1 > /sys/class/android_usb/android0/enable
