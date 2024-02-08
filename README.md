| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |

# _Larissa_

_Larissa_ is a small IoT project, with the end goal of handling various sensors and updating a client using a Mqtt broker (_Hermes_ WIP), using various ESP-32 controllers as brains. 

## How to use _Larissa_
First, ensure that you have ESPRESSIF toolchains setup

### Setting up ESP-IDF Toolchain

To keep the build sizes and compilation times to a minimum, the use of the ESPRESSIF-ID extension is desired to keep to a minimum, so the toolchain and the ESP-IDF default build processes are encoraged to use.
First, verify that you have some pre-requisites installed in your system

```
sudo pacman -S --needed gcc git make flex bison gperf python cmake ninja ccache dfu-util libusb
```
After that, download the standard toolchain ESP-IDF from their repo

```
git clone --recursive https://github.com/espressif/esp-idf.git
```
Note: Pleas ensure that it is in an accesible directory, where common permissions can be assigned.
Now, run the ESP-IDF install script, which will install the needed tools required for each model. Navigate inside the folder where the toolchain was isntalled and run

```
./install.sh CHIP_MODEL_TARGETED
```
By default, _CHIP_MODEL_TARGETED_ will be replaced wit _esp32_, but since _Larissa_ can be used across multiple chipsets, you might need to swap or install multiple models, separated by a comma. Ex:

```
./install.sh esp32,esp32s2,esp32s3
```
Running the script will install the required compilation tools inside the home directory, ex., <$HOME/.espressif>. If you wish to install the tools into a different directory, export the environment variable IDF_TOOLS_PATH before running the installation scripts. Make sure that your user account has sufficient permissions to read and write this path.

```
export IDF_TOOLS_PATH="$HOME/required_idf_tools_path"
./install.sh

. ./export.sh
```
Now with the tools installed,  the next thing to do is to add them to our PATH variables, so we can use them from our cli. So, we will add the following alias to our `.bashrc` file

```
alias get_idf='. $HOME/esp/esp-idf/export.sh'
```
With that done, now we can run `get_idf` in every terminal we want to have an IDF virtual environment, to make use of the ESP-IDF tools.  

### Building _Larissa_ 

In order to compile and flash a ESP-32 device with _Larissa_, you will need to have a terminal with an IDF virtual enviroment, and the latest code. But first.

Download the code, open a terminal and run
```
idf.py set-target CHIP_MODEL_TARGETED
Ex:
idf.py set-target esp32
```
Doing so, will clean the configuration files to make a build for the desired ESP-32 chip target. Next, we will need to set additional SDK configurations (Ex, Led GPIOs, which are different across ESP-32 modules)

```
idf.py menuconfig
```

Please note that changing any of the variables here will affect the build times, compilation times, flashing times, bootloader, etc., so any side effects while playing with it are at least expected and still unexplored. 

Now, we can build _Larissa_


```
idf.py build
```

### Flashing _Larissa_ onto a ESP-32 Device
You will need to have a ESP-32 Device booted on flash mode, and connected to a USB port. 

Once you got that, run
```
idf.py -p PORT flash
```
You will need to replace PORT to the serial name of the USB port where the ESP-32 device is connected.
If the flashing succedded, congratulations, your ESP-32 device now runs _Larissa_. 


## Project Structure

## WIP

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.
