# Info
This repository is for the test of lightweight cryptography (LWCs) on the Nucleo-L552ZE-Q Board.

---

### Supported Cryptography

1. AES
2. PRESENT
3. CLEFIA
4. LEA (WIP)
5. ENOCORO
6. TRIVIUM


---

### Usage

- Installation

    L552ZE_LWC requires `mbed-os` for build and flash.

    1. Install Mbed-CLI 2. Try `pip install mbed-tools` with your Python 3.
    2. Install [ARM Build Toolchain](https://developer.arm.com/downloads/-/gnu-rm) for building.
    3. Type `mbed-tools import https://github.com/KyeongMin5307/L552ZE_LWC` to clone this repository with Mbed-OS.

    For more information, see [Mbed CLI 2 documentation](https://os.mbed.com/docs/mbed-os/v6.16/build-tools/mbed-cli-2.html).

- Build

    1. Change `CRYPTO_TYPE` on `L552ZE_LWC/CMakeLists.txt` for selecting the LWC.

        ```cmake
        set(CRYPTO_TYPE false)
        ```
        The type `false` have no operation. See [the above list](https://github.com/KyeongMin5307/L552ZE_LWC#supported-cryptography) for selecting LWC.

    2. Type below command to build source code for Nucleo-L552ZE-Q board.

        ```bash
        mbed-tools compile -m NUCLEO_L552ZE_Q -t GCC_ARM -f
        ```

        Check your computer is connected with Nucleo-L552ZE-Q board using ST-LINK. Type `mbed-tools detect` for listing connected devices.
