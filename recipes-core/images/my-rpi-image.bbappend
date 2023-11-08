IMG_BASE = " \
    python3 \
    python3-numpy \ 
    wpa-supplicant \
    openssh \
    i2c-tools \
    bash \
    git \
    can-utils \
    libsocketcan \
    bcm2835-dev \
    common-api-c++ \
    common-api-c++-dev \
    common-api-c++-someip \
    common-api-c++-someip-dev \
    vsomeip \
    vsomeip-dev \
    fonts \
    automount \
    supervisor \
    python3-supervisor \
"

HU_PKGS = " \
    nano \
    racertest \
    qt-hu \
    ic-test \
    hu-test \
"

QT_BASE = " \
    qtbase \
    qtbase-dev \
    qtbase-mkspecs \
    qtbase-plugins \
    qtbase-tools \
"

QT_PKGS = " \
    qtwayland \
    qtwayland-dev \
    qtwayland-mkspecs \
    qtconnectivity-dev \
    qtconnectivity-mkspecs \
    qtquickcontrols \
    qtquickcontrols-qmlplugins \
    qtquickcontrols2 \
    qtquickcontrols2-dev \
    qtquickcontrols2-mkspecs \
    qtquickcontrols2-qmlplugins \
    qtdeclarative \
    qtdeclarative-dev \
    qtdeclarative-mkspecs \
    qtdeclarative-qmlplugins \
    qtgraphicaleffects \
    qtgraphicaleffects-dev \
    qtmultimedia \
    qtmultimedia-plugins \
    qtmultimedia-qmlplugins \
"

PIRACER = " \
    python3-adafruit-blinka \
    python3-adafruit-circuitpython-busdevice \
    python3-adafruit-circuitpython-pca9685 \
    python3-adafruit-circuitpython-register \
    python3-adafruit-platformdetect \
    python3-adafruit-pureio \
    python3-pyserial \
    python3-pyusb \
    rpi-gpio \
    python3-typing-extensions \
    python3-wheel \
    python-adafruit-circuitpython-framebuf \
    python-adafruit-circuitpython-ina219 \
    python-adafruit-circuitpython-requests \
    python-adafruit-circuitpython-ssd1306 \
    python-adafruit-circuitpython-typing \
    python-piracer-py \
    python-pyftdi \
" 

IMAGE_INSTALL += " \
    ${HU_PKGS} \
    ${IMG_BASE} \
    ${QT_BASE} \
    ${QT_PKGS} \
    ${PIRACER} \
"

