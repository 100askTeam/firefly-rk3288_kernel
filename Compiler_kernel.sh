#!/bin/bash
CPU=$(cat /proc/cpuinfo |grep 'processor' |wc -l)
export PATH=$PATH:../ToolChain/gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf/bin
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-

#step 1:clean kernel
#make distclean
#make clean 

#step 2:copy linux  config file 
make 100ask_firefly-rk3288_defconfig


#step 3:Compiler zImage 
make  zImage -j$CPU

#step 4:Compiler dtbs
make dtbs -j$CPU

#step 5:Compiler modules
make modules  -j$CPU

#step 6:Install kernel modules
#make modules_install INSTALL_MOD_PATH=<your rootfs patch>

echo -e "\033[32m zImage and rk3288-firefly.dtb directory \033[0m"

ls arch/arm/boot/zImage -la
ls arch/arm/boot/dts/rk3288-firefly.dtb -la

echo -e "\033[32m ------------------------------------- \033[0m"
