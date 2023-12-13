# meta-ipi

In-Piracer-Infotainment Layer for OpenEmbedded/Yocto

Through this layer, by following Quick Start below, you can obtain infotainment for Piracer!

Detailed information regarding hardware setup and applications can be found [here](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication)

# Dependencies

This layer depends on:

- URI: https://github.com/yoctoproject/poky
    - branch : kirkstone
    - commit : 5c556073ac6e54314aa3fc210db040f3ab55105a
- URI: [git://git.openembedded.org/meta-openembedded](https://git.openembedded.org/meta-openembedded//)
    - branch : kirkstone
    - commit : 8a75c61cce2aa1d6e5a3597ab8fc5a7ee6aeae1e4
- URI: [https://github.com/agherzan/meta-raspberrypi](https://github.com/agherzan/meta-raspberrypi.git)
    - branch : master
    - commit : fde68b24f08b0eac4ad4bfd3c461dc17fe3a263c
- URI: [https://github.com/meta-qt5/meta-qt5](https://github.com/meta-qt5/meta-qt5.git)
    - branch : kirkstone
    - commit : ae8a97f79364bed1abc297636f7933d0e35f22be

# Architecture
![yocto_layer_architecture](https://github.com/SEA-ME-Team6/meta-ipi/assets/106136905/ceda9706-da56-4a2f-afbc-e59ed040560e)


# **Descriptions of Recipe Directories**

- **recipes-core**
    - recipe for our custom image(my-rpi-image)
- **recipes-kernel & recipes-connectivity**
    - recipes for changing linux kernel version
- **recipes-setting**
    - recipes for environment setting(rpi-config, wifi, qt5, etc.)
- **recipes-ipc**
    - recipes for IPC(SOME/IP)
- **recipes-piracer**
    - recipes for piRacer-py
- **recipes-app**
    - recipe for Infortainment we’ve made.

# Quick Start

### Install packages for Yocto

```
sudo apt-get update
sudo apt-get upgrade -y
```

```
sudo apt install -y bmap-tools zstd liblz4-tool gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm python
sudo apt install -y curl
```

### Install the [repo](https://source.android.com/docs/setup/download/downloading?hl=ko#installing-repo) command by Google

```jsx
mkdir -p ~/bin
curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
chmod a+x ~/bin/repo
export PATH=~/bin:$PATH
```

## Create workspace

```jsx
mkdir yocto-ipi && cd yocto-ipi
repo init -u https://github.com/SEA-ME-Team6/meta-ipi -m tools/manifests/ipi-yocto.xml
repo sync
repo start work --all
```

### **Setup Build Environment**

```jsx
cd poky
. ./meta-ipi/setup.sh
```

### Build Image

```python
bitbake my-rpi-image
```

This process takes quit long time..😪

### Flash Image to SD Card

1. Locating target SD Card for Writing Image

```python
sudo fdisk -l
```

2. Flash image to SD Card

```python
cd tmp/deploy/images/raspberrypi4-64

ls -l | grep rpi-sdimg # Find the most recently built image

sudo dd if=meta-rpi-image-raspberrypi-64-[BuildTime].rootfs.rpi-sdimg of=/dev/sda # Flash built image to target SD card
sync
```

3. Remove the SD card and insert it into the Raspberry Pi
    
    If you’ve set up HW properly, you should be able to check our infotainment system! 🎮


