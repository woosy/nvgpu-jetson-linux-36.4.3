# Jetson linux 36.4.3
[Jetson linux 공식 홈페이지](https://developer.nvidia.com/embedded/jetson-linux-r3643) 

[NVIDIA Jetson Linux Developer Guide](https://docs.nvidia.com/jetson/archives/r36.4.3/DeveloperGuide/)

- [kernel customization](https://docs.nvidia.com/jetson/archives/r36.4.3/DeveloperGuide/SD/Kernel/KernelCustomization.html) 

Driver Package (BSP) Sources(public_source.tbz2 ➡️ kernel_oot_module_src.tbz2) 

모듈로 변경 

## 코드 수정  

printk로 timeslice 확인하는 코드 추가 (drivers/gpu/nvgpu/common/fifo/tsg.c)

1. source 파일에서 module make 하기 (소스코드뿐만아니라 driver package 설치해야함)

       cd Linux_for_Tegra/source
       make modules
       sudo -E make modules_install
       sudo nv-update-initrd
       sudo reboot  
2. dmesg로 로그 확인
   
   <img width="848" alt="스크린샷 2025-04-07 오후 4 37 04" src="https://github.com/user-attachments/assets/46a29e11-4c15-4190-8af8-4fa8adf822da" />

       dmesg -w
