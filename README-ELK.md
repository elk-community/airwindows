# Airwindows

Modified for headless plugin build for [Elk Audio OS](https://elk.audio)

## Building Instructions

1. Set up the cross-compilation toolchain with:  

   ```bash
   $ unset LD_LIBRARY_PATH
   $ source /path/to/environment-setup-cortexa7t2hf-neon-vfpv4-elk-linux-gnueabi
   ```

2. (optional) Add flags for more aggressive optimizations than the default ones from the toolchain with:  

   ```bash
   $ export CXXFLAGS="-O3 -pipe -ffast-math -feliminate-unused-debug-types -funroll-loops -mvectorize-with-neon-quad"
   ```

3. Set up the makefile:
    ```bash
    $ cd plugins/LinuxVST
    $ rm -rf build
    $ mkdir build && cd build
    $ cmake .. && ccmake ..
    ```
    set the flag `COMPILE_FOR_ELK_PI` to `ON`.

4. Finally cross compile the plugins using:  

   ```bash
   $ make
   ```

## Additional notes

* Make sure that you update the submodules before trying to build.
* For further compilation help. Look at our [documentation](https://github.com/elk-audio/elk-docs/blob/master/documents/building_plugins_for_elk.md).