# Airwindows

Build instructions for headless plugin build for [Elk Audio OS](https://elk.audio)

## Building Instructions

1. Initialize submodules:
```bash
$ git submodule update --init
```

2. Source the cross-compilation SDK for the target platform:

```bash
$ source [path-to-extracted-sdk]/environment-setup-[aarch-name]-elk-linux
```

3. Run Linux's CMake configuration:

```bash
$ cd plugins/LinuxVST
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Release -DVSTSDK_ROOT= [path-to-vst2.4-sdk] ..
# Optional: set flags for STM32MP1
$ export CXXFLAGS="-O3 -mcpu=cortex-a7 -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -mvectorize-with-neon-quad -ffast-math -fno-finite-math-only -fprefetch-loop-arrays -funroll-loops -funsafe-loop-optimizations"
$ cmake --build . --config Release
$ $STRIP *.so
```

