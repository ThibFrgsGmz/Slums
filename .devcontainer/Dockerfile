ARG VARIANT="22.04"
FROM ubuntu:${VARIANT} as dev

ARG DEBIAN_FRONTEND=noninteractive

# Install required packages as well as setup the prettier bash prompt and a
# Python virtual environment.
RUN apt-get update && apt-get install -y --no-install-recommends \
    openssh-server \
    curl \
    gnupg \
    git \
    build-essential \
    cmake \
    gdb-multiarch \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    clang-format \
    ffmpeg \
    libsm6 \
    libxext6 \
    libtool \
    pkg-config \
    libusb-1.0-0-dev \
    lm4flash \
    automake \
    default-jre \
    python3 \
    python3-setuptools \
    python3-pip \
    python3-venv \
    && rm -rf /var/lib/apt/lists/* \
    && python3 -m venv /tmp/fprime-venv \
    && . /tmp/fprime-venv/bin/activate \
    && python3 -m pip install --upgrade fprime-tools fprime-gds pyocd \
    && printf '\n[ -d "%s" ] && . %s/bin/activate\n' /tmp/fprime-venv /tmp/fprime-venv >> ~/.bashrc \
    && echo 'eval "$(register-python-argcomplete fprime-cli)"' >> ~/.bashrc

# install OpenOCD
WORKDIR /root
RUN git clone --depth 1 --j $(nproc) https://git.code.sf.net/p/openocd/code openocd-code \
&& cd openocd-code \
&& ./bootstrap \
&& ./configure --enable-ti-icdi \
&& make -j $(nproc) \
&& make install \
&& cd .. \
&& rm -rf openocd-code

# install sbt for fpp
RUN echo "deb https://repo.scala-sbt.org/scalasbt/debian all main" | tee /etc/apt/sources.list.d/sbt.list \
    && echo "deb https://repo.scala-sbt.org/scalasbt/debian /" | tee /etc/apt/sources.list.d/sbt_old.list \
    && curl -sL "https://keyserver.ubuntu.com/pks/lookup?op=get&search=0x2EE0EA64E40A89B84B2DF73499E82A75642AC823" | apt-key add \
    && apt-get update \
    && apt-get install sbt

# install fpp
WORKDIR /workspaces/fpp
RUN git clone https://github.com/fprime-community/fpp.git . \
    && git checkout v1.0.1 \
    && cd compiler \
    && ./install /usr/local/bin/fpp
ENV FPP_INSTALL_DIR=/usr/local/bin/fpp
ENV PATH=${PATH}:${FPP_INSTALL_DIR}

# if using GDB on the host instead of the container
EXPOSE 50000