# Enable I2C
ENABLE_I2C = "1"

# Enable SPI bus
ENABLE_SPI_BUS = "1"

# Remove Splash
DISABLE_SPLASH = "1"


do_deploy:append() {
    echo "# Enable CAN" >> $CONFIG
    echo "dtoverlay=spil-3cs" >> $CONFIG
    echo "dtoverlay=mcp251xfd,spi0-0,interrupt=25" >> $CONFIG
    echo "dtoverlay=mcp251xfd,spi1-0,interrupt=24" >> $CONFIG

    echo "# Install dtbo for 7.9inch LCD" >> $CONFIG
    echo "dtoverlay=vc4-kms-dsi-waveshare-panel,7_9_inch" >> $CONFIG

    echo "# Setting for 7inch HDMI LCD" >> $CONFIG
    echo "hdmi_force_hotplug=1">> $CONFIG
    echo "confg_hdmi_boost=10" >> $CONFIG
    echo "hdmi_group=2" >> $CONFIG
    echo "hdmi_mode=87" >> $CONFIG
    echo "hdmi_cvt 1024 1280 60 6 0 0 0" >> $CONFIG

    echo "# Enable Audio" >> $CONFIG
    echo "dtparam=audio=on" >> $CONFIG
    echo "dtoverlay=vc4-kms-v3d,noaudio" >> $CONFIG
}
