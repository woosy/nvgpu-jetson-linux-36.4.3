# Jetson linux 36.4.3
[Jetson linux 공식 홈페이지](https://developer.nvidia.com/embedded/jetson-linux-r3643) 

[NVIDIA Jetson Linux Developer Guide](https://docs.nvidia.com/jetson/archives/r36.4.3/DeveloperGuide/)

- kernel customization

Driver Package (BSP) Sources(public_source.tbz2 ➡️ kernel_oot_module_src.tbz2) 

모듈로 변경 

## 코드 수정  

printk로 timeslice 확인하는 코드 추가 (tsg.c)

  - dmesg -w로 로그 확인
