# Enable I2C
ENABLE_I2C = "1"
KERNEL_MODULE_AUTOLOAD:rpi += "i2c-dev i2c-bcm2708"

# Enable CAN
ENABLE_SPI_BUS = "1"
ENABLE_CAN = "1"
CAN_OSCILLATOR = "16000000"

# Install dtbo for 7.9inch LCD
RPI_EXTRA_CONFIG = " \n\
dtoverlay=spil-3cs \n\
dtoverlay=mcp251xfd,spi0-0,interrupt=25 \n\
dtoverlay=mcp251xfd,spi1-0,interrupt=24 \n\
\n\
dtoverlay=vc4-kms-dsi-waveshare-panel,7_9_inch \n\
\n\
hdmi_force_hotplug=1 \n\
confg_hdmi_boost=10 \n\
hdmi_group=2 \n\
hdmi_mode=87 \n\
hdmi_cvt 1024 1280 60 6 0 0 0 \n\
"

